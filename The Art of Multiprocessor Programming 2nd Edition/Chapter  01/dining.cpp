#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <chrono> 

int main() {
    const int N = 5;      // number of philosophers = number of chopsticks
    const int MEALS = 100;  // how many times each philosopher eats

    std::vector<std::mutex> chopstick(N);
    std::vector<std::thread> workers;

    auto philosopher = [&](int id) {
        int left  = id;
        int right = (id + 1) % N;

        int first  = std::min(left, right);
        int second = std::max(left, right);

        for (int m = 1; m <= MEALS; ++m) {
            // think
            std::this_thread::sleep_for(std::chrono::milliseconds(100 + id * 25));

            {
                std::lock_guard<std::mutex> lk1(chopstick[first]);
                std::lock_guard<std::mutex> lk2(chopstick[second]);

                std::cout << "P" << id << " eating meal " << m << "\n";
                std::this_thread::sleep_for(std::chrono::milliseconds(120));
            } // both chopsticks released here
        }
    };

    // start threads
    for (int i = 0; i < N; ++i) {
        workers.emplace_back(philosopher, i);
    }
    for (auto &t : workers) t.join();

    std::cout << "Done!";
    return 0;
}
