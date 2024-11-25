//
// Created by victor murris on 20/11/2024.
//

#include "StepGenerator.h"
#include <cstdlib> // Pour rand() et srand()

// Constructeurs
StepGenerator::StepGenerator() : TimeSeriesGenerator() {}

StepGenerator::StepGenerator(int seed) : TimeSeriesGenerator(seed) {
    srand(seed); // Initialisation de la graine aléatoire
}

// Implémentation de la méthode generateTimeSeries
std::vector<double> StepGenerator::generateTimeSeries(int size) {
    std::vector<double> series;
    if (size <= 0) return series;

    // Initialiser la première valeur à 0
    double currentValue = 0.0;
    series.push_back(currentValue);

    // Générer les valeurs suivantes
    for (int i = 1; i < size; ++i) {
        // Avec une probabilité de 50%, changer ou garder la valeur précédente
        if (rand() % 2 == 0) { // Probabilité de 50%
            currentValue = static_cast<double>(rand() % 101); // Nouvelle valeur entre 0 et 100
        }
        series.push_back(currentValue);
    }

    return series;
}
