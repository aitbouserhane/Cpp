#include <cmath>
#include <vector>

class SinWaveGenerator : public TimeSeriesGenerator {
public:
    // Constructeur par défaut
    SinWaveGenerator() : TimeSeriesGenerator(), amplitude(1.0), frequency(1.0), phase(0.0) {}

    // Constructeur paramétrisé
    SinWaveGenerator(int seed, double amplitude, double frequency, double phase)
        : TimeSeriesGenerator(seed), amplitude(amplitude), frequency(frequency), phase(phase) {}

    // Implémentation de la fonction virtuelle pure
    std::vector<double> generateTimeSeries(int size) override {
        std::vector<double> series;
        series.reserve(size);

        for (int i = 0; i < size; ++i) {
            double value = amplitude * sin(frequency * i + phase);
            series.push_back(value);
        }

        return series;
    }

private:
    double amplitude; // Amplitude de la fonction sinus
    double frequency; // Fréquence de la fonction sinus
    double phase;     // Phase initiale de la fonction sinus
};
