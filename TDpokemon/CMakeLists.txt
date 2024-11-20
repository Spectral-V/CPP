cmake_minimum_required(VERSION 3.29)
project(TDpokemon)

set(CMAKE_CXX_STANDARD 20)

add_executable(TDpokemon main.cpp
        Card.cpp
        Card.h
        PokemonCard.cpp
        PokemonCard.h
        EnergyCard.cpp
        EnergyCard.h
        TrainerCard.cpp
        TrainerCard.h
        Player.cpp
        Player.h)
