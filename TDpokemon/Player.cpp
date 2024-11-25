//
// Created by victor murris on 13/11/2024.
//

#include "Player.h"

#include <iostream>

#include "EnergyCard.h"
#include "TrainerCard.h"

/**
 * @brief Constructs a Player object with the specified player name.
 *
 * This constructor initializes a Player object and sets the player's name.
 *
 * @param playerName The name of the player.
 * @return A new instance of the Player class.
 */
Player::Player(std::string playerName)
    : playerName(playerName) {}

/**
 * @brief Adds a card to the player's bench.
 *
 * This method places the given card into the player's bench,
 * making it available for future actions.
 *
 * @param card Pointer to the Card object to be added to the bench.
 */
void Player::addCardToBench(Card *card) {
    benchCards.push_back(card);
}

/**
 * Activates a Pokémon card from the player's bench and moves it to the action card collection.
 *
 * @param index The index of the Pokémon card on the bench to be activated.
 */
void Player::activatePokemonCard(int index) {
    if (dynamic_cast<PokemonCard *> (benchCards[index]) != nullptr) {
        actionCards.push_back( dynamic_cast<PokemonCard *> (benchCards[index]) );
        benchCards.erase(benchCards.begin() + index);
        std::cout << playerName << " is activating a Pokemon Card : " << actionCards[0]->getName() << "\n";
    }
    else {
        std::cout << "Problem is not a Pokemon Card : " << playerName << "\n";
    }

}

/**
 * Attach an EnergyCard from the player's bench to a Pokémon card in actionCards.
 *
 * @param indexBench The index of the EnergyCard in benchCards that will be attached.
 * @param indexAction The index of the Pokémon card in actionCards to which the EnergyCard will be attached.
 */
void Player::attachEnergyCard(int indexBench, int indexAction) {
    // Check if the card at the specified index in benchCards is an EnergyCard
    EnergyCard* energyCard = dynamic_cast<EnergyCard*>(benchCards[indexBench]);
    if (energyCard != nullptr) {
        // Select the action card to which we want to attach the energy
        PokemonCard* actionCard = dynamic_cast<PokemonCard*>(actionCards.at(indexAction));
        if (actionCard != nullptr) {
            actionCard->updateCurrentEnergy(1); // Update the current energy of the action card
            benchCards.erase(benchCards.begin() + indexBench); // Remove the energy card from benchCards

            std::cout << playerName << " is attaching Energy card of type " << energyCard->getEnergyType()
            << " to the pokemon " << actionCard->getName() << "\n";
        }

        else {
            std::cout << "The action card at index " << indexAction << " is not a Pokémon card: " << playerName << "\n";
        }
    } else {
        std::cout << "The card at index " << indexBench << " is not an energy card: " << playerName << "\n";
    }
}


/**
 * @brief Displays the current bench of cards for the player.
 *
 * This method outputs the list of bench cards for the player to the standard output.
 * For each card in the bench, its information is displayed using the card's displayInfo() method.
 */
void Player::displayBench() {
    std::cout << "Bench cards for player " << playerName << " : "<< "\n";
    for (int i = 0; i < benchCards.size(); i++) {
        benchCards[i]->displayInfo();
    }
}

/**
 * @brief Display the action cards of the player.
 *
 * This method prints the action cards held by the player to the standard output.
 * It outputs the player's name followed by a list of action cards, with each card's
 * detailed information displayed by invoking their displayInfo() method.
 */
void Player::displayAction() {
    std::cout << "Action cards for player " << playerName << " : "<< "\n";
    for (int i = 0; i < actionCards.size(); i++) {
        actionCards[i]->displayInfo();
    }
}

/**
 * Executes an attack from the current player's action card to an opponent's action card.
 *
 * @param indexAction Index of the action card of the current player that initiates the attack.
 * @param indexAttack Index of the specific attack within the chosen action card.
 * @param opponent The opponent player who will be attacked.
 * @param indexOpponentAction Index of the action card of the opponent that will be targeted.
 */
void Player::attack(int indexAction, int indexAttack, Player opponent, int indexOpponentAction) {
    switch (actionCards.at(indexAction)->getattacksize()) {
        case 0:
            std::cout << "No attack exist." << "\n";
        case 1:
            std::cout << "Only " << actionCards.at(indexAction)->getattacksize() << " attack exist." << "\n";
        case 2:
            std::cout << "Only " << actionCards.at(indexAction)->getattacksize() << " attacks exist." << "\n";
    }

    std::cout << playerName << " attacking " << opponent.playerName << "'s Pokemon "
    << opponent.actionCards[indexOpponentAction]->getName()
    << " with the Pokemon " << actionCards[indexAction]->getName() << " with its attack: "
    << std::get < 2 > (actionCards[indexAction]->getattack(indexAttack)) << "\n";

    std::cout << "Reducing " << std::get < 3 > (actionCards[indexAction]->getattack(indexAttack)) << " from "
    << opponent.playerName << "'s Pokemon's HP " << "\n";


    int attackdamage = std::get < 3 > (actionCards[indexAction]->getattack(indexAttack));
    int opponentHP = opponent.actionCards.at(indexOpponentAction)->getHP();
    opponent.actionCards.at(indexOpponentAction)->setHP(opponentHP - attackdamage);


    if (opponent.actionCards.at(indexOpponentAction)->getHP() > 0) {
        std::cout << "Pokemon " << opponent.actionCards[indexOpponentAction]->getName() << " is still alive";
    }
    else {
        std::cout << "Pokemon " << opponent.playerName << " is KO";
    }

}

/**
 * @brief Uses a trainer card from the player's bench.
 *
 * This function performs the action associated with the trainer card located at the specified index
 * in the player's bench. The function outputs the player's name and the trainer card's effect.
 * Additionally, it restores the HP of all the action cards to their maximum value.
 *
 * @param indexTrainer The index of the trainer card in the benchCards vector to be used.
 */
void Player::useTrainer(int indexTrainer) {
    TrainerCard* trainerCard = dynamic_cast<TrainerCard*>(benchCards[indexTrainer]);
    if (trainerCard != nullptr) {
        std::cout << playerName << " is using the Trainer Card to " << "\""<<trainerCard->gettrainerEffect()<<"\"";
        for (size_t i = 0; i < actionCards.size(); ++i) {
            int maxHP = actionCards[i]->getHP();
            actionCards.at(i)->setHP(maxHP);
        }
    }
}
