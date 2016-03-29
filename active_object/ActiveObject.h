#include "SynchronizedList.h"
#include <iostream>
#include <thread>

using namespace std;

template<typename T>
class ActiveObject
{
private:
	synchronized_list<T> list;
	bool flag;
	ActiveObject *other;

	void runService()
	{
		if (other == nullptr)
		{
			while (flag)
			{
				cout << list.pop_back() << endl;
			}
		}
		else
		{
			while (flag)
			{
				other->enqueue(list.pop_back());
			}
		}
	}

public:
	ActiveObject(ActiveObject *other_ = nullptr) : flag(false), other(other_)
	{
	}

	void enqueue(T element)
	{
		list.push_front(element);
	}

	void activate()
	{
		if (!flag)
		{
			flag = true;
			list.restart();
			thread t(&ActiveObject<T>::runService, this);
			t.detach();
		}
	}

	void deactivate()
	{
		if (flag)
		{
			flag = false;
			list.shut_down();
		}
	}
};
