//
// Created by victor murris on 20/11/2024.
//

#include "GaussianGenerator.h"
#include <cmath>
#include <random>
#include <cstdlib>

/**
 * @brief Default constructor for the GaussianGenerator class.
 *
 * Initializes a GaussianGenerator object with default mean of 0.0 and standard deviation of 1.0.
 * Inherits from TimeSeriesGenerator class.
 */
GaussianGenerator::GaussianGenerator() : TimeSeriesGenerator(), mean(0.0), std(1.0) {}

/**
 * @brief Constructs a GaussianGenerator object with specified parameters.
 *
 * @param seed The seed for the random number generator.
 * @param mean The mean (μ) of the Gaussian distribution.
 * @param std The standard deviation (σ) of the Gaussian distribution.
 *
 * @return A new instance of the GaussianGenerator class.
 */
GaussianGenerator::GaussianGenerator(int seed, double mean, double std)
    : TimeSeriesGenerator(seed), mean(mean), std(std) {}

/**
 * @brief Generates a Gaussian-distributed random number.
 *
 * This method uses the Box-Muller transform to generate a Gaussian random number
 * with the mean and standard deviation specified by the instance's mean and std members.
 * It generates pairs of Gaussian numbers at each call, saving the spare number for the next call.
 *
 * @return A Gaussian-distributed random number.
 */
double GaussianGenerator::generateGaussian() {
    static bool hasSpare = false;
    static double spare;
    if (hasSpare) {
        hasSpare = false;
        return mean + std * spare;
    }

    double u, v, s;
    do {
        u = 2.0 * rand() / RAND_MAX - 1.0;
        v = 2.0 * rand() / RAND_MAX - 1.0;
        s = u * u + v * v;
    } while (s >= 1.0 || s == 0.0);

    s = sqrt(-2.0 * log(s) / s);
    spare = v * s;
    hasSpare = true;
    return mean + std * u * s;
}

/**
 * @brief Generate a time series of specified size with Gaussian distributed values.
 *
 * The generated time series will contain values that follow the Gaussian
 * (normal) distribution with mean and standard deviation defined in the
 * GaussianGenerator instance.
 *
 * @param size The number of Gaussian distributed values to generate.
 * @return A vector containing `size` Gaussian distributed values.
 */
std::vector<double> GaussianGenerator::generateTimeSeries(int size) {
    std::vector<double> series;
    for (int i = 0; i < size; ++i) {
        series.push_back(generateGaussian());
    }
    return series;
}
