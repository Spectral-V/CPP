//
// Created by victor murris on 13/11/2024.
//

#include "TrainerCard.h"

#include <iostream>

/**
 * @brief Constructs a TrainerCard object with the specified name and effect.
 *
 * Initializes a TrainerCard with a given name and effect, which is related to
 * the trainer's special action or ability provided by the card.
 *
 * @param name The name of the TrainerCard.
 * @param effect The effect or ability associated with the TrainerCard.
 * @return A new instance of the TrainerCard class.
 */
TrainerCard::TrainerCard(const std::string& name, const std::string& effect)
: Card(name), trainerEffect(effect) {}

/**
 * @brief Displays information about the trainer card.
 *
 * This method outputs the name of the trainer card and its effect
 * to the standard output. It overrides the pure virtual function
 * from the Card class to provide specific details related to the trainer card.
 */
void TrainerCard::displayInfo() const {
    std::cout << "Trainer Card - Name: " << cardName << ", Effect: " << trainerEffect << "\n";
}

/**
 * @brief Retrieves the effect description of the trainer card.
 *
 * This method provides access to the trainer card's special effect description,
 * which may describe abilities or actions facilitated by the card within the game.
 *
 * @return A string representing the trainer card's effect.
 */
std::string TrainerCard::gettrainerEffect() const {
    return trainerEffect;
}

