#include "Wizard.h"

Wizard::Wizard(const string &name, double health, double attackDamage, const int rank): Character(WIZARD, name, health, attackDamage){
    this -> rank = rank;
}
void Wizard::attack(Character &enemy){
    double damageDone;
    if (enemy.getType == WIZARD){
        Wizard &opp = dynamic_cast <Wizard &opp> (enemy);
        damageDone = attackStrength * (rank / opp.)
    }
    else{

    }
}