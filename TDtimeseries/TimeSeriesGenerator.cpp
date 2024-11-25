//
// Created by victor murris on 20/11/2024.
//

#include "TimeSeriesGenerator.h"
#include <iostream>
#include <iomanip> // Pour le formatage de la sortie

// Constructeur par défaut
TimeSeriesGenerator::TimeSeriesGenerator() : seed(0) {}

// Constructeur paramétré
TimeSeriesGenerator::TimeSeriesGenerator(int s) : seed(s) {}

// Méthode statique pour afficher une série temporelle
void TimeSeriesGenerator::printTimeSeries(const std::vector<double>& series) {
    for (const auto& value : series) {
        std::cout << std::fixed << std::setprecision(2) << value << " ";
    }
    std::cout << std::endl;
}

// Implémentation vide de la méthode virtuelle pure (nécessaire pour le linker)
std::vector<double> TimeSeriesGenerator::generateTimeSeries(int) {
    return {};
}

// Destructeur virtuel
TimeSeriesGenerator::~TimeSeriesGenerator() {}




