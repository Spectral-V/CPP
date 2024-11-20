//
// Created by victor murris on 13/11/2024.
//

#include "Player.h"

#include <iostream>

#include "EnergyCard.h"
#include "TrainerCard.h"

Player::Player(std::string playerName)
    : playerName(playerName) {}

void Player::addCardToBench(Card *card) {
    benchCards.push_back(card);
}

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


void Player::displayBench() {
    std::cout << "Bench cards for player " << playerName << " : "<< "\n";
    for (int i = 0; i < benchCards.size(); i++) {
        benchCards[i]->displayInfo();
    }
}

void Player::displayAction() {
    std::cout << "Action cards for player " << playerName << " : "<< "\n";
    for (int i = 0; i < actionCards.size(); i++) {
        actionCards[i]->displayInfo();
    }
}

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
