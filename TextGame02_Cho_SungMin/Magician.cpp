#include "Magician.h"
#include "Monster.h"
#include <iostream>
using namespace std;

Magician::Magician(string nickname) : Player(nickname) {
    job_name = "마법사";
    level = 1;
    HP = 50; MP = 60;
    power = 22; defence = 5; accuracy = 90; speed = 11;
}

void Magician::attack() {
    cout << "* " << nickname << "이 주문을 중얼거린다!" << endl;
}

void Magician::attack(Monster* monster) {
    int raw = power - monster->getDefence();
    if (raw <= 0) raw = 1;

    cout << "* " << monster->getName() << "에게 화염구로 " << raw << "의 피해!" << endl;

    bool alive = monster->setHP(monster->getHP() - raw);
    if (alive) {
        cout << monster->getName() << "의 남은 HP: " << monster->getHP() << endl;
    }
    else {
        cout << monster->getName() << "의 남은 HP: " << monster->getHP() << endl;
        cout << nickname << "의 승리!" << endl;
    }
}
