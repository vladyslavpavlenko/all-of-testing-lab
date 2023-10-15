#ifndef LAB2_ALL_OF_H
#define LAB2_ALL_OF_H

#include <vector>
#include <algorithm>
#include <thread>

template<typename Iterator, typename Predicate>
bool process_part(Iterator begin, Iterator end, Predicate pred) {
    return std::all_of(begin, end, pred);
}

template<typename Iterator, typename Predicate>
bool par_all_of(Iterator begin, Iterator end, Predicate pred, int numThreads) {
    int dataSize = std::distance(begin, end);
    int partSize = dataSize / numThreads;

    std::vector<bool> results(numThreads);
    std::vector<std::thread> threads;

    for (int i = 0; i < numThreads; ++i) {
        Iterator partBegin = begin + i * partSize;
        Iterator partEnd = (i == numThreads - 1) ? end : partBegin + partSize;

        threads.emplace_back([partBegin, partEnd, &results, i, &pred]() {
            results[i] = process_part(partBegin, partEnd, pred);
        });
    }

    for (auto &thread: threads) {
        thread.join();
    }

    return std::all_of(results.begin(), results.end(), [](bool val) { return val; });
}

#endif //LAB2_ALL_OF_H