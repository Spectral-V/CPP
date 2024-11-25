//
// Created by victor murris on 20/11/2024.
//
#ifndef STEPGENERATOR_H
#define STEPGENERATOR_H

#include "TimeSeriesGenerator.h"
#include <vector>

/**
 * @class StepGenerator
 * @brief Class for generating step time series data.
 *
 * @details
 * This class inherits from the TimeSeriesGenerator class and
 * provides functionality to generate step time series.
 * It supports initialization with or without a seed value.
 */
class StepGenerator : public TimeSeriesGenerator {
 /**
  * @brief Constructs a new instance of StepGenerator class.
  *
  * This constructor initializes a StepGenerator object, which is a subclass of TimeSeriesGenerator.
  * It sets up the necessary base class initialization through its constructor.
  *
  * @return A new instance of StepGenerator.
  */
public:
    StepGenerator();

 /**
  * Constructs a StepGenerator object with a specified seed.
  *
  * @param seed The seed value used for random number generation.
  * @return A new instance of the StepGenerator class.
  */
 StepGenerator(int seed);

 /**
  * Generates a time series of the given size using a step function.
  * The values in the time series either stay the same or jump to a new random value between 0 and 100.
  *
  * @param size The number of elements in the generated time series.
  * @return A vector of doubles representing the generated time series.
  */
 std::vector<double> generateTimeSeries(int size) override;

 /**
  * Destructor for the StepGenerator class.
  *
  * Cleans up any resources allocated by the StepGenerator.
  */
 ~StepGenerator() {}
};

#endif // STEPGENERATOR_H
