#include "simple_thread_safe_queue.h"
#include <vector>
#include <functional>
#include <thread>
#include <atomic>
#include <thread>

class thread_pool
{
    std::atomic_bool done;
    thread_safe_queue<std::function<void()> > work_queue;
    std::vector<std::thread> threads;

    void worker_thread()
    {
        while(!done)
        {
            std::function<void()> task;
            if(work_queue.try_pop(task))
            {
                task();
            }
            else
            {
                std::this_thread::yield();
            }
        }
    }
public:
    thread_pool():
        done(false)
    {
        unsigned const thread_count=std::thread::hardware_concurrency() == 0?2:std::thread::hardware_concurrency();
        try
        {
            for(unsigned i=0;i<thread_count;++i)
            {
                threads.push_back(
                    std::thread(&thread_pool::worker_thread,this));
            }
        }
        catch(...)
        {
            done=true;
            throw;
        }
    }

    ~thread_pool()
    {
        done=true;
        for (auto& t: threads) t.join();
    }

    template<typename FunctionType>
    void submit(FunctionType f)
    {
        work_queue.push(std::function<void()>(f));
    }
};
