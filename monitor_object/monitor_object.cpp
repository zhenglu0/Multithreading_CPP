#include "monitor_object.h"
#include <iostream>
#include <thread>

using namespace std;

int main(int argc, char* argv[])
{
  synchronized_list<int> sList;

  thread t1([&]{ sList.push_back(1); });
  thread t2([&]{ sList.push_back(2); });
  thread t3([&]{ sList.push_back(3); });
  thread t4([&]{ sList.push_back(4); });


  thread t5([&]{ cout << sList.pop_back() << " "; });
  thread t6([&]{ cout << sList.pop_back() << " "; });
  thread t7([&]{ cout << sList.pop_back() << " "; });
  thread t8([&]{ cout << sList.pop_back() << " "; });

  t1.join();
  t2.join();
  t3.join();
  t4.join();

  t5.join();
  t6.join();
  t7.join();
  t8.join();

  cout << endl;

  return 0;
}


