// Studio9-18.cpp : Defines the entry point for the console application.
//

#include "ActiveObject.h"
#include <chrono>


int main(int argc, char* argv[])
{
	ActiveObject<int> o1;
	ActiveObject<int> o2(&o1);

	std::cout << "o2 is active and starts enqueue element..." << std::endl;
	o2.activate();
	o2.enqueue(1);
	o2.enqueue(2);
	o2.enqueue(3);
	o2.enqueue(4);
	std::this_thread::sleep_for(std::chrono::seconds(3));
	
	std::cout << "o1 is active and pop:" << std::endl;
	o1.activate();
	std::this_thread::sleep_for(std::chrono::seconds(3));

	return 0;
}

