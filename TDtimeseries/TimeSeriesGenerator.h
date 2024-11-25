//
// Created by victor murris on 20/11/2024.
//

#ifndef TIMESERIESGENERATOR_H
#define TIMESERIESGENERATOR_H
#include <vector>


class TimeSeriesGenerator {
private:
    int seed;

public:
    TimeSeriesGenerator();
    TimeSeriesGenerator(int seed);
    virtual ~TimeSeriesGenerator();
    virtual std::vector<double> generateTimeSeries(int seed);
    static void printTimeSeries(const std::vector<double>& timeSeries);
};



#endif //TIMESERIESGENERATOR_H
