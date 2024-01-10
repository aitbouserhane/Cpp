#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include "tsdata.h" // Include the TimeSeriesDataset header
#include "knn.h"

class KNN {
public:
    // Constructeur paramétrisé
    KNN(int k, const std::string& similarityMeasure)
        : k(k), similarityMeasure(similarityMeasure) {}

    // Fonction pour évaluer la métrique "accuracy"
    double KNN::evaluate(const TimeSeriesDataset& trainSet, const TimeSeriesDataset& testSet, const std::vector<int>& groundTruth) const {
    if (trainSet.getNumberOfSamples() != groundTruth.size()) {
        throw std::invalid_argument("Mismatched sizes between train set and ground truth.");
    }

    size_t totalSamples = testSet.getNumberOfSamples();
    size_t correctPredictions = 0;

    for (size_t i = 0; i < totalSamples; ++i) {
        int trueLabel = groundTruth[i];
        int predictedLabel = predict(testSet.getData(i));

        if (trueLabel == predictedLabel) {
            correctPredictions++;
        }
    }

    return static_cast<double>(correctPredictions) / totalSamples;
}

    // Fonction pour prédire l'étiquette d'une série temporelle
    int predict(const std::vector<double>& querySeries) const {
        std::vector<std::pair<int, double>> neighbors; // (label, distance)

        // Trouver les k plus proches voisins
        for (size_t i = 0; i < trainingSet.getNumberOfSamples(); ++i) {
            const std::vector<double>& trainingSeries = trainingSet.getData(i);
            double distance = calculateDistance(querySeries, trainingSeries);

            neighbors.push_back({trainingSet.getLabel(i), distance});
        }

        // Trier les voisins par distance
        std::sort(neighbors.begin(), neighbors.end(),
                  [](const auto& a, const auto& b) { return a.second < b.second; });

        // Compter les occurrences des étiquettes des k plus proches voisins
        std::unordered_map<int, int> labelCount;
        for (size_t i = 0; i < k; ++i) {
            labelCount[neighbors[i].first]++;
        }

        // Choisir la classe la plus populeuse parmi les voisins
        int predictedLabel = -1;
        int maxCount = -1;

        for (const auto& entry : labelCount) {
            if (entry.second > maxCount) {
                maxCount = entry.second;
                predictedLabel = entry.first;
            }
        }

        return predictedLabel;
    }

    // Fonction pour définir le jeu de données d'entraînement
    void setTrainingSet(const TimeSeriesDataset& trainingData) {
        trainingSet = trainingData;
    }

private:
    int k;  // Nombre de voisins
    std::string similarityMeasure; // Mesure de similarité utilisée
    TimeSeriesDataset trainingSet; // Jeu de données d'entraînement

    // Fonction pour calculer la distance entre deux séries temporelles
    double calculateDistance(const std::vector<double>& series1, const std::vector<double>& series2) const {
        if (similarityMeasure == "euclidean") {
            // Utilisez la fonction d'écart euclidien définie dans TimeSeriesDataset
            return TimeSeriesDataset::euclideanDistance(series1, series2);
        }
        // Ajoutez d'autres mesures de similarité au besoin

        throw std::invalid_argument("Unknown similarity measure");
    }
};
