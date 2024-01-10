#ifndef KNN_H
#define KNN_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include "tsdata.h" // Include the TimeSeriesDataset header


class KNN {
public:
    // Constructeur paramétrisé
    KNN(int k, const std::string& similarityMeasure)
        : k(k), similarityMeasure(similarityMeasure) {}

    // Fonction pour évaluer la métrique "accuracy"
    double evaluate(const TimeSeriesDataset& trainSet, const TimeSeriesDataset& testSet, const std::vector<int>& groundTruth) const;


    int predict(const std::vector<double>& querySeries) const ;

    
    void setTrainingSet(const TimeSeriesDataset& trainingData) ;

private:
    int k;  // Nombre de voisins
    std::string similarityMeasure; // Mesure de similarité utilisée
    TimeSeriesDataset trainingSet; // Jeu de données d'entraînement

    // Fonction pour calculer la distance entre deux séries temporelles
    double calculateDistance(const std::vector<double>& series1, const std::vector<double>& series2) const ;
};

#endif // KNN_H
