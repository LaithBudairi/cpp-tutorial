//
// Created by LaithB on 12/6/2020.
//

#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>
#include <vector>
#include <time.h>
#include <mutex>
#include <condition_variable>

static int amount = 0;
static int counter = 0;
typedef unsigned long long ull;
std::mutex m;
std::mutex mtx;
int X=0, Y=0;
std::mutex m1, m2;

int myAmount = 0;
std::timed_mutex mt;

std::condition_variable cv;
std::mutex mcv;
long balance = 0;

void addMoney(int money) {
    std::lock_guard<std::mutex> lock(mcv);
    balance += money;
    std::cout << "Amount Added Current Balance: " << balance << '\n';
    cv.notify_one();
}

void withdrawMoney(int money) {
    std::unique_lock<std::mutex> lock(mcv);
    cv.wait(lock, [] {
        return (balance != 0)? true : false;
    });

    if(balance >= money) {
        balance -= money;
        std::cout << "Amount Deducted: " << balance << '\n';
    }
    else {
        std::cout << "Amount Cannot Be Deducted, Current Balance is Less Than " << money << '\n';
    }
    std::cout << "Current Balance Is: " << balance << '\n';
}



void increment2(int i) {
    if(mt.try_lock_for(std::chrono::seconds(2))){
        ++myAmount;
        std::this_thread::sleep_for (std::chrono::seconds(1));
        std::cout << "Thread " << i << " Entered" << '\n';
        m.unlock();
    }else{
        std::cout << "Thread " << i << " Couldn't Enter" << '\n';
    }
}

void doSomeWorkForSeconds(int seconds) { std::this_thread::sleep_for(std::chrono::seconds(seconds)); }

void incrementXY(int& XorY, std::mutex& m, const char* desc) {
    for(int i=0; i<5; ++i){
        m.lock();
        ++XorY;
        std::cout << desc << XorY << '\n';
        m.unlock();
        doSomeWorkForSeconds(1);
    }
}

void consumeXY () {
    int useCount = 5;
    int XplusY = 0;
    while(1){
        int lockResult = std::try_lock(m1,m2);
        if(lockResult == -1){
            if(X!=0 && Y!=0){
                --useCount;
                XplusY+=X+Y;
                X = 0;
                Y = 0;
                std::cout << "XplusY " << XplusY << '\n';
            }
            m1.unlock();
            m2.unlock();
            if(useCount == 0) break;
        }
    }
}

void increaseCounterForThe100000Time() {
    for(int i = 0; i < 100000; i++) {
        if(mtx.try_lock()) {
            counter++;
            mtx.unlock();
        }
    }
}

void increment() {
    m.lock();
    amount++;
    m.unlock();
}

ull findOdd(ull start, ull end) {
    ull sum = 0;

    for(int i = start; i <= end; i++) {
        if(i & 1 == 1) {
            sum += i;
        }
    }

    return sum;
}

ull findEven(ull start, ull end) {
    ull sum = 0;

    for(int i = start; i <= end; i++) {
        if(i & 1 != 1) {
            sum += i;
        }
    }

    return sum;
}

class Base {
public:
    void run(int x) {
        while(x-- > 0) {
            std::cout << x << '\n';
        }
    }

    static void go(int x) {
        while(x-- > 0) {
            std::cout << x << '\n';
        }
    }
};


void threading() {
    ull start = 0, end = 1900000000;


    auto startTime = std::chrono::high_resolution_clock::now();

    // Function Pointer
    std::thread t1(findEven, start, end);
    std::thread t2(findOdd, start, end);

    t1.join();
    t2.join();

    auto stopTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(stopTime - startTime);

    std::cout << "Duration: " << duration.count() << '\n';


    // Non-static member function
    Base b;
    std::thread t3(&Base::run, &b, 10);

    t3.join();

    // Static member function
    std::thread t4(&Base::go, 10);
    if(t4.joinable()) {
        t4.join();
    }

    // Mutex
    std::thread t5(increment);
    std::thread t6(increment);

    t5.join();
    t6.join();

    std::cout << "amount: " << amount << '\n';

    // mutex::try-lock
    std::thread t7(increaseCounterForThe100000Time);
    std::thread t8(increaseCounterForThe100000Time);

    t7.join();
    t8.join();

    std::cout << "Counter: " << counter << '\n';

    // std::try-lock - for locking multiple mutexes

    std::thread t9(incrementXY, std::ref(X), std::ref(m1), "X ");
    std::thread t10(incrementXY, std::ref(Y), std::ref(m2), "Y ");
    std::thread t11(consumeXY);

    t9.join();
    t10.join();
    t11.join();

    // Timed mutex - wait for amount of time and does another thing
    std::thread t12(increment2, 1);
    std::thread t13(increment2, 2);

    t12.join();
    t13.join();

    std::cout << myAmount << '\n';

    // Recursive mutex - need to unlock it depending on how many times you lock it

    // Lock guard - Scope based auto unlock - locks once initialized and assigned with mutex
    //std::lock_guard<std::mutex> lockGuard(m);

    // Unique lock (same syntax as above) - does not lock when initialized with strategy, additional parameter to determine locking strategy



    // Condition variables
    std::thread t14(withdrawMoney, 500);
    std::thread t15(addMoney, 500);

    t14.join();
    t15.join();


}
