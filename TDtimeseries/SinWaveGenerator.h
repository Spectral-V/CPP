//
// Created by victor murris on 20/11/2024.
//

#ifndef SINWAVEGENERATOR_H
#define SINWAVEGENERATOR_H

#include "TimeSeriesGenerator.h"
#include <vector>

class SinWaveGenerator : public TimeSeriesGenerator {
private:
    double amplitude;  // Amplitude de l'onde
    double frequency;  // Fréquence (ω)
    double phase;      // Phase initiale (ϕ)
public:
    // Constructeurs
    SinWaveGenerator();
    SinWaveGenerator(int seed, double amplitude, double frequency, double phase);

    // Implémentation de la méthode virtuelle pure
    std::vector<double> generateTimeSeries(int size) override;

    ~SinWaveGenerator() {}
};

#endif // SINWAVEGENERATOR_H

