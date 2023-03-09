#ifndef WARRIOR_H
#define WARRIOR_H
#include "Character.h"

class Warrior: public Character{
    public:
        Warrior(const string &name, double health, double attackDamage, const string &familyName );
        virtual void attack(Character &enemy);
    private:
        string allegiance;
};

#endif