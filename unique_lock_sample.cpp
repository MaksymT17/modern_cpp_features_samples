#include<iostream>
#include<thread>
#include<mutex>
#include <chrono>
//compile: g++ unique_lock_sample.cpp -std=c++14 -lpthread

std::mutex m1, m2;
int buffer;

void task_thread_safe(const char* thrName, const int loopCounter){
    std::unique_lock<std::mutex> lock(m1, std::defer_lock);
    std::cout <<thrName<<" before lock"<<std::endl;

    // do not use sleep() functions in production code
    // just for demo, to show that some time-consuming code could be here
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    
    lock.lock();
    for(int i=0; i<loopCounter; ++i){
        buffer++;
        std::cout << thrName << buffer << std::endl;
    }
    // lock - unlocks automatically on destroy
}

int main(){
    // unique_lock example
    std::thread t1(task_thread_safe, "Thread_1 ", 10);
    std::thread t2(task_thread_safe, "Thread_2 ", 10);
    t1.join();
    t2.join();


    return 0;
}