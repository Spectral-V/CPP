//
// Created by victor murris on 20/11/2024.
//

#include "SinWaveGenerator.h"
#include <cmath> // for sin()


/**
 * @brief Constructs a SinWaveGenerator object.
 *
 * This constructor initializes a SinWaveGenerator object with default parameters:
 * - amplitude is set to 1.0
 * - frequency is set to 1.0
 * - phase is set to 0.0
 *
 * These parameters define a sinusoidal wave which can be used to generate a time series.
 *
 * @return A newly constructed SinWaveGenerator object with default parameter values.
 */
SinWaveGenerator::SinWaveGenerator()
    : TimeSeriesGenerator(), amplitude(1.0), frequency(1.0), phase(0.0) {}

/**
 * @brief Constructs a SinWaveGenerator object with the given parameters.
 *
 * @param seed An integer seed for the random number generator used in the base class.
 * @param amplitude A double value representing the amplitude of the sine wave.
 * @param frequency A double value representing the frequency of the sine wave.
 * @param phase A double value representing the initial phase of the sine wave.
 * @return An instance of SinWaveGenerator.
 */
SinWaveGenerator::SinWaveGenerator(int seed, double amplitude, double frequency, double phase)
    : TimeSeriesGenerator(seed), amplitude(amplitude), frequency(frequency), phase(phase) {}

/**
 * Generates a sine wave time series based on the amplitude, frequency,
 * and phase of the sine wave.
 *
 * @param size The number of data points in the time series.
 * @return A vector of doubles containing the sine wave time series.
 */
std::vector<double> SinWaveGenerator::generateTimeSeries(int size) {
    std::vector<double> series;
    if (size <= 0) return series;

    for (int i = 0; i < size; ++i) {
        double x = static_cast<double>(i);
        double value = amplitude * sin(frequency * x + phase);
        series.push_back(value);
    }

    return series;
}
