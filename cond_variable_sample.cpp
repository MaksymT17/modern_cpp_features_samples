#include<iostream>
#include<thread>
#include<mutex>
#include <chrono>
#include <condition_variable>
//compile: g++ cond_variable_sample.cpp -std=c++14 -lpthread

std::condition_variable cv;
std::mutex m;

long balance {0};

void addValue(const int value){
    std::lock_guard<std::mutex> lg(m);
    balance+=value;
    std::cout << "Value added, current value is: " << value <<std::endl;
    cv.notify_one();
}

void reduceValue(int value){
    std::unique_lock<std::mutex> ul(m);
    cv.wait(ul, []{return balance!=0 ? true:false;});

    if(balance-=value){
        std::cout << "Amount reduced: " << value << std::endl;
    }
    else{
        std::cout << "Amount can't be reduced, balance less than: " << value << std::endl;
    }
    std::cout << "balance now: " << balance << std::endl;
}

int main(){
    //reduce value can be done only if there is balance > 0
    std::thread t1(reduceValue, 5);

    // do not use sleep() functions in production code
    // just for demo, to show that some time-consuming code could be here
    std::this_thread::sleep_for(std::chrono::milliseconds(200));

    std::thread t2(addValue, 10);
    
    t1.join();
    t2.join();

    return 0;
}