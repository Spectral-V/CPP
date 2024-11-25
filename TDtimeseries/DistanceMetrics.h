#ifndef DISTANCEMETRICS_H
#define DISTANCEMETRICS_H

#include <vector>
#include <cmath>
#include <stdexcept>
#include <limits>

class DistanceMetrics {
public:
    // Distance euclidienne entre deux séries temporelles
    static double euclideanDistance(const std::vector<double>& series1, const std::vector<double>& series2);

    // Dynamic Time Warping (DTW) entre deux séries temporelles
    static double dynamicTimeWarping(const std::vector<double>& series1, const std::vector<double>& series2);
};

#endif // DISTANCEMETRICS_H
