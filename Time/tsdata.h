#ifndef TSDATA_H
#define TSDATA_H

#include <iostream>
#include <vector>
#include <cmath>

class TimeSeriesDataset {
public:
    // Constructeur par défaut
    TimeSeriesDataset() : znormalize(false), isTrain(true), maxLength(0), numberOfSamples(0) {}

    // Constructeur paramétrisé
    TimeSeriesDataset(bool znormalize, bool isTrain)
        : znormalize(znormalize), isTrain(isTrain), maxLength(0), numberOfSamples(0) {}

    // Ajouter une série temporelle avec une étiquette
   // Update the addTimeSeries function in tsdata.h
    void addTimeSeries(const std::vector<double>& series, int label = -1);


    static double euclideanDistance(const std::vector<double>& series1, const std::vector<double>& series2) ;

    double calculateDTWDistance(size_t index1, size_t index2) const ;

    double calculateNormalizedEditDistance(size_t index1, size_t index2) const ;

    // Afficher le jeu de données
    void displayDataset() ;

private:
    bool znormalize;            // Indique si la normalisation Z est activée
    bool isTrain;               // Indique si le jeu de données est pour l'entraînement
    std::vector<std::vector<double>> data;   // Vecteur de séries temporelles
    std::vector<int> labels;    // Vecteur d'étiquettes correspondant aux séries temporelles
    int maxLength;              // Longueur maximale des séries dans le jeu de données
    int numberOfSamples;        // Nombre total de séries dans le jeu de données

    // Fonction pour normaliser une série temporelle
    void normalize(std::vector<double>& series) ;

    // Fonction pour calculer la moyenne d'une série temporelle
    double calculateMean(const std::vector<double>& series) ;

    // Fonction pour calculer l'écart type d'une série temporelle
    double calculateStdDev(const std::vector<double>& series) ;
};

#endif // TIME_SERIES_DATASET_H
