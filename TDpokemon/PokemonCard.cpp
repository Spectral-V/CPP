//
// Created by victor murris on 13/11/2024.
//

#include "PokemonCard.h"
#include <iostream>

PokemonCard::PokemonCard(const std::string& name, const std::string& type, const std::string& family, int evoLevel,
    int max_hp, int energyCostAttack1, const std::string& descAttack1, int damageAttack1, int energyCostAttack2,
    const std::string& descAttack2, int damageAttack2)
    : Card(name), pokemonType(type), familyName(family), evolutionLevel(evoLevel), maxHP(max_hp), hp(max_hp) {
    this->addAttack(energyCostAttack1, 0, descAttack1, damageAttack1);
    this->addAttack(energyCostAttack2, 0, descAttack2, damageAttack2);

}

void PokemonCard::addAttack(int energyCost, int currentEnergy, const std::string& description, int damage) {
    attacks.emplace_back(energyCost, currentEnergy, description, damage);
}

void PokemonCard::displayInfo() const {
    std::cout << "Pokemon Card - Name: " << cardName << ", Type: " << pokemonType
              << ", Evolution Level: " << evolutionLevel << " of the family " << familyName
    << ", HP: " << hp << "/" << maxHP << "\n" << "Attacks: ";
    int i=0;
    for (auto it = attacks.cbegin(); it != attacks.cend(); ++it) {
        std::cout << "\n Attack #" << i<< " \n Attack Cost: " << std::get < 0 > (*it)
        << "\n Attack current energy storage: " << std::get < 1 > (*it) << "\n Attack description: "
        << std::get < 2 > (*it) << "\n Attack damage: " << std::get < 3 > (*it) << "\n";
        i++;
    }
}

void PokemonCard::setHP(int hp) {
    this->hp = hp;
}
int PokemonCard::getHP() const {
    return this->hp;
}

int PokemonCard::getMaxHP() const {
    return this->maxHP;
}

void PokemonCard::updateCurrentEnergy(int additionalEnergy) {
    for (auto& attack : attacks) {
        std::get<1>(attack) += additionalEnergy;
    }
}

std::string PokemonCard::getName() const {
    return cardName;
}


std::tuple<int, int, std::string, int> PokemonCard::getattack(int index) {
    return attacks.at(index);
}

int PokemonCard::getattacksize() {
    return attacks.size();
}


