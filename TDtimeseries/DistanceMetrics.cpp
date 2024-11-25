#include "DistanceMetrics.h"
#include <algorithm> // for std::min


/**
 * Calculates the Euclidean distance between two time series.
 *
 * @param series1 The first time series of doubles.
 * @param series2 The second time series of doubles.
 * @return The Euclidean distance between the two time series.
 * @throws std::invalid_argument if the time series do not have the same length.
 */
double DistanceMetrics::euclideanDistance(const std::vector<double>& series1, const std::vector<double>& series2) {
    if (series1.size() != series2.size()) {
        throw std::invalid_argument("Les séries temporelles doivent avoir la même longueur.");
    }

    double sum = 0.0;
    for (size_t i = 0; i < series1.size(); ++i) {
        double diff = series1[i] - series2[i];
        sum += diff * diff;
    }

    return std::sqrt(sum);
}

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
double DistanceMetrics::dynamicTimeWarping(const std::vector<double>& series1, const std::vector<double>& series2) {
    size_t len1 = series1.size();
    size_t len2 = series2.size();

    std::vector<std::vector<double>> dtw(len1 + 1, std::vector<double>(len2 + 1, std::numeric_limits<double>::infinity()));
    dtw[0][0] = 0.0;

    for (size_t i = 1; i <= len1; ++i) {
        for (size_t j = 1; j <= len2; ++j) {
            double cost = std::pow(series1[i - 1] - series2[j - 1], 2);
            dtw[i][j] = cost + std::min({dtw[i - 1][j],
                                         dtw[i][j - 1],
                                         dtw[i - 1][j - 1]
                                        });
        }
    }


    return std::sqrt(dtw[len1][len2]);
}
