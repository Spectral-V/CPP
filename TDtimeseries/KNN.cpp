//
// Created by victor murris on 25/11/2024.
//

#include "KNN.h"
#include <algorithm> // Pour std::sort et std::pair


// Constructeur
KNN::KNN(int k, const std::string& similarityMeasure)
    : k(k), similarityMeasure(similarityMeasure) {
    if (k <= 0) {
        throw std::invalid_argument("k doit être supérieur à 0.");
    }
}

// Méthode privée pour calculer la distance
double KNN::calculateDistance(const std::vector<double>& series1, const std::vector<double>& series2) const {
    if (similarityMeasure == "euclidean_distance") {
        return DistanceMetrics::euclideanDistance(series1, series2);
    } else if (similarityMeasure == "dtw") {
        return DistanceMetrics::dynamicTimeWarping(series1, series2);
    } else {
        throw std::invalid_argument("Mesure de similarité non reconnue : " + similarityMeasure);
    }
}

// Évaluer le modèle KNN
double KNN::evaluate(const TimeSeriesDataset& trainData, const TimeSeriesDataset& testData, const std::vector<int>& groundTruth) {
    const auto& trainSeries = trainData.getData();
    const auto& trainLabels = trainData.getLabels();
    const auto& testSeries = testData.getData();

    if (testSeries.size() != groundTruth.size()) {
        throw std::invalid_argument("La taille des données de test et des ground truth ne correspond pas.");
    }

    int correct = 0;

    // Pour chaque série de test
    for (size_t i = 0; i < testSeries.size(); ++i) {
        std::vector<std::pair<double, int>> distances;

        // Calculer les distances entre la série de test et chaque série d'entraînement
        for (size_t j = 0; j < trainSeries.size(); ++j) {
            double distance = calculateDistance(testSeries[i], trainSeries[j]);
            distances.emplace_back(distance, trainLabels[j]);
        }

        // Trier les distances par ordre croissant
        std::sort(distances.begin(), distances.end());

        // Trouver les k plus proches voisins
        std::vector<int> neighborLabels;
        for (int n = 0; n < k && n < static_cast<int>(distances.size()); ++n) {
            neighborLabels.push_back(distances[n].second);
        }

        // Trouver la classe majoritaire parmi les voisins
        std::vector<int> labelCount(10, 0); // Supposons un maximum de 10 classes
        for (int label : neighborLabels) {
            labelCount[label]++;
        }

        int predictedLabel = std::distance(labelCount.begin(), std::max_element(labelCount.begin(), labelCount.end()));

        // Vérifier si la prédiction est correcte
        if (predictedLabel == groundTruth[i]) {
            correct++;
        }
    }

    // Retourner la précision
    return static_cast<double>(correct) / groundTruth.size();
}
