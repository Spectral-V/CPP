//
// Created by victor murris on 20/11/2024.
//

#include "TimeSeriesDataset.h"

// Constructeur
TimeSeriesDataset::TimeSeriesDataset(bool znormalize, bool isTrain)
    : znormalize(znormalize), isTrain(isTrain), maxLength(0), numberOfSamples(0) {}

// Méthode privée : normalisation Z d'une série temporelle
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

// Ajout d'une série temporelle et de son label
void TimeSeriesDataset::addTimeSeries(const std::vector<double>& series, int label) {
    std::vector<double> seriesCopy = series;

    // Normalisation Z si activée
    if (znormalize) {
        zNormalizeSeries(seriesCopy);
    }

    // Ajout au dataset
    data.push_back(seriesCopy);
    labels.push_back(label);

    // Mise à jour des métadonnées
    if (series.size() > static_cast<size_t>(maxLength)) {
        maxLength = series.size();
    }
    numberOfSamples++;
}

// Accesseurs
const std::vector<std::vector<double>>& TimeSeriesDataset::getData() const {
    return data;
}

const std::vector<int>& TimeSeriesDataset::getLabels() const {
    return labels;
}

// Affichage des séries et labels
void TimeSeriesDataset::printDataset() const {
    for (size_t i = 0; i < data.size(); ++i) {
        std::cout << "Série " << i + 1 << " (label: " << labels[i] << "): ";
        for (double value : data[i]) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
}

