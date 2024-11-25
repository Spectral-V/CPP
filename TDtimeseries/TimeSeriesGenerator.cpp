//
// Created by victor murris on 20/11/2024.
//

#include "TimeSeriesGenerator.h"
#include <iostream>
#include <iomanip>


/**
 * @brief Default constructor for the TimeSeriesGenerator class.
 *
 * This constructor initializes a new instance of TimeSeriesGenerator with a default seed value of 0.
 *
 * @return A new instance of TimeSeriesGenerator with the default seed.
 */
TimeSeriesGenerator::TimeSeriesGenerator() : seed(0) {}


/**
 * Constructs a TimeSeriesGenerator with a specified seed.
 *
 * @param s The seed value used to initialize the random number generator.
 * @return An instance of TimeSeriesGenerator initialized with the given seed.
 */
TimeSeriesGenerator::TimeSeriesGenerator(int s) : seed(s) {}

/**
 * Prints the given time series to the standard output.
 * Each value in the series is printed with a precision of two decimal places.
 *
 * @param series A vector containing the time series data values to be printed.
 */
void TimeSeriesGenerator::printTimeSeries(const std::vector<double>& series) {
    for (const auto& value : series) {
        std::cout << std::fixed << std::setprecision(2) << value << " ";
    }
    std::cout << std::endl;
}


/**
 * Generates a time series based on the given seed.
 *
 * @param seed An integer used to initialize the random number generator
 *             for creating the time series.
 * @return A vector of doubles representing the generated time series.
 */
std::vector<double> TimeSeriesGenerator::generateTimeSeries(int) {
    return {};
}


/**
 * @brief Destructor for the TimeSeriesGenerator class.
 *
 * This method is responsible for cleaning up any resources that the
 * TimeSeriesGenerator instance may be holding onto. It is automatically
 * invoked when an object of this class goes out of scope or is explicitly deleted.
 */
TimeSeriesGenerator::~TimeSeriesGenerator() {}




