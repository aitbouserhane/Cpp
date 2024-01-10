#include <cstdlib>
#include <ctime>
#include <vector>

class StepGenerator : public TimeSeriesGenerator {
public:
    // Constructeur par défaut
    StepGenerator() : TimeSeriesGenerator() {
        srand(static_cast<unsigned>(time(nullptr)));
    }

    // Constructeur paramétrisé
    StepGenerator(int seed) : TimeSeriesGenerator(seed) {
        srand(seed);
    }

    // Implémentation de la fonction virtuelle pure
    std::vector<double> generateTimeSeries(int size) override {
        std::vector<double> series;
        series.reserve(size);

        // La première valeur est 0
        series.push_back(0);

        for (int i = 1; i < size; ++i) {
            // Choix aléatoire entre 0 et 1 avec probabilité 50% chacun
            if (rand() % 2 == 0) {
                // Si 0, garder la valeur précédente
                series.push_back(series[i - 1]);
            } else {
                // Sinon, effectuer un saut aléatoire entre 0 et 100
                series.push_back(rand() % 101);
            }
        }

        return series;
    }
};
