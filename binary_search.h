#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include "search.h"

class BinarySearch : public SearchingAlgorithm {
public:
    BinarySearch();

    int search(const std::vector<int>&, int) override;
};

#endif


