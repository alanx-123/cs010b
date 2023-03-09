#include "Wizard.h"

Wizard::Wizard(const string &name, double health, double attackDamage, const int rank): Character(WIZARD, name, health, attackDamage){
    this -> rank = rank;
}
Wizard::virtual void attack(Character &enemy){
    
}