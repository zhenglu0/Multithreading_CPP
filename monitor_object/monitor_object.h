
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
 public:
  synchronized_list();
  synchronized_list(size_t h, size_t l);
  void push_back(T item);
  void push_front(T item);
  T pop_back();
  T pop_front();
};

template<typename T>
synchronized_list<T>::synchronized_list() : high(0), low(0){}

template<typename T>
synchronized_list<T>::synchronized_list(size_t h, size_t l) : high(h), low(l){}

template<typename T>
void synchronized_list<T>::push_back(T item){
  unique_lock<mutex> u(m);
  cv.wait(u, [this] { return high == 0 || _list.size() < high; });
  _list.push_back(item);
  cv.notify_all();
}

template<typename T>
void synchronized_list<T>::push_front(T item){
  unique_lock<mutex> u(m);
  cv.wait(u, [] { return high == 0 || _list.size() < high; });
  _list.push_front(item);
  cv.notify_all();
}

template<typename T>
T synchronized_list<T>::pop_back(){
  unique_lock<mutex> u(m);
  cv.wait(u, [] { return low == 0 || _list.size() > low; });
  T retVal = _list.back();
  _list.pop_back();
  //cout << retVal << endl;
  cv.notify_all();
  return retVal;
}

template<typename T>
T synchronized_list<T>::pop_front(){
  unique_lock<mutex> u(m);
  cv.wait(u, [this] { return low == 0 || _list.size() > low; });
  T retVal = _list.front();
  _list.pop_front();
  // cout << retVal << endl;
  cv.notify_all();
  return retVal;
}
