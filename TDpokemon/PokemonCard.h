//
// Created by victor murris on 13/11/2024.
//

#ifndef POKEMONCARD_H
#define POKEMONCARD_H

#include "Card.h"
#include <string>
#include <vector>
#include <tuple>

/**
 * @class PokemonCard
 * @brief Represents a Pokemon card in the game.
 *
 * A derived class from Card, PokemonCard includes additional attributes
 * specific to Pokemon such as type, family, evolution level, hit points (HP),
 * and attacks.
 */
class PokemonCard : public Card {
 /**
  * @brief Represents the type of the Pokémon on this card.
  *
  * The type is a string that specifies the Pokémon type, such as Fire, Water,
  * Grass, etc. It is used to classify the Pokémon and determine its strengths,
  * weaknesses, and abilities in comparison to other Pokémon types.
  */
private:
    std::string pokemonType;
 /**
  * @brief Represents the family to which the Pokémon belongs.
  */
 std::string familyName;
 /**
  * @brief Represents the evolution level of the Pokémon card.
  *
  * This integer indicates the stage of evolution of the Pokémon.
  * An evolution level of 0 typically represents a basic or first-stage Pokémon.
  * Higher numbers represent subsequent evolutions.
  */
 int evolutionLevel;
 /**
  * @brief The maximum health points (HP) of a Pokémon card.
  *
  * This variable represents the highest amount of health that the Pokémon can have.
  * It is initialized when a Pokémon card object is created and can be used to
  * determine when the Pokémon is at full health.
  */
 int maxHP;
 /**
  * @brief Represents the current hit points (HP) of the Pokémon card.
  *
  * This member variable stores the current health points of a Pokémon card
  * instance. It is initialized with the maximum HP value when the PokémonCard
  * object is created.
  */
 int hp;
 /**
  * @brief A collection of attacks available to a Pokémon card.
  *
  * This variable holds a list of tuples where each tuple represents an attack for the Pokémon card.
  * Each tuple consists of:
  *  - An integer representing the energy cost of the attack.
  *  - An integer representing the current energy stored for the attack.
  *  - A string describing the attack.
  *  - An integer indicating the damage that the attack can cause.
  */
 std::vector<std::tuple<int, int, std::string, int>> attacks;

 /**
  * @brief Constructs a PokemonCard object with the specified attributes and attacks.
  *
  * @param name The name of the Pokemon card.
  * @param type The type of the Pokemon.
  * @param family The family name of the Pokemon.
  * @param evoLevel The evolution level of the Pokemon.
  * @param max_hp The maximum hit points (HP) of the Pokemon.
  * @param energyCostAttack1 The energy cost for the first attack.
  * @param descAttack1 Description of the first attack.
  * @param damageAttack1 The damage value for the first attack.
  * @param energyCostAttack2 The energy cost for the second attack.
  * @param descAttack2 Description of the second attack.
  * @param damageAttack2 The damage value for the second attack.
  *
  * @return A new instance of the PokemonCard class.
  */
public:
    PokemonCard(const std::string& name, const std::string& type, const std::string& family, int evoLevel, int max_hp, int energyCostAttack1, const std::string& descAttack1, int damageAttack1, int energyCostAttack2, const std::string& descAttack2, int damageAttack2);

 /**
  * @brief Adds a new attack to the PokemonCard.
  *
  * This method appends an attack to the pokemon card's list of available attacks.
  *
  * @param energyCost The energy cost required to perform the attack.
  * @param currentEnergy The current energy available for the attack.
  * @param description A string description of the attack.
  * @param damage The damage value that the attack will inflict.
  */
 void addAttack(int energyCost, int currentEnergy, const std::string& description, int damage);

 /**
  * @brief Displays the detailed information of the Pokémon card.
  *
  * Outputs the following details to the console:
  * - Card name
  * - Pokémon type
  * - Evolution level
  * - Family name
  * - Current HP and maximum HP
  * - List of attacks with their properties, including:
  *   - Attack cost
  *   - Current energy storage
  *   - Description
  *   - Damage
  *
  * This method can be used to quickly see all relevant attributes of a Pokémon card.
  */
 void displayInfo() const override;

 /**
  * @brief Sets the HP (hit points) of the Pokémon card.
  *
  * This function updates the HP of the Pokémon card to the specified value.
  *
  * @param hp The new HP value to be set for the Pokémon card.
  */
 void setHP(int hp);

 /**
  * @brief Gets the current HP of the Pokémon card.
  *
  * This function returns the current hit points (HP) of the Pokémon
  * represented by this card. The HP denotes the remaining health of the Pokémon.
  *
  * @return The current HP value of the Pokémon card.
  */
 int getHP() const;

 /**
  * @brief Retrieves the maximum HP of the Pokemon card.
  *
  * This method returns the maximum hit points (HP)
  * that the Pokemon associated with this card can have.
  *
  * @return An integer representing the maximum HP of the Pokemon card.
  */
 int getMaxHP() const;

 /**
  * @brief Updates the current energy of all attacks for the Pokemon card.
  *
  * This method iterates through all the attacks of the Pokemon card and adds the specified
  * amount of additional energy to the current energy of each attack.
  *
  * @param additionalEnergy The amount of energy to be added to the current energy of each attack.
  */
 void updateCurrentEnergy(int additionalEnergy);

 /**
  * @brief Retrieve the name of the Pokemon card.
  *
  * This method returns the name of the Pokemon card
  * as a string. It overrides the getName function in
  * the base Card class.
  *
  * @return The name of the Pokemon card.
  */
 std::string getName() const;

 /**
  * @brief Retrieves the attack details of the Pokemon at the specified index.
  *
  * Each attack is represented as a tuple containing:
  * - Energy cost required for the attack.
  * - Current energy available for the attack.
  * - Description of the attack.
  * - Damage caused by the attack.
  *
  * @param index The index of the attack to retrieve.
  * @return A tuple containing the details of the attack:
  *         (energy cost, current energy, description, damage).
  */
 std::tuple<int, int, std::string, int> getattack(int index);

 /**
  * Gets the number of attacks available for the Pokémon card.
  *
  * @return The size of the attacks vector.
  */
 int getattacksize();
};




#endif //POKEMONCARD_H
