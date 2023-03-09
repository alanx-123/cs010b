#ifndef ELF_H
#define ELF_H
#include "Character.h"

class Elf: public Character{
    public:
        Elf(string , double , double , const string & );
        virtual void attack(Character &heroType);
    private:
        string familyName;
};

#endif