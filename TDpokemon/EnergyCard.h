//
// Created by victor murris on 13/11/2024.
//

#ifndef ENERGYCARD_H
#define ENERGYCARD_H



#include "Card.h"
#include <string>

/**
 * @class EnergyCard
 * @brief Represents an energy card.
 *
 * EnergyCard is a type of card that provides energy of a specific type
 * to other cards.
 */
class EnergyCard : public Card {
 /**
  * @brief Represents the type of energy associated with an EnergyCard.
  *
  * This variable stores a string detailing the specific type of energy
  * for an EnergyCard, a subclass of the Card class. It is set during
  * the instantiation of the EnergyCard object and can be retrieved
  * using the getEnergyType() method. It is utilized in the displayInfo()
  * method to provide information about the type of energy the card represents.
  */
private:
    std::string energyType;

 /**
  * @brief Constructs an EnergyCard object with the specified energy type.
  *
  * This constructor initializes the EnergyCard with a predefined type
  * by calling the parent class Card constructor with the name "Energy"
  * and setting the energyType member variable.
  *
  * @param type The type of energy associated with this EnergyCard.
  *
  * @return A new instance of the EnergyCard class.
  */
public:
    EnergyCard(const std::string& type);

 /**
  * @brief Display the information of the EnergyCard.
  *
  * This method outputs the type of the energy of the card to the standard output.
  * It overrides the pure virtual function displayInfo() from the base Card class.
  */
 void displayInfo() const override;

 /**
  * @brief Retrieves the type of energy associated with this EnergyCard.
  *
  * @return A string representing the type of energy.
  */
 std::string getEnergyType() const;
};



#endif //ENERGYCARD_H
