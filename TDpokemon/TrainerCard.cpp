//
// Created by victor murris on 13/11/2024.
//

#include "TrainerCard.h"

#include <iostream>

TrainerCard::TrainerCard(const std::string& name, const std::string& effect)
: Card(name), trainerEffect(effect) {}

void TrainerCard::displayInfo() const {
    std::cout << "Trainer Card - Name: " << cardName << ", Effect: " << trainerEffect << "\n";
}

std::string TrainerCard::gettrainerEffect() const {
    return trainerEffect;
}

