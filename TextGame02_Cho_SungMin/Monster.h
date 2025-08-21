#pragma once
#include <string>
#include <iostream>
using namespace std;

class Player; // ���� ����

class Monster {
public:
    Monster(string name);
    void attack(Player* player);

    // getter (��� const �߰�)
    string getName()   const;
    int    getHP()     const;
    int    getPower()  const;
    int    getDefence() const;
    int    getSpeed()  const;

    // setter
    void setName(string name);
    bool setHP(int HP); // ���� ���� ����
    void setPower(int power);
    void setDefence(int defence);
    void setSpeed(int speed);

protected:
    string name;
    int HP;
    int power;
    int defence;
    int speed;
};
