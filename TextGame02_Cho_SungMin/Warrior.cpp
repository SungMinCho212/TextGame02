#include "Warrior.h"
#include "Monster.h"
#include <iostream>
using namespace std;

Warrior::Warrior(string nickname) : Player(nickname) {
    job_name = "����";
    level = 1;
    HP = 80; MP = 20;
    power = 20; defence = 12; accuracy = 85; speed = 10;
}

void Warrior::attack() {
    cout << "* " << nickname << "�� Į�� ���� �ֵѷ���!" << endl;
}

void Warrior::attack(Monster* monster) {
    int raw = power - monster->getDefence();
    if (raw <= 0) raw = 1;

    cout << "* " << monster->getName() << "���� �˰����� " << raw << "�� ����!" << endl;

    bool alive = monster->setHP(monster->getHP() - raw);
    if (alive) {
        cout << monster->getName() << "�� ���� HP: " << monster->getHP() << endl;
    }
    else {
        cout << monster->getName() << "�� ���� HP: " << monster->getHP() << endl;
        cout << nickname << "�� �¸�!" << endl;
    }
}
