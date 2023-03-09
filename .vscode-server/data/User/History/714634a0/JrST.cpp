#include "Character.h"

HeroType type;
string name;
double health;
double attackStrength;

Character::Character(HeroType type, const string &name, double hp, double dmg): type(type), name(name), health (hp), attackStrength(dmg) {}
HeroType Character::getType() const{
    return type;
}
const string & Character::getName() const{
    return name;
}
int Character::getHealth() const{
    return static_cast<int>(health);
}
void Character::damage(double d){
    health -= d;
}
bool Character::isAlive() const{
    return (health > 0);
}