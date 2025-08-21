#include "Player.h"
#include "Monster.h"

Player::Player(string nickname)
    : job_name("Unemployed"), nickname(nickname), level(1), HP(50), MP(30), power(10), defence(5), accuracy(80), speed(10) {}

void Player::printPlayerStatus() const 
{
    cout << "------------------------------------" << endl;
    cout << "* 현재 능력치" << endl;
    cout << "닉네임: " << nickname << endl;
    cout << "Lv. " << level << endl;
    cout << "HP: " << HP << endl;
    cout << "MP: " << MP << endl;
    cout << "공격력: " << power << endl;
    cout << "방어력: " << defence << endl;
    cout << "정확도: " << accuracy << endl;
    cout << "속도: " << speed << endl;
    cout << "------------------------------------" << endl;
}


string Player::getJobName()   const { return job_name; }
string Player::getNickname()  const { return nickname; }
int    Player::getLevel()     const { return level; }
int    Player::getHP()        const { return HP; }
int    Player::getMP()        const { return MP; }
int    Player::getPower()     const { return power; }
int    Player::getDefence()   const { return defence; }
int    Player::getAccuracy()  const { return accuracy; }
int    Player::getSpeed()     const { return speed; }


void Player::setNickname(string nickname) { this->nickname = nickname; }

bool Player::setHP(int HP) 
{
    if (HP > 0)
    { this->HP = HP; return true; }

    this->HP = 0; return false;
}

bool Player::setMP(int MP) 
{
    if (MP > 0) 
    { this->MP = MP; return true; }

    this->MP = 0; return false;
}
void Player::setPower(int power) { this->power = power; }
void Player::setDefence(int defence) { this->defence = defence; }
void Player::setAccuracy(int accuracy) { this->accuracy = accuracy; }
void Player::setSpeed(int speed) { this->speed = speed; }
