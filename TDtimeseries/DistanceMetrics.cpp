#include "DistanceMetrics.h"
#include <algorithm> // Pour std::min

// Distance euclidienne
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

// Dynamic Time Warping (DTW)
double DistanceMetrics::dynamicTimeWarping(const std::vector<double>& series1, const std::vector<double>& series2) {
    size_t len1 = series1.size();
    size_t len2 = series2.size();

    // Matrice DTW initialisée avec des valeurs infinies
    std::vector<std::vector<double>> dtw(len1 + 1, std::vector<double>(len2 + 1, std::numeric_limits<double>::infinity()));
    dtw[0][0] = 0.0;

    // Calcul des coûts accumulés
    for (size_t i = 1; i <= len1; ++i) {
        for (size_t j = 1; j <= len2; ++j) {
            double cost = std::pow(series1[i - 1] - series2[j - 1], 2);
            dtw[i][j] = cost + std::min({dtw[i - 1][j],    // Suppression
                                         dtw[i][j - 1],    // Insertion
                                         dtw[i - 1][j - 1] // Substitution
                                        });
        }
    }

    // La valeur finale est dans le coin inférieur droit
    return std::sqrt(dtw[len1][len2]);
}
