#include "elf.h"
#include <iostream>
#include <cmath>
#include "knight.h"
#include "robber.h"
#include "NPC.h"

Elf::Elf(int x, int y, const std::string& name) : NPC(ElfType, x, y, name) {}

Elf::Elf(std::istream& is) : NPC(ElfType, is) {}

void Elf::print() {
    std::cout << *this;
}

bool Elf::is_elf() const {
    return true;
}

bool Elf::fight(std::shared_ptr<Elf> other) {
    fight_notify(other, true); 
    return false;
}

bool Elf::fight(std::shared_ptr<Robber> other) {
    fight_notify(other, false);
    return false;
}

bool Elf::fight(std::shared_ptr<Knight> other) {
    fight_notify(other, true); 
    return true;
}

void Elf::save(std::ostream& os) {
    os << ElfType << std::endl;
    NPC::save(os);
}

std::ostream& operator<<(std::ostream& os, Elf& Elf) {
    os << "Elf: " << *static_cast<NPC*>(&Elf) << std::endl;
    return os;
}

bool Elf::accept(std::shared_ptr<NPC> attacker) {
    // Используем базовую логику из NPC
    return NPC::accept(attacker);
}