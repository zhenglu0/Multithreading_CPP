#include "test.h"

template <typename T>
void Test<T>:: operator << (T t)
{
    std:: cout << t;
    std:: cout << std::endl;
}
