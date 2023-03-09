#include "Character.h"

HeroType type;
string name;
double health;
double attackStrength;

Character(HeroType type, const string &name, double hp, double dmg): type(type), name(name), health (hp), attackStrength(dmg) {}
HeroType getType() const{
    return type;
}
const string & getName() const{
    return name;
}
int getHealth() const{
    return health;
}
void damage(double d){
    
}
bool isAlive() const;
virtual void attack(Character &) = 0;