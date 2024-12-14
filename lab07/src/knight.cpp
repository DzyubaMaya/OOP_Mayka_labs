#include "knight.h"
#include <iostream>
#include <cmath>
#include "elf.h"
#include "robber.h"
#include "NPC.h"

Knight::Knight(int x, int y, const std::string& name) : NPC(KnightType, x, y, name) {}

Knight::Knight(std::istream& is) : NPC(KnightType, is) {}

void Knight::print() {
    std::cout << *this;
}

bool Knight::is_knight() const {
    return true;
}

bool Knight::fight(std::shared_ptr<Elf> other) {
    fight_notify(other, true); 
    return true;
}

bool Knight::fight(std::shared_ptr<Robber> other) {
    fight_notify(other, false);
    return false;
}

bool Knight::fight(std::shared_ptr<Knight> other) {
    fight_notify(other, false); 
    return false;
}

void Knight::save(std::ostream& os) {
    os << KnightType << std::endl;
    NPC::save(os);
}

std::ostream& operator<<(std::ostream& os, Knight& Knight) {
    os << "Knight: " << *static_cast<NPC*>(&Knight) << std::endl;
    return os;
}

bool Knight::accept(std::shared_ptr<NPC> attacker) {
    // Используем базовую логику из NPC
    return NPC::accept(attacker);
}