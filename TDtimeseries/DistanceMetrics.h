//
// Created by victor murris on 20/11/2024.
//

#ifndef DISTANCEMETRICS_H
#define DISTANCEMETRICS_H

#include <vector>
#include <cmath>
#include <stdexcept>

class DistanceMetrics {
public:
    // Distance euclidienne entre deux séries temporelles
    static double euclideanDistance(const std::vector<double>& series1, const std::vector<double>& series2);
};

#endif // DISTANCEMETRICS_H

