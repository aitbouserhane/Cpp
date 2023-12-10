#include "search.h"

int SearchingAlgorithm::totalComparisons = 0;
int SearchingAlgorithm::totalSearch = 0;
double SearchingAlgorithm::averageComparisons = 0.0;

SearchingAlgorithm::SearchingAlgorithm() : numberComparisons(0) {}

void SearchingAlgorithm::displaySearchResults(std::ostream& os, int results, int target) const {
    totalSearch++;

    if (results == -1) {
        os << "Searching for the element " << target << " was not successful.";
    } else {
        totalComparisons += numberComparisons;
        averageComparisons = static_cast<double>(totalComparisons) / totalSearch;
        os << "It took a total of " << numberComparisons << " comparisons to find the element " << target << " on index " << results;
    }
    os << std::endl << std::endl;
}


