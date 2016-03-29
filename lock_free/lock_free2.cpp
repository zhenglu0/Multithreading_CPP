#include "lock_free.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
  lock_free_stack<int> stack;

  cout << "Push: " << 1 << endl;
  stack.push(1);
  cout << "Push: " << 2 << endl;
  stack.push(2);
  cout << "Pop: " << *(stack.pop()) << endl;
  cout << "Push: " << 3 << endl;
  stack.push(3);
  cout << "Pop: " << *(stack.pop()) << endl;
  cout << "Pop: " << *(stack.pop()) << endl;

  return 0;
}
