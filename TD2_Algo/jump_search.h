#ifndef JUMP_SEARCH_H
#define JUMP_SEARCH_H

#include "search.h"
#include <cmath>

class JumpSearch : public SearchingAlgorithm {
public:
    JumpSearch();

    int search(const std::vector<int>&, int) override;
};
#endif
