#include "Magician.h"
#include "Monster.h"
#include <iostream>
using namespace std;

Magician::Magician(string nickname) : Player(nickname) {
    job_name = "������";
    level = 1;
    HP = 50; MP = 60;
    power = 22; defence = 5; accuracy = 90; speed = 11;
}

void Magician::attack() {
    cout << "* " << nickname << "�� �ֹ��� �߾�Ÿ���!" << endl;
}

void Magician::attack(Monster* monster) {
    int raw = power - monster->getDefence();
    if (raw <= 0) raw = 1;

    cout << "* " << monster->getName() << "���� ȭ������ " << raw << "�� ����!" << endl;

    bool alive = monster->setHP(monster->getHP() - raw);
    if (alive) {
        cout << monster->getName() << "�� ���� HP: " << monster->getHP() << endl;
    }
    else {
        cout << monster->getName() << "�� ���� HP: " << monster->getHP() << endl;
        cout << nickname << "�� �¸�!" << endl;
    }
}
