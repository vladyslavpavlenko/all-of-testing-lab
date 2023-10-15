#include "predicates.h"

bool is_prime(int n) {
    if (n <= 1) {
        return false;
    }

    for (int i = 2; i <= n / 2; ++i) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

bool all_true(int n) {
    return true;
}

bool is_positive(int n) {
    return n > 0;
}