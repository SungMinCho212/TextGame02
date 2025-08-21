#pragma once
#include "Player.h"

class Magician : public Player 
{
public:
    explicit Magician(string nickname);
    void attack() override;
    void attack(Monster* monster) override;
};
