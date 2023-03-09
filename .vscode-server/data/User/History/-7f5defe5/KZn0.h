#ifndef ELF_H
#define ELF_H
#include "Character.h"

class Elf: public Character{
    public:
        Elf()
        void attack(Character &heroType);
}

#endif