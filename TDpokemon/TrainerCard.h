//
// Created by victor murris on 13/11/2024.
//

#ifndef TRAINERCARD_H
#define TRAINERCARD_H


#include "Card.h"
#include <string>

class TrainerCard : public Card {
private:
    std::string trainerEffect;

public:
    TrainerCard(const std::string& name, const std::string& effect);
    void displayInfo() const override;
    std::string gettrainerEffect() const;
};



#endif //TRAINERCARD_H
