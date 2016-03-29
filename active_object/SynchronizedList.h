#include <list>
#include <mutex>
#include <condition_variable>

using namespace std;

template<typename T>
class synchronized_list{

	mutex m;

	condition_variable cv;

	list<T> _list;

	size_t high, low;

	bool flag;

public:

	synchronized_list();

	synchronized_list(size_t h, size_t l);

	void push_back(T item);

	void push_front(T item);

	T pop_back();

	T pop_front();

	size_t size();

	void shut_down();

	void restart();

};




template<typename T>

synchronized_list<T>::synchronized_list() : high(0), low(0), flag(false) {}




template<typename T>

synchronized_list<T>::synchronized_list(size_t h, size_t l) : high(h), low(l), flag(false) {}




template<typename T>

void synchronized_list<T>::push_back(T item){

	unique_lock<mutex> u(m);

	cv.wait(u, [this] { return high == 0 || _list.size() < high || flag; });

	if (flag) return;

	_list.push_back(item);

	cv.notify_all();

}




template<typename T>

void synchronized_list<T>::push_front(T item){

	unique_lock<mutex> u(m);

	cv.wait(u, [this] { return high == 0 || _list.size() < high || flag; });

	if (flag) return;

	_list.push_front(item);

	cv.notify_all();

}




template<typename T>

T synchronized_list<T>::pop_back(){

	unique_lock<mutex> u(m);

	cv.wait(u, [this] { return _list.size() > low || flag; });

	if (flag) return T();

	T retVal = _list.back();

	_list.pop_back();

	cv.notify_all();

	return retVal;

}




template<typename T>

T synchronized_list<T>::pop_front(){

	unique_lock<mutex> u(m);

	cv.wait(u, [this] { return _list.size() > low || flag; });

	if (flag) return T();

	T retVal = _list.front();

	_list.pop_front();

	cv.notify_all();

	return retVal;

}

template<typename T>
size_t synchronized_list<T>::size()
{
	lock_guard<mutex> guard(m);
	return _list.size();
}

template<typename T>
void synchronized_list<T>::shut_down()
{
	lock_guard<mutex> guard(m);
	flag = true;
	cv.notify_all();
}

template<typename T>
void synchronized_list<T>::restart()
{
	flag = false;
}
