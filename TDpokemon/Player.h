//
// Created by victor murris on 13/11/2024.
//

#ifndef PLAYER_H
#define PLAYER_H


#include <string>

#include "Card.h"
#include "PokemonCard.h"

class Player {
private:
    std::string playerName;
    std::vector<Card*> benchCards;
    std::vector<PokemonCard*> actionCards;
public:
    Player(std::string playerName);
    void addCardToBench(Card* card);
    void activatePokemonCard(int index);
    void attachEnergyCard(int indexBench, int indexAction);
    void displayBench();
    void displayAction();
    void attack(int indexAction,int indexAttack, Player Opponent, int indexOpponentAction);
    void useTrainer(int indexTrainer);
};



#endif //PLAYER_H
