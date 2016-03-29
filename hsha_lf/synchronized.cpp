#include "synchronized.h"

sync_wrapper::sync_wrapper(ostream& s): stream(s) {}

void sync_wrapper::print(const string& str){
    lock_guard<mutex> guard(mut);
    stream << str;
}
