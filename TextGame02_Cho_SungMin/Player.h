#pragma once
#include <string>
#include <iostream>
using namespace std;

class Monster; // 전방 선언

class Player {
public:
    Player(string nickname);

    // 추상 인터페이스
    virtual void attack() = 0;                 // 무기를 휘두르기만 하는 기본 공격
    virtual void attack(Monster* monster) = 0; // 몬스터 대상으로 공격

    void printPlayerStatus() const;            // <-- const 추가

    // getter (모두 const 추가)
    string getJobName()   const;
    string getNickname()  const;
    int    getLevel()     const;
    int    getHP()        const;
    int    getMP()        const;
    int    getPower()     const;
    int    getDefence()   const;
    int    getAccuracy()  const;
    int    getSpeed()     const;

    // setter (setHP, setMP는 생존 여부 리턴)
    void setNickname(string nickname);
    bool setHP(int HP);
    bool setMP(int MP);
    void setPower(int power);
    void setDefence(int defence);
    void setAccuracy(int accuracy);
    void setSpeed(int speed);

protected:
    string job_name;
    string nickname;
    int level;
    int HP;
    int MP;
    int power;
    int defence;
    int accuracy;
    int speed;
};
