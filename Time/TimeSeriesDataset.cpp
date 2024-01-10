#include <iostream>
#include <vector>
#include <cmath>
#include "tsdata.h"

class TimeSeriesDataset {
public:
    // Constructeur par défaut
    TimeSeriesDataset() : znormalize(false), isTrain(true), maxLength(0), numberOfSamples(0) {}

    // Constructeur paramétrisé
    TimeSeriesDataset(bool znormalize, bool isTrain)
        : znormalize(znormalize), isTrain(isTrain), maxLength(0), numberOfSamples(0) {}

    // Ajouter une série temporelle avec une étiquette
    // Update the addTimeSeries function in tsdata.cpp
    void TimeSeriesDataset::addTimeSeries(const std::vector<double>& series, int label) {
    // Vérifier si la normalisation Z est activée
    if (znormalize) {
        normalize(series);
    }

    data.push_back(series);
    labels.push_back(label);

    // Mettre à jour la longueur maximale des séries dans le jeu de données
    if (series.size() > maxLength) {
        maxLength = static_cast<int>(series.size());
    }

    // Mettre à jour le nombre de séries dans le jeu de données
    numberOfSamples++;
    }


    static double euclideanDistance(const std::vector<double>& series1, const std::vector<double>& series2) {
        // Vérifier que les deux séries ont la même longueur
        if (series1.size() != series2.size()) {
            throw std::invalid_argument("Series must have the same length for Euclidean distance calculation.");
        }

        double sumSquaredDiff = 0.0;

        // Calcul de la somme des carrés des différences
        for (size_t i = 0; i < series1.size(); ++i) {
            sumSquaredDiff += std::pow(series1[i] - series2[i], 2);
        }

        // Calcul de la distance euclidienne
        double euclideanDist = std::sqrt(sumSquaredDiff);
        return euclideanDist;
    }

    double calculateDTWDistance(size_t index1, size_t index2) const {
        // Ensure the indices are within bounds
        if (index1 >= numberOfSamples || index2 >= numberOfSamples) {
            throw std::out_of_range("Invalid indices for DTW distance calculation.");
        }

        const std::vector<double>& series1 = data[index1];
        const std::vector<double>& series2 = data[index2];

        // Get the lengths of the two time series
        size_t len1 = series1.size();
        size_t len2 = series2.size();

        // Initialize the DTW matrix
        std::vector<std::vector<double>> dtwMatrix(len1 + 1, std::vector<double>(len2 + 1, 0.0));

        // Set the initial values
        dtwMatrix[0][0] = 0.0;
        for (size_t i = 1; i <= len1; ++i) {
            dtwMatrix[i][0] = std::numeric_limits<double>::infinity();
        }
        for (size_t j = 1; j <= len2; ++j) {
            dtwMatrix[0][j] = std::numeric_limits<double>::infinity();
        }

        // Calculate DTW matrix
        for (size_t i = 1; i <= len1; ++i) {
            for (size_t j = 1; j <= len2; ++j) {
                double cost = std::pow(series1[i - 1] - series2[j - 1], 2);
                double insert = dtwMatrix[i][j - 1];
                double deleteOp = dtwMatrix[i - 1][j];
                double moveOp = dtwMatrix[i - 1][j - 1];

                dtwMatrix[i][j] = cost + std::min({insert, deleteOp, moveOp});
            }
        }

        // Return the DTW distance
        return dtwMatrix[len1][len2];
    }

    double calculateNormalizedEditDistance(size_t index1, size_t index2) const {
        // Assurez-vous que les indices sont valides
        if (index1 >= numberOfSamples || index2 >= numberOfSamples) {
            throw std::out_of_range("Invalid indices for edit distance calculation.");
        }

        const std::vector<double>& sequence1 = data[index1];
        const std::vector<double>& sequence2 = data[index2];

        size_t len1 = sequence1.size();
        size_t len2 = sequence2.size();

        // Initialiser la matrice d'édition
        std::vector<std::vector<double>> editMatrix(len1 + 1, std::vector<double>(len2 + 1, 0.0));

        // Initialiser la première ligne et la première colonne
        for (size_t i = 0; i <= len1; ++i) {
            editMatrix[i][0] = i;
        }

        for (size_t j = 0; j <= len2; ++j) {
            editMatrix[0][j] = j;
        }

        // Calculer la matrice d'édition
        for (size_t i = 1; i <= len1; ++i) {
            for (size_t j = 1; j <= len2; ++j) {
                double cost = (sequence1[i - 1] == sequence2[j - 1]) ? 0.0 : 1.0;
                editMatrix[i][j] = std::min({editMatrix[i - 1][j] + 1,    // Suppression
                                             editMatrix[i][j - 1] + 1,    // Insertion
                                             editMatrix[i - 1][j - 1] + cost}); // Substitution
            }
        }

        // Retourner la distance d'édition normalisée
        return editMatrix[len1][len2] / std::max(len1, len2);
    }

    // Afficher le jeu de données
    void displayDataset() {
        for (size_t i = 0; i < data.size(); ++i) {
            std::cout << "Sample " << i << " - Label: " << labels[i] << " - Series: ";
            for (double value : data[i]) {
                std::cout << value << " ";
            }
            std::cout << std::endl;
        }
    }

private:
    bool znormalize;            // Indique si la normalisation Z est activée
    bool isTrain;               // Indique si le jeu de données est pour l'entraînement
    std::vector<std::vector<double>> data;   // Vecteur de séries temporelles
    std::vector<int> labels;    // Vecteur d'étiquettes correspondant aux séries temporelles
    int maxLength;              // Longueur maximale des séries dans le jeu de données
    int numberOfSamples;        // Nombre total de séries dans le jeu de données

    // Fonction pour normaliser une série temporelle
    void normalize(std::vector<double>& series) {
        double mean = calculateMean(series);
        double stddev = calculateStdDev(series);

        for (double& value : series) {
            value = (value - mean) / stddev;
        }
    }

    // Fonction pour calculer la moyenne d'une série temporelle
    double calculateMean(const std::vector<double>& series) {
        double sum = 0.0;
        for (double value : series) {
            sum += value;
        }
        return sum / series.size();
    }

    // Fonction pour calculer l'écart type d'une série temporelle
    double calculateStdDev(const std::vector<double>& series) {
        double mean = calculateMean(series);
        double sumSquares = 0.0;

        for (double value : series) {
            sumSquares += std::pow(value - mean, 2);
        }

        return std::sqrt(sumSquares / series.size());
    }
};
