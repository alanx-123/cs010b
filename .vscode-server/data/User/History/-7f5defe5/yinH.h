#ifndef ELF_H
#define ELF_H
#include "Character.h"

class Elf: public Character{
    public:
        Elf(string elfName, double health, double attackDamage, string familyName );
        virtual void attack(Character &heroType);
    private:
        string familyName;
};

#endif