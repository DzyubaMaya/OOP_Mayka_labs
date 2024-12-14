// Knight.h
#pragma once

#include "NPC.h"

struct Knight : public NPC {
    Knight(int x, int y, const std::string& name);
    Knight(std::istream& is);

    void print() override;

    bool is_knight() const override;

    bool accept(const std::shared_ptr<NPC>& attacker) override;

    bool fight(std::shared_ptr<Elf> other) override;
    bool fight(std::shared_ptr<Robber> other) override;
    bool fight(std::shared_ptr<Knight> other) override;

    void save(std::ostream& os) override;

    friend std::ostream& operator<<(std::ostream& os, Knight& Knight);

    ~Knight() = default;
};