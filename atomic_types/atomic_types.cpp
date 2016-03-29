#include <atomic>
#include <thread>
#include <assert.h>
#include <iostream>

std::atomic<bool> x,y;
std::atomic<int> z;

void write_x_then_y()
{
  x.store(true,std::memory_order_release);
  y.store(true,std::memory_order_release);
}

void read_y_then_x()
{
  while(!y.load(std::memory_order_acquire));
  if(x.load(std::memory_order_acquire))
    ++z;
}

int main(int argc, char* argv[])
{
  int num = 1;
  if (argc == 2) {
    num = atoi(argv[1]);
  }
  z=0;
  for (int i = 0; i < num; ++i) {
    x=false;
    y=false;
    std::thread a(write_x_then_y);
    std::thread b(read_y_then_x);
    a.join();
    b.join();
    std::cout << z << std::endl;
  }
}
