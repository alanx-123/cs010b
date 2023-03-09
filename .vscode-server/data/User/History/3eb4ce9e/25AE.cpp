#include "Wizard.h"
#include <iostream>


Wizard::Wizard(const string &name, double health, double attackDamage, const int rank): Character(WIZARD, name, health, attackDamage){
    this -> rank = rank;
}
void Wizard::attack(Character &enemy){
    double damageDone;
    if (enemy.getType()== WIZARD){
        Wizard &opp = dynamic_cast <Wizard &> (enemy);
        damageDone = attackStrength * (1.0 * rank / opp.rank);
        opp.damage(damageDone);
        cout << "Wizard " << name << " attacks " << opp.getName() << " --- POOF!!" << endl;
        cout << opp.name << " takes " << damageDone << " damage." << endl;
    }
    else{
        damageDone = attackStrength;
        enemy.damage(damageDone);
        cout << "Wizard " << name << " attacks " << enemy.getName() << " --- POOF!!" << endl;
        cout << enemy.getName() << " takes " << damageDone << " damage." << endl;
    }
}