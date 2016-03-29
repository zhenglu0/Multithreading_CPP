#include "lock_free.h"
#include <iostream>
#include <thread>

using namespace std;

int main(int argc, char* argv[])
{
  thread t3([]{
      lock_free_stack<int> stack;
 
      thread t1([&stack]{
	  for(int i = 1; i < 20; i += 2){
	    cout << "Push: " << i << endl;
	    stack.push(i);
	  }
	  for(int i = 1; i < 20; i += 2){
	    cout << "Pop: " << *stack.pop() << endl;
	  }
      });

      thread t2([&stack]{
	  for(int i = 0; i < 20; i += 2){
	    cout << "Push: " << i << endl;
	    stack.push(i);
	  }
	  for(int i = 0; i < 20; i += 2){
	    cout << "Pop: " << *stack.pop() << endl;
	  }
      });

      t1.join();
      t2.join();
  });
  
  t3.join();
  return 0;
}
