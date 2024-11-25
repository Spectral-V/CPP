//
// Created by victor murris on 20/11/2024.
//

#ifndef TIMESERIESGENERATOR_H
#define TIMESERIESGENERATOR_H
#include <vector>


/**
 * @class TimeSeriesGenerator
 * @brief A base class for generating time series data.
 *
 * The TimeSeriesGenerator class provides an interface for generating and printing time series data.
 * Derived classes should implement the generateTimeSeries method to produce specific types of time series.
 */
class TimeSeriesGenerator {
 /**
  * @brief Holds the initial seed value used for generating time series.
  *
  * This variable initializes the random number generator, providing
  * reproducibility for time series generation.
  */
private:
    int seed;

    /**
     * @brief Default constructor for the TimeSeriesGenerator class.
     *
     * Initializes a new instance of the TimeSeriesGenerator class with a default seed value of 0.
     *
     * @return A new instance of TimeSeriesGenerator.
     */
   public:
    TimeSeriesGenerator();

    /**
     * @brief Constructs a TimeSeriesGenerator with the specified seed.
     *
     * This constructor initializes the TimeSeriesGenerator instance using the provided seed value
     * to control the randomness of the generated time series.
     *
     * @param s The seed value used for initializing the random number generator.
     * @return A new instance of TimeSeriesGenerator initialized with the specified seed.
     */
    TimeSeriesGenerator(int seed);

    /**
     * @brief Destructor for the TimeSeriesGenerator class.
     *
     * Cleans up any resources allocated by the TimeSeriesGenerator instance.
     */
    virtual ~TimeSeriesGenerator();

    /**
     * Generates a time series based on a provided seed value.
     *
     * @param seed An integer seed value used to generate the time series.
     * @return A vector of doubles representing the generated time series.
     */
    virtual std::vector<double> generateTimeSeries(int seed);

    /**
     * Prints the given time series values to the standard output.
     *
     * @param series A vector containing the time series values to be printed.
     */
    static void printTimeSeries(const std::vector<double>& timeSeries);
};



#endif //TIMESERIESGENERATOR_H
