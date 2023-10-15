#include "utils.h"

void random_fill(std::vector<int> &v) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(-10000, 10000);

    for (auto &e: v) {
        e = dis(gen);
    }
}
