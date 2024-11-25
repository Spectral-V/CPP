//
// Created by victor murris on 13/11/2024.
//

#ifndef PLAYER_H
#define PLAYER_H


#include <string>

#include "Card.h"
#include "PokemonCard.h"

/**
 * @class Player
 * @brief Represents a player in the game, managing bench cards and action cards.
 */
class Player {
 /**
  * @brief The name of the player.
  *
  * This variable stores the name of the player for identification purposes.
  */
private:
    std::string playerName;
 /**
  * @brief A collection of pointers to cards currently on the player's bench.
  *
  * The bench serves as a holding area for cards that are not actively in play.
  * This vector manages the cards that the player has prepared but not yet
  * activated in the game.
  */
 std::vector<Card*> benchCards;
 /**
  * A collection of pointers to PokemonCard objects that represent the action cards
  * available to a player. These action cards can be used by the player during the game
  * to perform various actions and strategies.
  */
 std::vector<PokemonCard*> actionCards;
 /**
  * @brief Constructs a Player object with the specified player name.
  *
  * This constructor initializes a Player object and sets the player's name.
  *
  * @param playerName The name of the player.
  *
  * @return A new instance of the Player class.
  */
public:
    Player(std::string playerName);

 /**
  * @brief Adds a card to the player's bench.
  *
  * This method places the given card into the player's bench,
  * making it available for future actions.
  *
  * @param card Pointer to the Card object to be added to the bench.
  */
 void addCardToBench(Card* card);

 /**
  * Activates a Pokémon card from the player's bench and moves it to the action card collection.
  *
  * @param index The index of the Pokémon card on the bench to be activated.
  */
 void activatePokemonCard(int index);

 /**
  * Attaches an energy card from the player's bench to an active action card.
  *
  * @param indexBench The index of the energy card on the bench to be attached.
  * @param indexAction The index of the action card to which the energy card will be attached.
  */
 void attachEnergyCard(int indexBench, int indexAction);

 /**
  * @brief Displays the current bench of cards for the player.
  *
  * This method outputs the list of bench cards for the player to the standard output.
  * For each card in the bench, its information is displayed using the card's displayInfo() method.
  */
 void displayBench();

 /**
  * @brief Display the action cards of the player.
  *
  * This method prints the action cards held by the player to the standard output.
  * It outputs the player's name followed by a list of action cards, with each card's
  * detailed information displayed by invoking their displayInfo() method.
  */
 void displayAction();

 /**
  * Executes an attack from one player's active Pokémon to an opponent's active Pokémon.
  *
  * @param indexAction The index of the attacking Pokémon in the current player's action cards.
  * @param indexAttack The index of the attack move to be used by the attacking Pokémon.
  * @param opponent The opponent player whose Pokémon will be attacked.
  * @param indexOpponentAction The index of the defending Pokémon in the opponent player's action cards.
  */
 void attack(int indexAction,int indexAttack, Player Opponent, int indexOpponentAction);

 /**
  * @brief Uses a trainer card from the player's bench.
  *
  * This function performs the action associated with the trainer card located at the specified index
  * in the player's bench. The function outputs the player's name and the trainer card's effect.
  * Additionally, it restores the HP of all the action cards to their maximum value.
  *
  * @param indexTrainer The index of the trainer card in the benchCards vector to be used.
  */
 void useTrainer(int indexTrainer);
};



#endif //PLAYER_H
