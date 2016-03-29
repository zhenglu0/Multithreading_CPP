#include <iostream>
#include <sstream>
#include <chrono>
#include <cmath>
#include "pool.h"
#include "synchronized.h"

using namespace std;
using namespace chrono;

int main(int argc, char* argv[])
{
    pool p(5);
    sync_wrapper printer(cout);

    p.add_task(77);
    p.add_task(31);
    p.add_task(15);
    p.add_task(475);
    p.add_task(7657243);
    p.add_task(263);
    p.add_task(6047);
    p.add_task(15485863);
    p.add_task(234594);
    p.add_task(1234);
    p.add_task(7656576);
    p.add_task(2342);
    p.add_task(643452);

    this_thread::sleep_for(seconds(1));

    return 0;
}
