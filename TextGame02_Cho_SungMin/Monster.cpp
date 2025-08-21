#include "Monster.h"
#include "Player.h"

Monster::Monster(string name)
    : name(name), HP(50), power(30), defence(10), speed(10) {
}

void Monster::attack(Player* player) {
    int damage = power - player->getDefence();
    if (damage <= 0) damage = 1;

    cout << "* " << name << "이(가) " << player->getNickname()
        << "에게 " << damage << "의 피해를 입혔다!" << endl;

    bool alive = player->setHP(player->getHP() - damage);
    if (alive) {
        cout << player->getNickname() << "의 남은 HP: " << player->getHP() << endl;
    }
    else {
        cout << player->getNickname() << "의 남은 HP: " << player->getHP() << endl;
        cout << name << "의 승리!" << endl;
    }
}

// getter들 const 일치
string Monster::getName()    const { return name; }
int    Monster::getHP()      const { return HP; }
int    Monster::getPower()   const { return power; }
int    Monster::getDefence() const { return defence; }
int    Monster::getSpeed()   const { return speed; }

// setter 그대로
void Monster::setName(string name) { this->name = name; }
bool Monster::setHP(int HP) {
    if (HP > 0) { this->HP = HP; return true; }
    this->HP = 0; return false;
}
void Monster::setPower(int power) { this->power = power; }
void Monster::setDefence(int defence) { this->defence = defence; }
void Monster::setSpeed(int speed) { this->speed = speed; }
