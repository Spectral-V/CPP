//
// Created by victor murris on 20/11/2024.
//
#include "TimeSeriesDataset.h"


/**
 * Constructor for the TimeSeriesDataset class.
 *
 * @param znormalize Indicates whether the time series should be z-normalized.
 * @param isTrain Indicates whether this dataset is a training dataset.
 * @return A new instance of TimeSeriesDataset.
 */
TimeSeriesDataset::TimeSeriesDataset(bool znormalize, bool isTrain)
    : znormalize(znormalize), isTrain(isTrain), maxLength(0), numberOfSamples(0) {}


/**
 * Normalizes the given time series using z-normalization.
 * The z-normalization process involves subtracting the mean of the series
 * and dividing by the standard deviation, resulting in a series with zero mean
 * and unit variance.
 *
 * @param series A reference to the time series to be normalized.
 *               The series is modified in place.
 * @throw std::runtime_error if the standard deviation of the series is zero.
 */
void TimeSeriesDataset::zNormalizeSeries(std::vector<double>& series) {
    double sum = 0.0, sumSq = 0.0;

    for (double value : series) {
        sum += value;
        sumSq += value * value;
    }

    double mean = sum / series.size();
    double variance = sumSq / series.size() - mean * mean;
    double stdDev = std::sqrt(variance);

    if (stdDev == 0) {
        throw std::runtime_error("Standard deviation is zero, cannot normalize series.");
    }

    for (double& value : series) {
        value = (value - mean) / stdDev;
    }
}

/**
 * Adds a time series to the dataset, optionally normalizing it, and assigns it a label.
 *
 * @param series The time series data to be added, represented as a vector of doubles.
 * @param label The label associated with the time series, used for classification purposes.
 */
void TimeSeriesDataset::addTimeSeries(const std::vector<double>& series, int label) {
    std::vector<double> seriesCopy = series;

    if (znormalize) {
        zNormalizeSeries(seriesCopy);
    }

    data.push_back(seriesCopy);
    labels.push_back(label);

    if (series.size() > static_cast<size_t>(maxLength)) {
        maxLength = series.size();
    }
    numberOfSamples++;
}

/**
 * Adds a time series to the dataset.
 *
 * @param series A vector of doubles representing the time series to be added.
 *               If znormalize is true, the series will be z-normalized before being added.
 */
void TimeSeriesDataset::addTimeSeries(const std::vector<double>& series) {
    std::vector<double> seriesCopy = series;

    if (znormalize) {
        zNormalizeSeries(seriesCopy);
    }

    data.push_back(seriesCopy);

    if (series.size() > static_cast<size_t>(maxLength)) {
        maxLength = series.size();
    }
    numberOfSamples++;
}

/**
 * Retrieves the time series data from the dataset.
 *
 * @return A constant reference to a vector of vectors, where each inner vector
 *         represents a time series.
 */
const std::vector<std::vector<double>>& TimeSeriesDataset::getData() const {
    return data;
}

/**
 * Retrieves the labels associated with the time series dataset.
 *
 * @return A constant reference to a vector of integers representing the labels.
 */
const std::vector<int>& TimeSeriesDataset::getLabels() const {
    return labels;
}

/**
 * Prints the time series dataset.
 *
 * For each series in the dataset, this method prints the series index and
 * the data points it contains. If the dataset is a training set, the label
 * associated with each series is also printed.
 */
void TimeSeriesDataset::printDataset() const {
    for (size_t i = 0; i < data.size(); ++i) {
        std::cout << "Série " << i + 1;
        if (isTrain) {
            std::cout << " (label: " << labels[i] << ")";
        }
        std::cout << ": ";
        for (double value : data[i]) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
}
