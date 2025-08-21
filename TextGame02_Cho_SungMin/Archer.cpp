#include "Archer.h"
#include "Monster.h"
#include <iostream>
using namespace std;

Archer::Archer(string nickname) : Player(nickname) 
{
    job_name = "궁수";
    level = 1;
    HP = 55; MP = 25;
    power = 18; defence = 7; accuracy = 88; speed = 13;
}

void Archer::attack()
{
    cout << "* " << nickname << "이 활을 쏠려고 자세를 잡았다!" << endl;
}

void Archer::attack(Monster* monster) 
{
    int base = power - monster->getDefence();
    if (base <= 0) base = 1;
    int perHit = base / 3;
    if (perHit <= 0) perHit = 1;

    cout << "* " << monster->getName() << "에게 화살로 " << perHit << "의 피해, 3회!" << endl;

    for (int i = 0; i < 3; ++i) 
    {
        bool alive = monster->setHP(monster->getHP() - perHit);
        cout << "  -" << (i + 1) << "발 적중, 남은 HP: " << monster->getHP() << endl;
        if (!alive) 
        {
            cout << nickname << "의 승리!" << endl;
            break;
        }
    }
}
