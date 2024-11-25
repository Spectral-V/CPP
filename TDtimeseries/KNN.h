//
// Created by victor murris on 25/11/2024.
//
#ifndef KNN_H
#define KNN_H

#include <vector>
#include <string>
#include "DistanceMetrics.h"
#include "TimeSeriesDataset.h"

/**
 * @class KNN
 * @brief A class implementing the k-Nearest Neighbors algorithm for time series classification.
 */
class KNN {
 /**
  * @brief Number of nearest neighbors to consider in the KNN algorithm.
  */
private:
    int k;
 /**
  * Variable to determine the similarity measure for calculating distances
  * between time series.
  *
  * This variable is used in the calculateDistance method to select the
  * appropriate distance metric (e.g., Euclidean distance, dynamic time
  * warping). The allowed values are "euclidean_distance" and "dtw".
  */
 std::string similarityMeasure;

 /**
  * Calculates the distance between two time series based on the specified similarity measure.
  *
  * @param series1 The first time series of doubles.
  * @param series2 The second time series of doubles.
  * @return The distance between the two time series according to the configured similarity measure.
  * @throws std::invalid_argument if an unrecognized similarity measure is used.
  */
 double calculateDistance(const std::vector<double>& series1, const std::vector<double>& series2) const;

 /**
  * Constructs a K-Nearest Neighbors (KNN) model with the specified number of neighbors (k)
  * and the given similarity measure.
  *
  * @param k The number of nearest neighbors to consider. Must be greater than 0.
  * @param similarityMeasure A string indicating the similarity measure to use (e.g., "dtw", "euclidean_distance").
  * @throws std::invalid_argument if k is less than or equal to 0.
  */
public:
    KNN(int k, const std::string& similarityMeasure);

 /**
  * Evaluates the performance of the K-Nearest Neighbors model on the given test dataset.
  *
  * @param trainData The training dataset containing time series data and their associated labels.
  * @param testData The test dataset containing time series data to be classified.
  * @param groundTruth A vector containing the true labels for the test dataset.
  * @return The accuracy of the model, defined as the proportion of correctly classified instances in the test dataset.
  * @throws std::invalid_argument if the size of the test data does not match the size of the ground truth labels.
  */
 double evaluate(const TimeSeriesDataset& trainData, const TimeSeriesDataset& testData, const std::vector<int>& groundTruth);

 /**
  * Destructor for the KNN class.
  *
  * This destructor is responsible for cleaning up any resources
  * allocated during the lifetime of the KNN instance.
  */
 ~KNN() {}
};

#endif // KNN_H
