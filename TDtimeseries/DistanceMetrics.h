//
// Created by victor murris on 25/11/2024.
//
#ifndef DISTANCEMETRICS_H
#define DISTANCEMETRICS_H

#include <vector>
#include <cmath>
#include <stdexcept>
#include <limits>

/**
 * @brief Class providing methods to compute distance metrics for time series.
 */
class DistanceMetrics {
    /**
     * Calculates the Euclidean distance between two time series.
     *
     * @param series1 The first time series of doubles.
     * @param series2 The second time series of doubles.
     * @return The Euclidean distance between the two time series.
     * @throws std::invalid_argument if the time series do not have the same length.
     */
public:
    static double euclideanDistance(const std::vector<double>& series1, const std::vector<double>& series2);

    /**
     * Computes the Dynamic Time Warping (DTW) distance between two time series.
     *
     * This method uses a dynamic programming approach to measure the similarity
     * between two sequences, which may vary in length. The DTW distance accounts
     * for shifts and distortions in the time dimension by finding an optimal alignment.
     *
     * @param series1 The first time series.
     * @param series2 The second time series.
     * @return The DTW distance between the two time series.
     */
    static double dynamicTimeWarping(const std::vector<double>& series1, const std::vector<double>& series2);
};

#endif // DISTANCEMETRICS_H
