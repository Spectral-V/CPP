//
// Created by victor murris on 20/11/2024.
//

#ifndef GAUSSIANGENERATOR_H
#define GAUSSIANGENERATOR_H
#include "TimeSeriesGenerator.h"


/**
 * @brief A class to generate time series data based on Gaussian distribution.
 *
 * The GaussianGenerator class inherits from the TimeSeriesGenerator and provides
 * functionality to generate time series data where each point is drawn from a Gaussian (normal) distribution.
 */
class GaussianGenerator : public TimeSeriesGenerator{
 /**
  * @var mean
  * @brief Holds the mean value for the Gaussian distribution used in the GaussianGenerator class.
  */
private:
    int mean;
 /**
  * @brief Standard deviation parameter for the Gaussian distribution.
  */
 int std;
 /**
  * @brief Generates a Gaussian-distributed random number.
  *
  * This method uses the Box-Muller transform to generate a Gaussian random number
  * with the mean and standard deviation specified by the instance's mean and std members.
  * It generates pairs of Gaussian numbers at each call, saving the spare number for the next call.
  *
  * @return A Gaussian-distributed random number.
  */
 double generateGaussian();

public:
    /**
     * @brief Default constructor for the GaussianGenerator class.
     * Initializes a GaussianGenerator object with default mean of 0.0 and standard deviation of 1.0.
     * Inherits from TimeSeriesGenerator class.
     */
    GaussianGenerator();

    /**
     * Constructs a GaussianGenerator object with specified parameters.
     * @param seed The seed for the random number generator.
     * @param mean The mean (μ) of the Gaussian distribution.
     * @param std The standard deviation (σ) of the Gaussian distribution.
     */
    GaussianGenerator(int seed, double mean, double std);

 /**
  * Generate a time series of specified size with Gaussian distributed values.
  *
  * The generated time series will contain values that follow the Gaussian
  * (normal) distribution with mean and standard deviation defined in the
  * GaussianGenerator instance.
  *
  * @param size The number of Gaussian distributed values to generate.
  * @return A vector containing `size` Gaussian distributed values.
  */
 std::vector<double> generateTimeSeries(int size) override;

    /**
     * Virtual destructor for the GaussianGenerator class.
     * Ensures derived class destructors are called properly.
     */
    virtual ~GaussianGenerator() {}
};



#endif //GAUSSIANGENERATOR_H
