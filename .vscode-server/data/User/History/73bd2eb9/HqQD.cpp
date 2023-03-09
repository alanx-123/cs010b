#include "Warrior.h"
#include <iostream>


Warrior::Warrior(const string &name, double health, double attackDamage, const string &allegiance ): Character(WARRIOR, name, health, attackDamage){
    this-> allegiance = allegiance;
}
void Warrior::attack(Character &enemy){
    double damageDone = (health / MAX_HEALTH) * attackStrength;
    if (enemy.getType() == WARRIOR){
        Warrior &opp = dynamic_cast<Warrior &> (enemy);
        if (opp.allegiance == allegiance){
            cout << "Warrior " << name << " does not attack Warrior " << opp.getName() << "." << endl;
        }
        else{
            opp.damage(damageDone);
            cout << "Warrior " << name << " attacks " << opp.getName() << " --- SLASH!!" << endl;
        }
    }
    else{
        enemy.damage(damageDone);
        cout << "Warrior " << name << " attacks " << enemy.getName() << " --- SLASH!!" << endl;
        cout << enemy.getName() << " takes " << damageDone << " damage." << endl;
    }   
}