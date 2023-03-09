#include "Warrior.h"




Warrior::Warrior(const string &name, double health, double attackDamage, const string &familyName ): Character(HeroType::WARRIOR, name, health, attackDamage){
    this-> familyName = familyName;
}