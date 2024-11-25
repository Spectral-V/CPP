//
// Created by victor murris on 13/11/2024.
//

#ifndef TRAINERCARD_H
#define TRAINERCARD_H


#include "Card.h"
#include <string>

/**
 * @brief Represents a Trainer Card in the game.
 *
 * Trainer cards provide special effects that can be used during the game.
 * They are derived from the base Card class and include an additional trainer effect.
 */
class TrainerCard : public Card {
 /**
  * @brief Represents the effect of a trainer card.
  *
  * The trainerEffect string holds a description of the special effect
  * that the trainer card imparts when used in the game.
  */
private:
    std::string trainerEffect;

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
public:
    TrainerCard(const std::string& name, const std::string& effect);

 /**
  * @brief Displays information about the trainer card.
  *
  * This method outputs the name of the trainer card and its effect
  * to the standard output. It overrides the pure virtual function
  * from the Card class to provide specific details related to the trainer card.
  */
 void displayInfo() const override;

 /**
  * @brief Retrieves the effect description of the trainer card.
  *
  * @return A string representing the trainer card's effect.
  */
 std::string gettrainerEffect() const;
};



#endif //TRAINERCARD_H
