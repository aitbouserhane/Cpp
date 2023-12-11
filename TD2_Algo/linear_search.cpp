#include "linear_search.h"

LinearSearch::LinearSearch() : SearchingAlgorithm() {}

int LinearSearch::search(const std::vector<int>& arr, int target) {
    numberComparisons = 0;
    for (size_t i = 0; i < arr.size(); ++i) {
        numberComparisons++;
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}


