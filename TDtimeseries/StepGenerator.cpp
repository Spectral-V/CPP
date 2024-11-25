//
// Created by victor murris on 20/11/2024.
//

#include "StepGenerator.h"
#include <cstdlib> // for rand() et srand()

/**
 * @brief Constructs a new StepGenerator object.
 *
 * Initializes a new instance of the StepGenerator class, inheriting
 * from the TimeSeriesGenerator base class. This constructor does not
 * take any parameters and initializes any necessary base class components.
 *
 * @return A new instance of StepGenerator.
 */
StepGenerator::StepGenerator() : TimeSeriesGenerator() {}

/**
 * Constructs a StepGenerator object with the given seed.
 *
 * This constructor initializes the StepGenerator and seeds the random number generator
 * with the provided seed value.
 *
 * @param seed The seed value used to initialize the random number generator.
 * @return A StepGenerator object initialized with the specified seed.
 */
StepGenerator::StepGenerator(int seed) : TimeSeriesGenerator(seed) {
    srand(seed);
}

/**
 * Generates a time series of the specified size with step changes.
 *
 * @param size The number of elements in the generated time series. If the size is less than or equal to zero, an empty series is returned.
 * @return A vector of doubles representing the generated time series.
 */
std::vector<double> StepGenerator::generateTimeSeries(int size) {
    std::vector<double> series;
    if (size <= 0) return series;

    double currentValue = 0.0;
    series.push_back(currentValue);

    for (int i = 1; i < size; ++i) {
        if (rand() % 2 == 0) {
            currentValue = static_cast<double>(rand() % 101);
        }
        series.push_back(currentValue);
    }

    return series;
}
