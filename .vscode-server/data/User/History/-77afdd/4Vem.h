#ifndef WIZARD_H
#define WIZARD_H
#include "Character.h"

class Wizard: public Character{
    public:
        Wizard(const string &name, double health, double attackDamage, const int rank);
        virtual void attack(Character &enemy);
    private:
        string allegiance;
}



#endif