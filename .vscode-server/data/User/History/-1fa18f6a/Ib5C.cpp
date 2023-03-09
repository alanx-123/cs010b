#include "Elf.h"

Elf::Elf(const string &name, double health, double attackDamage, const string &familyName ): Character(HeroType::ELF, name, health, attackDamage){
    this-> familyName = familyName;
}
void Elf::attack(Character &heroType){

}