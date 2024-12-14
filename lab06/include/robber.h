#pragma once
#include "../include/NPC.h"

struct Robber : public NPC {
    Robber(int x, int y, const std::string& name);
    Robber(std::istream& is);

    void print() override;

    bool is_robber() const override;

    bool accept(const std::shared_ptr<NPC>& attacker) override;

    bool fight(std::shared_ptr<Elf> other) override;
    bool fight(std::shared_ptr<Robber> other) override;
    bool fight(std::shared_ptr<Knight> other) override;

    void save(std::ostream& os) override;

    friend std::ostream& operator<<(std::ostream& os, Robber& Robber);

    ~Robber() = default;
};