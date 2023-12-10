#include "jump_search.h"

JumpSearch::JumpSearch() : SearchingAlgorithm() {}

int JumpSearch::search(const std::vector<int>& arr, int target) {
    numberComparisons = 0;
    size_t n = arr.size();
    size_t step = sqrt(n);
    size_t prev = 0;

    while (arr[std::min(step, n) - 1] < target) {
        prev = step;
        step += sqrt(n);
        numberComparisons++;
        if (prev >= n) {
            return -1;
        }
    }

    while (arr[prev] < target) {
        prev++;
        numberComparisons++;
        if (prev == std::min(step, n)) {
            return -1;
        }
    }

    numberComparisons++; // For the final comparison.
    if (arr[prev] == target) {
        return prev;
    }

    return -1;
}

