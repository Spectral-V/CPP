//
// Created by victor murris on 25/11/2024.
//
#ifndef KNN_H
#define KNN_H

#include <vector>
#include <string>
#include "DistanceMetrics.h"
#include "TimeSeriesDataset.h"

class KNN {
private:
    int k;                       // Nombre de voisins
    std::string similarityMeasure; // Méthode de similarité ("euclidean_distance" ou "dtw")

    // Méthode privée pour calculer la distance entre deux séries
    double calculateDistance(const std::vector<double>& series1, const std::vector<double>& series2) const;

public:
    // Constructeur
    KNN(int k, const std::string& similarityMeasure);

    // Fonction pour évaluer le modèle
    double evaluate(const TimeSeriesDataset& trainData, const TimeSeriesDataset& testData, const std::vector<int>& groundTruth);

    ~KNN() {}
};

#endif // KNN_H
