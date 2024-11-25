//
// Created by victor murris on 20/11/2024.
//

#ifndef TIMESERIESDATASET_H
#define TIMESERIESDATASET_H

#include <vector>
#include <cmath> // Pour std::sqrt
#include <stdexcept> // Pour les exceptions
#include <iostream>

class TimeSeriesDataset {
private:
    bool znormalize;                    // Indique si les séries doivent être normalisées
    bool isTrain;                       // Indique si c'est un ensemble d'entraînement
    std::vector<std::vector<double>> data; // Les séries temporelles
    std::vector<int> labels;            // Les classes associées aux séries
    int maxLength;                      // Longueur maximale des séries
    int numberOfSamples;                // Nombre total de séries

    // Méthode privée pour normaliser une série temporelle
    void zNormalizeSeries(std::vector<double>& series);

public:
    // Constructeur
    TimeSeriesDataset(bool znormalize, bool isTrain);

    // Ajout d'une série temporelle avec son label
    void addTimeSeries(const std::vector<double>& series, int label);

    // Accesseurs
    const std::vector<std::vector<double>>& getData() const;
    const std::vector<int>& getLabels() const;

    // Affichage des séries et labels
    void printDataset() const;

    ~TimeSeriesDataset() {}
};

#endif // TIMESERIESDATASET_H

