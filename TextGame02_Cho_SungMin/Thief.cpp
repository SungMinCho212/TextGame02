#include "Thief.h"
#include "Monster.h"
#include <iostream>
using namespace std;

Thief::Thief(string nickname) : Player(nickname) {
    job_name = "도적";
    level = 1;
    HP = 60; MP = 30;
    power = 16; defence = 8; accuracy = 92; speed = 14;
}

void Thief::attack() {
    cout << "* " << nickname << "이 단검을 찌른다!" << endl;
}

void Thief::attack(Monster* monster) {
    int base = power - monster->getDefence();
    if (base <= 0) base = 1;
    int perHit = base / 5;
    if (perHit <= 0) perHit = 1;

    cout << "* " << monster->getName() << "에게 연속 타격으로 " << perHit << "의 피해, 5회!" << endl;

    for (int i = 0; i < 5; ++i) {
        bool alive = monster->setHP(monster->getHP() - perHit);
        cout << "  -" << (i + 1) << "타 적중, 남은 HP: " << monster->getHP() << endl;
        if (!alive) {
            cout << nickname << "의 승리!" << endl;
            break;
        }
    }
}
