#include "tests.h"

void test_custom_all_of() {
    std::vector<int> v(1000000000);

    std::cout << std::left
              << std::setw(10 + 7) << " "
              << std::setw(1 + 7) << "K"
              << std::setw(10 + 7) << "SIZE"
              << std::setw(9 + 7) << "PREDICATE"
              << std::setw(1 + 9) << "↓"
              << std::setw(11) << "TIME TAKEN" << std::endl;

    random_fill(v);

    for (int k = 1; k <= 20; k++) {
        std::cout << std::setw(10 + 7) << "par_all_of"
                  << std::left << std::setw(1 + 7) << k
                  << std::setw(10 + 7) << v.size()
                  << std::setw(9 + 7) << "all_true";

        auto start = std::chrono::high_resolution_clock::now();
        std::cout << std::setw(1) << par_all_of(v.begin(), v.end(), all_true, k) << std::setw(7) << " ";
        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> duration = end - start;

        std::cout << std::setw(8) << std::fixed << duration.count() << " sec" << std::endl;
    }
}


void test_all() {
    std::vector<test> tests = {
            {is_positive, "is_positive"},
            {is_prime,    "is_prime"},
            {all_true,    "all_true"}
    };

    std::cout << std::left
              << std::setw(11 + 7) << " "
              << std::setw(10 + 7) << "SIZE"
              << std::setw(9 + 7) << "POLICY"
              << std::setw(11 + 7) << "PREDICATE"
              << std::setw(1 + 9) << "↓"
              << std::setw(11) << "TIME TAKEN" << std::endl;

    for (int i = 1000; i <= 1000000000; i *= 10) {
        std::vector<int> v(i);
        random_fill(v);

        for (auto &pred: tests) {
            test_all_of(v, pred);
            test_all_of(v, pred, std::optional(std::execution::seq), std::optional<std::string>("seq"));
            test_all_of(v, pred, std::optional(std::execution::unseq), std::optional<std::string>("unseq"));
            test_all_of(v, pred, std::optional(std::execution::par), std::optional<std::string>("par"));
            test_all_of(v, pred, std::optional(std::execution::par_unseq), std::optional<std::string>("par_unseq"));
            std::cout << std::endl;
        }
    }
}