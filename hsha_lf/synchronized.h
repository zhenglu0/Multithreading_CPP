#ifndef SYNCRONIZED_H
#define SYNCRONIZED_H

#include <iostream>
#include <mutex>
#include <string>

using namespace std;

class sync_wrapper{
    ostream& stream;
    mutex mut;
public:
    sync_wrapper(ostream& s);
    void print(const string& str);
};

#endif
