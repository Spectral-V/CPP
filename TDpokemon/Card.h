//
// Created by victor murris on 13/11/2024.
//

#ifndef CARD_H
#define CARD_H

#include <string>

/**
 * @class Card
 * @brief Abstract base class representing a generic card.
 *
 * The Card class provides a common interface and shared functionality for all specific types of cards in the game.
 * It serves as the base class for various specific card types such as PokemonCard, EnergyCard, and TrainerCard.
 */
class Card {
 /**
  * @brief Represents the name of the card.
  */
protected:
    std::string cardName;

 /**
  * Constructs a Card object with the specified name.
  *
  * @param name The name of the card.
  * @return A new instance of the Card class.
  */
public:
    Card(const std::string& name);

    /**
     * Virtual destructor for the Card class.
     *
     * Ensures derived classes are properly destructed.
     */
    virtual ~Card() = default;

    /**
     * @brief Display the information of the card.
     *
     * This is a pure virtual function that must be implemented by any derived class.
     * It should output the detailed information of the card, such as the card's name,
     * type, attributes, and any other relevant data.
     */
    virtual void displayInfo() const = 0;
};



#endif //CARD_H
