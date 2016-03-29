// Studio9-9.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <algorithm>
#include <iterator>
#include <thread>

using namespace std;

template<typename ITER, typename T>
void sum(ITER start, ITER end, ITER result)
{
	T sum = 0;
	for (;start != end; start += 1)
	{
		sum += *start;
	}

	*result = sum;
}

int main(int argc, char* argv[])
{
	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25 };
	int b[5];

	thread t1(sum<int *, int>, a, a + 5, b);
	thread t2(sum<int *, int>, a + 5, a + 10, b + 1);
	thread t3(sum<int *, int>, a + 10, a + 15, b + 2);
	thread t4(sum<int *, int>, a + 15, a + 20, b + 3);
	thread t5(sum<int *, int>, a + 20, a + 25, b + 4);

	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();

	ostream_iterator<int> out_it(cout," ");
	copy(b, b + 5, out_it );

	return 0;
}

