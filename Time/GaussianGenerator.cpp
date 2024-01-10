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
    std::vector<double> generateTimeSeries(int size) override {
        std::vector<double> series;
        series.reserve(size);

        // Utilisation de la distribution normale avec Box-Muller
        std::default_random_engine generator(seed);
        std::normal_distribution<double> distribution(mean, stddev);

        for (int i = 0; i < size; ++i) {
            // Génération de deux variables aléatoires indépendantes
            double u1 = static_cast<double>(rand()) / RAND_MAX;
            double u2 = static_cast<double>(rand()) / RAND_MAX;

            // Transformation de Box-Muller pour obtenir une variable aléatoire gaussienne
            double z = sqrt(-2.0 * log(u1)) * cos(2.0 * M_PI * u2);

            // Ajout de la valeur à la série temporelle
            series.push_back(mean + stddev * z);
        }

        return series;
    }

private:
    double mean;   // Moyenne de la distribution gaussienne
    double stddev; // Écart type de la distribution gaussienne
};
