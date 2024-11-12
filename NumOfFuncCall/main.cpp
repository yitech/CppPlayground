#include <iostream>
#include <mutex>
#include <thread>

std::mutex mtx;
int call_count = 0;  // Global variable

void myFunction() {
    std::lock_guard<std::mutex> lock(mtx);  // Lock the mutex
    call_count++;
    std::cout << "Function called " << call_count << " times." << std::endl;
}

void runThread() {
    for (int i = 0; i < 5; ++i) {
        myFunction();
    }
}

int main() {
    std::thread t1(runThread);
    std::thread t2(runThread);

    t1.join();
    t2.join();
    return 0;
}
