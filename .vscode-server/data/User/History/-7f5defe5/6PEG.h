#ifndef ELF_H
#define ELF_H
#include "Character.h"

class Elf: public Character{
    public:
        void attack(Character &heroType);
}

#endif