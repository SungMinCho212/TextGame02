#include "Archer.h"
#include "Monster.h"
#include <iostream>
using namespace std;

Archer::Archer(string nickname) : Player(nickname) 
{
    job_name = "�ü�";
    level = 1;
    HP = 55; MP = 25;
    power = 18; defence = 7; accuracy = 88; speed = 13;
}

void Archer::attack()
{
    cout << "* " << nickname << "�� Ȱ�� ����� �ڼ��� ��Ҵ�!" << endl;
}

void Archer::attack(Monster* monster) 
{
    int base = power - monster->getDefence();
    if (base <= 0) base = 1;
    int perHit = base / 3;
    if (perHit <= 0) perHit = 1;

    cout << "* " << monster->getName() << "���� ȭ��� " << perHit << "�� ����, 3ȸ!" << endl;

    for (int i = 0; i < 3; ++i) 
    {
        bool alive = monster->setHP(monster->getHP() - perHit);
        cout << "  -" << (i + 1) << "�� ����, ���� HP: " << monster->getHP() << endl;
        if (!alive) 
        {
            cout << nickname << "�� �¸�!" << endl;
            break;
        }
    }
}
