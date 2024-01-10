#ifndef GAU_H
#define GAU_H

#include "TimeSeriesGenerator.h"
#include <cmath>
#include <random>

class GaussianGenerator : public TimeSeriesGenerator {
public:
    // Constructeur par défaut
    GaussianGenerator() : TimeSeriesGenerator(), mean(0.0), stddev(1.0) {}

    // Constructeur paramétrisé
    GaussianGenerator(int seed, double mean, double stddev)
        : TimeSeriesGenerator(seed), mean(mean), stddev(stddev) {}

    // Implémentation de la fonction virtuelle pure
    std::vector<double> generateTimeSeries(int size) override ;

private:
    double mean;   // Moyenne de la distribution gaussienne
    double stddev; // Écart type de la distribution gaussienne
};

#endif // GAUSSIAN_GENERATOR_H
