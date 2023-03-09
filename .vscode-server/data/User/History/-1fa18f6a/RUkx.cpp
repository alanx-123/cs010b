#include "Elf.h"

Elf::Elf(const string &name, double health, double attackDamage, const string &familyName ): Character(ELF, name, health, attackDamage){
    this-> familyName = familyName;
}
void Elf::attack(Character &enemy){
    double damageDone = (health / MAX_HEALTH) * attackStrength;

    if (enemy.getType() == ELF){
        Elf &opp = dynamic_cast<Warrior &> (enemy);

        if (opp.familyName != this -> familyName){
            
        }
    }
}