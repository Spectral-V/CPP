#include <iostream>

#include "DistanceMetrics.h"
#include "GaussianGenerator.h"
#include "SinWaveGenerator.h"
#include "StepGenerator.h"
#include "TimeSeriesDataset.h"

int main() {
    GaussianGenerator generator(42, 0.0, 1.0); // Seed = 42, Moyenne = 0, Ecart-type = 1
    std::vector<double> series = generator.generateTimeSeries(10);

    std::cout << "Serie temporelle gaussienne générée : " << std::endl;
    TimeSeriesGenerator::printTimeSeries(series);

    StepGenerator generator2(42); // Graine aléatoire fixe pour reproductibilité
    std::vector<double> series2 = generator2.generateTimeSeries(10);

    std::cout << "Série temporelle de type 'Step' générée : " << std::endl;
    TimeSeriesGenerator::printTimeSeries(series2);

    SinWaveGenerator generator3(42, 2.0, 0.1, 0.0); // Amplitude = 2, Fréquence = 0.1, Phase = 0
    std::vector<double> series3 = generator3.generateTimeSeries(10);

    std::cout << "Série temporelle de type 'Sinus' générée : " << std::endl;
    TimeSeriesGenerator::printTimeSeries(series3);

    TimeSeriesDataset dataset(true, true);
    GaussianGenerator generator4(42, 0.0, 1.0);
    for (int i = 0; i < 3; ++i) {
        auto series4 = generator4.generateTimeSeries(10);
        dataset.addTimeSeries(series4, i % 2); // Alternance des labels 0 et 1
    }
    dataset.printDataset();

    // Exemple de deux séries temporelles
    std::vector<double> series5 = {1.0, 2.0, 3.0, 4.0, 5.0};
    std::vector<double> series6 = {2.0, 3.0, 4.0, 5.0, 6.0};

    try {
        // Calcul de la distance euclidienne
        double distance = DistanceMetrics::euclideanDistance(series5, series6);
        std::cout << "Distance euclidienne : " << distance << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }

    return 0;

    return 0;
}
