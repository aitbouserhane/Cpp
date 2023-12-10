#ifndef SEARCH_H
#define SEARCH_H

#include <vector>
#include <iostream>

class SearchingAlgorithm {
public:
    int numberComparisons;

    static int totalComparisons;
    static int totalSearch;
    static double averageComparisons;

    SearchingAlgorithm();

    virtual int search(const std::vector<int>&, int) = 0;

    void displaySearchResults(std::ostream&, int, int) const;
};

#endif


