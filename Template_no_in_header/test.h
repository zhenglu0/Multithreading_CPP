#ifndef TEST_H
#define TEST_H

#include <iostream>

template <typename T>
class Test
{
public:
  void operator << (T t); 
};

#endif


