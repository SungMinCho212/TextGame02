#pragma once
#include "Player.h"

class Thief : public Player {
public:
    explicit Thief(string nickname);
    void attack() override;
    void attack(Monster* monster) override;
};
