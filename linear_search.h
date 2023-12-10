#ifndef LINEAR_SEARCH_H
#define LINEAR_SEARCH_H

#include "search.h"

class LinearSearch : public SearchingAlgorithm {
public:
    LinearSearch();

    int search(const std::vector<int>&, int) override;
};

#endif // LINEAR_SEARCH_H

