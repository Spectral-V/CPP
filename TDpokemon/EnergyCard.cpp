//
// Created by victor murris on 13/11/2024.
//

#include "EnergyCard.h"
#include <iostream>

/**
 * @brief Constructs a new EnergyCard object with the specified energy type.
 *
 * Initializes the EnergyCard with the given type and sets the card type to "Energy" in the base Card class.
 *
 * @param type The type of energy that this card represents.
 * @return An instance of the EnergyCard class.
 */
EnergyCard::EnergyCard(const std::string& type) : Card("Energy"), energyType(type) {}

/**
 * @brief Display information about the Energy Card.
 *
 * Outputs the type of the Energy Card to the standard output.
 */
void EnergyCard::displayInfo() const {
    std::cout << "Energy Card - Type: " << energyType << "\n";
}

/**
 * @brief Retrieves the type of energy the card represents.
 *
 * @return A string indicating the type of energy.
 */
std::string EnergyCard::getEnergyType() const {
    return energyType;
}
