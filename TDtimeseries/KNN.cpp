//
// Created by victor murris on 25/11/2024.
//

#include "KNN.h"
#include <algorithm> // Pour std::sort et std::pair


/**
 * @brief Constructs a K-Nearest Neighbors (KNN) model with the specified number of neighbors and similarity measure.
 * @param k The number of nearest neighbors to consider (must be greater than 0).
 * @param similarityMeasure The method to use for calculating similarity (e.g., "euclidean_distance" or "dtw").
 * @throw std::invalid_argument If k is less than or equal to 0.
 */
KNN::KNN(int k, const std::string& similarityMeasure)
    : k(k), similarityMeasure(similarityMeasure) {
    if (k <= 0) {
        throw std::invalid_argument("k doit être supérieur à 0.");
    }
}

/**
 * Calculates the distance between two time series based on the specified similarity measure.
 *
 * @param series1 The first time series of doubles.
 * @param series2 The second time series of doubles.
 * @return The computed distance between the two time series.
 * @throws std::invalid_argument if the similarity measure is not recognized.
 */
double KNN::calculateDistance(const std::vector<double>& series1, const std::vector<double>& series2) const {
    if (similarityMeasure == "euclidean_distance") {
        return DistanceMetrics::euclideanDistance(series1, series2);
    } else if (similarityMeasure == "dtw") {
        return DistanceMetrics::dynamicTimeWarping(series1, series2);
    } else {
        throw std::invalid_argument("Mesure de similarité non reconnue : " + similarityMeasure);
    }
}

/**
 * Evaluates the K-Nearest Neighbors model on the provided test data.
 *
 * @param trainData The dataset used for training, containing time series and their corresponding labels.
 * @param testData The dataset used for testing, containing time series without labels.
 * @param groundTruth A vector of integers representing the true labels of the test data.
 * @return The accuracy of the model as a double, which is the ratio of correct predictions to the total number of test instances.
 * @throw std::invalid_argument If the size of test data does not match the size of ground truth labels.
 */
double KNN::evaluate(const TimeSeriesDataset& trainData, const TimeSeriesDataset& testData, const std::vector<int>& groundTruth) {
    const auto& trainSeries = trainData.getData();
    const auto& trainLabels = trainData.getLabels();
    const auto& testSeries = testData.getData();

    if (testSeries.size() != groundTruth.size()) {
        throw std::invalid_argument("La taille des données de test et des ground truth ne correspond pas.");
    }

    int correct = 0;


    for (size_t i = 0; i < testSeries.size(); ++i) {
        std::vector<std::pair<double, int>> distances;

        for (size_t j = 0; j < trainSeries.size(); ++j) {
            double distance = calculateDistance(testSeries[i], trainSeries[j]);
            distances.emplace_back(distance, trainLabels[j]);
        }

        std::sort(distances.begin(), distances.end());

        std::vector<int> neighborLabels;
        for (int n = 0; n < k && n < static_cast<int>(distances.size()); ++n) {
            neighborLabels.push_back(distances[n].second);
        }

        std::vector<int> labelCount(10, 0);
        for (int label : neighborLabels) {
            labelCount[label]++;
        }

        int predictedLabel = std::distance(labelCount.begin(), std::max_element(labelCount.begin(), labelCount.end()));

        if (predictedLabel == groundTruth[i]) {
            correct++;
        }
    }

    return static_cast<double>(correct) / groundTruth.size();
}
