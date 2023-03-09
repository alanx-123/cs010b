#include "Elf.h"

Elf::Elf(const string &name, double health, double attackDamage, const string &familyName ): Character(ELF, name, health, attackDamage){
    this-> familyName = familyName;
}
void Elf::attack(Character &enemy){
    double damageDone = (health / MAX_HEALTH) * attackStrength;

    if (enemy.getType() == ELF){
        Elf &opp = dynamic_cast<Elf &> (enemy);

        if (opp.familyName != this -> familyName){
            opp.damage(damageDone);
            cout << "Elf " << getName() << " shoots an arrow at " << opp.getName() << " --- TWANG!!" << endl;
        }
        else{
            cout << "Elf " << getName() << " does not attack Elf " << opp.getName() << "." << endl;
            cout << "They are both members of the " << familyName << " family." << endl;
        }
    }
    else{
        enemy.damage(damageDone);
        cout << "Elf " << getName() << " shoots an arrow at " << enemy.getName() << " -- TWANG!!" << endl;
        cout << enemy.getName() << " takes " << damageDone << " damage." << endl;
    }
}