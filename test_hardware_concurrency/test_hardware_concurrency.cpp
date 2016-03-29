#include <iostream>
#include <thread>

using namespace std;


int main(int argc, char* argv[])
{
  cout <<"thread::hardware_concurrency() = "<< thread::hardware_concurrency() << endl;
 
  return 0;
}
