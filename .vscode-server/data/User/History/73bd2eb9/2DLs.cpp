#include "Warrior.h"




Warrior::Warrior(const string &name, double health, double attackDamage, const string &allegiance ): Character(WARRIOR, name, health, attackDamage){
    this-> allegiance = allegiance;
}
virtual void attack(Character &enemy){
    double damageDone = (health / MAX_HEALTH) * attackStrength;
    if (enemy.getType() == WARRIOR){
        Warrior &opp = dynamic_cast<Warrior &> (enemy;)
    }   
}