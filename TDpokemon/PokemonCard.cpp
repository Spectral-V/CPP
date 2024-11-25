//
// Created by victor murris on 13/11/2024.
//

#include "PokemonCard.h"
#include <iostream>

/**
 * @brief Constructs a new PokemonCard with specified attributes and attacks.
 *
 * The constructor initializes a PokemonCard object, setting its name, type,
 * evolutionary level, maximum HP, and attack descriptors. It also invokes the base
 * class constructor for the Card name.
 *
 * @param name The name of the Pokémon.
 * @param type The type of the Pokémon (e.g., Fire, Water).
 * @param family The family or species name of the Pokémon.
 * @param evoLevel The evolution level of the Pokémon.
 * @param max_hp The maximum hit points (HP) of the Pokémon.
 * @param energyCostAttack1 The energy cost of the first attack.
 * @param descAttack1 The description of the first attack.
 * @param damageAttack1 The damage value of the first attack.
 * @param energyCostAttack2 The energy cost of the second attack.
 * @param descAttack2 The description of the second attack.
 * @param damageAttack2 The damage value of the second attack.
 */
PokemonCard::PokemonCard(const std::string& name, const std::string& type, const std::string& family, int evoLevel,
                         int max_hp, int energyCostAttack1, const std::string& descAttack1, int damageAttack1, int energyCostAttack2,
                         const std::string& descAttack2, int damageAttack2)
    : Card(name), pokemonType(type), familyName(family), evolutionLevel(evoLevel), maxHP(max_hp), hp(max_hp) {
    this->addAttack(energyCostAttack1, 0, descAttack1, damageAttack1);
    this->addAttack(energyCostAttack2, 0, descAttack2, damageAttack2);

}

/**
 * Adds a new attack to the Pokemon card.
 *
 * @param energyCost The energy cost required to perform the attack.
 * @param currentEnergy The current energy available to the Pokemon card.
 * @param description A description of the attack.
 * @param damage The damage points the attack can inflict.
 */
void PokemonCard::addAttack(int energyCost, int currentEnergy, const std::string& description, int damage) {
    attacks.emplace_back(energyCost, currentEnergy, description, damage);
}

/**
 * @brief Displays the information of a Pokémon card.
 *
 * This method prints to the console the following details of a Pokémon card:
 * - Name of the Pokémon.
 * - Type of the Pokémon.
 * - Evolution level within its family.
 * - Family name.
 * - Current and maximum Hit Points (HP).
 * - List of attacks, each showing:
 *   - Attack cost.
 *   - Current energy storage for the attack.
 *   - Description of the attack.
 *   - Damage caused by the attack.
 */
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

/**
 * Sets the hit points (HP) of the Pokémon card.
 *
 * @param hp An integer representing the hit points (HP) to set.
 */
void PokemonCard::setHP(int hp) {
    this->hp = hp;
}

/**
 * Retrieves the HP (Hit Points) of the Pokemon card.
 *
 * @return The current HP of the Pokemon card.
 */
int PokemonCard::getHP() const {
    return this->hp;
}

/**
 * Retrieves the maximum HP of the Pokemon card.
 *
 * @return The maximum HP of the Pokemon card.
 */
int PokemonCard::getMaxHP() const {
    return this->maxHP;
}

/**
 * Updates the current energy of each attack by adding the specified additional energy.
 *
 * @param additionalEnergy The amount of energy to add to the current energy of each attack.
 */
void PokemonCard::updateCurrentEnergy(int additionalEnergy) {
    for (auto& attack : attacks) {
        std::get<1>(attack) += additionalEnergy;
    }
}

/**
 * Retrieves the name of the Pokémon card.
 *
 * @return The name of the Pokémon card as a std::string.
 */
std::string PokemonCard::getName() const {
    return cardName;
}


/**
 * Fetches the attack details at a given index.
 *
 * @param index The index of the attack to retrieve in the attacks vector.
 * @return A tuple containing the attack's power, energy cost, type, and accuracy.
 */
std::tuple<int, int, std::string, int> PokemonCard::getattack(int index) {
    return attacks.at(index);
}

/**
 * Retrieves the number of attacks associated with this Pokemon card.
 *
 * @return The number of attacks.
 */
int PokemonCard::getattacksize() {
    return attacks.size();
}


