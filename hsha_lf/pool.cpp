#include "pool.h"
#include <sstream>
#include <cmath>

bool pool::isprime(int num){
    for(int i = 2; i < sqrt(num); ++i){
        if(num % i == 0)
    return false;
}
    return true;
}

void pool::calcPrime(int num){
    bool prime = isprime(num);

    stringstream stream;
    stream  << num << ": " << boolalpha << prime << "\n";
    wrapper.print(stream.str());
}

pool::pool(int t) : wrapper(cout),done(false)
{
    for(int i = 0; i < t; ++i){
        this->my_pool.push_back(thread([this]{
            while(true) {
                unique_lock<mutex> lock(this->mut);
                this->cv.wait(lock, [this]{return !this->work_queue.empty() || done;});
                if(done) return;
                cout << "Leader thread is now: " << this_thread::get_id() << endl;

                int num = 0;
                while(true){
                    if(this->work_queue.empty()){
                        break;
                    }

                    num = this->work_queue.front();
                    this->work_queue.pop();

                    if(num % 2 == 0 || num == 1){
                        calcPrime(num);
                    } else {
                        break;
                    }

                }
                lock.unlock();
                calcPrime(num);
            }
        }));
    }
}


pool::~pool(void)
{
    this->done = true;
    this->cv.notify_all();
    for(thread& t : this->my_pool){
        t.join();
    }
}

void pool::add_task(int num){
    lock_guard<mutex> lock(this->mut);
    this->work_queue.push(num);
    this->cv.notify_all();
}
