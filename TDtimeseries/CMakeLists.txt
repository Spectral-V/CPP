cmake_minimum_required(VERSION 3.29)
project(TDtimeseries)

set(CMAKE_CXX_STANDARD 20)

add_executable(TDtimeseries main.cpp
        TimeSeriesGenerator.cpp
        TimeSeriesGenerator.h
        GaussianGenerator.cpp
        GaussianGenerator.h
        StepGenerator.cpp
        StepGenerator.h
        SinWaveGenerator.cpp
        SinWaveGenerator.h
        TimeSeriesDataset.cpp
        TimeSeriesDataset.h
        DistanceMetrics.cpp
        DistanceMetrics.h
        KNN.cpp
        KNN.h)
