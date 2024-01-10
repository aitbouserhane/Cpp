#ifndef TIME_SERIES_GENERATOR_H
#define TIME_SERIES_GENERATOR_H

#include <iostream>
#include <vector>
#include <cstdlib>

class TimeSeriesGenerator {
public:
    // Constructeur par défaut
    TimeSeriesGenerator() : seed(0) {}

    // Constructeur paramétrisé
    TimeSeriesGenerator(int seed) : seed(seed) {}

    // Fonction virtuelle pure pour générer une série temporelle
    virtual std::vector<double> generateTimeSeries(int size) = 0;

    // Fonction statique pour imprimer une série temporelle
    static void printTimeSeries(const std::vector<double>& series) {
        std::cout << "Time Series: ";
        for (double value : series) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }

protected:
    int seed; // Attribut pour stocker la graine (seed)
};

#endif // TIME_SERIES_GENERATOR_H
