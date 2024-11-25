//
// Created by victor murris on 20/11/2024.
//

#ifndef TIMESERIESDATASET_H
#define TIMESERIESDATASET_H

#include <vector>
#include <cmath>
#include <stdexcept>
#include <iostream>

/**
 * @class TimeSeriesDataset
 * @brief The TimeSeriesDataset class is used to store and manage a collection of time series data.
 *
 * This class supports operations for adding, retrieving, and normalizing time series data.
 */
class TimeSeriesDataset {
 /**
  * @brief Flag indicating whether z-normalization should be applied to time series data.
  *
  * When set to `true`, the time series data added to the dataset will be
  * z-normalized, which involves subtracting the mean and dividing by the
  * standard deviation of the data. This normalization ensures that the data
  * has a mean of zero and a standard deviation of one, which can help improve
  * the performance of certain machine learning algorithms.
  */
private:
    bool znormalize;
 /**
  * @brief Indicates whether the TimeSeriesDataset is used for training.
  *
  * If true, the dataset is being used in a training context where each time series
  * is associated with a label. If false, the dataset is used in a testing or
  * validation context where labels may not be required.
  */
 bool isTrain;
 /**
  * A two-dimensional vector to store time series data. Each inner vector
  * represents a single time series, and the outer vector holds multiple such
  * series. This structure is used to store and manage time series datasets
  * within the TimeSeriesDataset class.
  */
 std::vector<std::vector<double>> data;
 /**
  * @brief Stores the labels corresponding to each time series in the dataset.
  *
  * Each label is associated with a specific time series and is used for classification
  * or identification purposes within the dataset.
  */
 std::vector<int> labels;
 /**
  * @brief The maximum length of any time series in the dataset.
  *
  * This variable is used to track the longest time series added to the dataset.
  * It is updated whenever a new time series is added if the new series is
  * longer than the currently stored maximum length.
  */
 int maxLength;
 /**
  * @brief Stores the number of time series samples added to the dataset.
  *
  * This variable keeps track of the total number of time series samples
  * that have been added to the dataset, either with or without associated labels.
  */
 int numberOfSamples;


 /**
  * Normalizes the given time series using Z-normalization.
  * Z-normalization adjusts the values in the series so that they have a mean of zero and a standard deviation of one.
  *
  * @param series The time series to be normalized. The series is modified in place.
  */
 void zNormalizeSeries(std::vector<double>& series);

public:
 /**
  * Constructor for the TimeSeriesDataset class.
  *
  * @param znormalize If true, time series data will be z-normalized.
  * @param isTrain If true, the dataset is a training dataset; otherwise, it is a test dataset.
  * @return This method does not return a value.
  */
 TimeSeriesDataset(bool znormalize, bool isTrain);

 /**
  * Adds a time series and its associated label to the dataset. If z-normalization
  * is enabled, the time series will be normalized before being added. The dataset's
  * metadata, such as the number of samples and the maximum length of the series, will
  * be updated accordingly.
  *
  * @param series A vector of doubles representing the time series data to be added.
  * @param label An integer representing the label associated with the time series.
  */
 void addTimeSeries(const std::vector<double>& series, int label);

 /**
  * Adds a time series to the dataset.
  *
  * This method takes a vector of doubles representing a time series
  * and adds it to the dataset. If z-normalization is enabled, the time
  * series will be normalized before being added.
  *
  * @param series A vector of doubles representing the time series to be added.
  */
 void addTimeSeries(const std::vector<double>& series);

 /**
  * Retrieves the time series data stored in the dataset.
  *
  * @return A constant reference to a vector of vectors containing the time series data.
  */
 const std::vector<std::vector<double>>& getData() const;

 /**
  * Returns the labels associated with the time series data.
  *
  * @return A constant reference to a vector of integer labels.
  */
 const std::vector<int>& getLabels() const;

 /**
  * Prints the dataset to the standard output.
  *
  * This method iterates over each time series in the dataset and prints
  * its values. If the dataset is marked as a training dataset (`isTrain` is true),
  * it also prints the label associated with each time series.
  *
  * Each time series is printed on a new line, prefixed by its index in the dataset
  * (e.g., "Serie 1", "Serie 2", etc.). If the dataset is a training dataset,
  * the label is indicated after the series index (e.g., "(label: 3)").
  *
  * The printed format will be:
  *  - "Serie 1: value1 value2 value3 ..."
  *  - "Serie 2 (label: 3): value1 value2 value3 ..."
  */
 void printDataset() const;

 /**
  * Destructor for the TimeSeriesDataset class.
  *
  * This destructor is responsible for cleaning up any resources that were
  * allocated during the lifetime of the TimeSeriesDataset object. It is
  * automatically called when an instance of TimeSeriesDataset goes out of scope
  * or is explicitly deleted.
  */
 ~TimeSeriesDataset() {}
};

#endif // TIMESERIESDATASET_H

