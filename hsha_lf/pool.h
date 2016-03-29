#ifndef POOL_H
#define POOL_H

#include "synchronized.h"
#include <queue>
#include <functional>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>


using namespace std;
class pool
{
    sync_wrapper wrapper;
    condition_variable cv;
    mutex mut;
    queue<int> work_queue;
    vector<thread> my_pool;
    bool done;

public:
    pool(int t);
    void add_task(int num);
    bool isprime(int num);
    void calcPrime(int num);

    ~pool(void);
};

#endif

