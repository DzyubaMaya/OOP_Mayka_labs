#include "robber.h"
#include <iostream>
#include <cmath>
#include "elf.h"
#include "knight.h"
#include "NPC.h"

Robber::Robber(int x, int y, const std::string& name) : NPC(RobberType, x, y, name) {}

Robber::Robber(std::istream& is) : NPC(RobberType, is) {}

void Robber::print() {
    std::cout << *this;
}

bool Robber::is_robber() const {
    return true;
}

bool Robber::fight(std::shared_ptr<Elf> other) {
    fight_notify(other, true); 
    return false;
}

bool Robber::fight(std::shared_ptr<Robber> other) {
    fight_notify(other, false);
    return false;
}

bool Robber::fight(std::shared_ptr<Knight> other) {
    fight_notify(other, true); 
    return true;
}

void Robber::save(std::ostream& os) {
    os << RobberType << std::endl;
    NPC::save(os);
}

std::ostream& operator<<(std::ostream& os, Robber& Robber) {
    os << "Robber: " << *static_cast<NPC*>(&Robber) << std::endl;
    return os;
}

bool Robber::accept(const std::shared_ptr<NPC>& attacker) {
    if (attacker->is_knight()) {
        return true;
    } else if (attacker->is_elf()) {
        return false;
    } else if (attacker->is_robber()) {
        return false;
    }
    return false;
}



