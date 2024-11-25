//
// Created by victor murris on 20/11/2024.
//
#ifndef STEPGENERATOR_H
#define STEPGENERATOR_H

#include "TimeSeriesGenerator.h"
#include <vector>

class StepGenerator : public TimeSeriesGenerator {
public:
    // Constructeurs
    StepGenerator();
    StepGenerator(int seed);

    // Implémentation de la méthode virtuelle pure
    std::vector<double> generateTimeSeries(int size) override;

    ~StepGenerator() {}
};

#endif // STEPGENERATOR_H
