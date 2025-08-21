#pragma once
#include "Player.h"

class Warrior : public Player {
public:
    explicit Warrior(string nickname);
    void attack() override;
    void attack(Monster* monster) override;
};
