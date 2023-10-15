#ifndef LAB2_UTILS_H
#define LAB2_UTILS_H

#include <iostream>
#include <iomanip>
#include <chrono>
#include <algorithm>
#include <execution>
#include <optional>
#include <vector>
#include <random>

struct test {
    bool (*predicate)(int);

    std::string name;
};

void random_fill(std::vector<int> &v);

template<typename ExecutionPolicy = std::execution::sequenced_policy>
void test_all_of(const std::vector<int> &v, const test &pred, std::optional<ExecutionPolicy> policy = std::nullopt,
                 const std::optional<std::string> &policy_name = std::nullopt) {
    std::cout << std::left
              << std::setw(11 + 7) << "std::all_of"
              << std::setw(10 + 7) << v.size();
    auto start = std::chrono::high_resolution_clock::now();

    std::cout << std::setw(9 + 7) << (policy_name ? policy_name.value().c_str() : "-")
              << std::setw(11 + 7) << pred.name
              << std::setw(1) << (policy ? std::all_of(*policy, v.begin(), v.end(), pred.predicate) :
                                  std::all_of(v.begin(), v.end(), pred.predicate))
              << std::setw(7) << " ";
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration = end - start;

    std::cout << std::setw(8) << std::fixed << duration.count() << " sec" << std::endl;
}

#endif //LAB2_UTILS_H