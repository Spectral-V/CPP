//
// Created by victor murris on 20/11/2024.
//

#include "SinWaveGenerator.h"
#include <cmath> // Pour sin()

// Constructeurs
SinWaveGenerator::SinWaveGenerator()
    : TimeSeriesGenerator(), amplitude(1.0), frequency(1.0), phase(0.0) {}

SinWaveGenerator::SinWaveGenerator(int seed, double amplitude, double frequency, double phase)
    : TimeSeriesGenerator(seed), amplitude(amplitude), frequency(frequency), phase(phase) {}

// Implémentation de la méthode generateTimeSeries
std::vector<double> SinWaveGenerator::generateTimeSeries(int size) {
    std::vector<double> series;
    if (size <= 0) return series;

    for (int i = 0; i < size; ++i) {
        double x = static_cast<double>(i); // Temps discret
        double value = amplitude * sin(frequency * x + phase);
        series.push_back(value);
    }

    return series;
}
