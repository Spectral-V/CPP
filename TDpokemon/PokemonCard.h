//
// Created by victor murris on 13/11/2024.
//

#ifndef POKEMONCARD_H
#define POKEMONCARD_H

#include "Card.h"
#include <string>
#include <vector>
#include <tuple>

class PokemonCard : public Card {
private:
    std::string pokemonType;
    std::string familyName;
    int evolutionLevel;
    int maxHP;
    int hp;
    std::vector<std::tuple<int, int, std::string, int>> attacks;

public:
    PokemonCard(const std::string& name, const std::string& type, const std::string& family, int evoLevel, int max_hp, int energyCostAttack1, const std::string& descAttack1, int damageAttack1, int energyCostAttack2, const std::string& descAttack2, int damageAttack2);
    void addAttack(int energyCost, int currentEnergy, const std::string& description, int damage);
    void displayInfo() const override;
    void setHP(int hp);
    int getHP() const;
    int getMaxHP() const;
    void updateCurrentEnergy(int additionalEnergy);
    std::string getName() const;
    std::tuple<int, int, std::string, int> getattack(int index);
    int getattacksize();
};




#endif //POKEMONCARD_H
