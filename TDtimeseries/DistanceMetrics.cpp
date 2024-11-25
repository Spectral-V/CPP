//
// Created by victor murris on 20/11/2024.
//

#include "DistanceMetrics.h"

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
