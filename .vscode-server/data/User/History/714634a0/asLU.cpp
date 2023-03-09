#include "Character.h"

HeroType type;
string name;
double health;
double attackStrength;

Character(HeroType, const string &, double, double);
HeroType getType() const;
const string & getName() const;
int getHealth() const;
void damage(double d);
bool isAlive() const;
virtual void attack(Character &) = 0;