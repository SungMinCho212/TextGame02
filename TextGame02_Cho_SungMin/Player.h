#pragma once
#include <string>
#include <iostream>
using namespace std;

class Monster; // ���� ����

class Player {
public:
    Player(string nickname);

    // �߻� �������̽�
    virtual void attack() = 0;                 // ���⸦ �ֵθ��⸸ �ϴ� �⺻ ����
    virtual void attack(Monster* monster) = 0; // ���� ������� ����

    void printPlayerStatus() const;            // <-- const �߰�

    // getter (��� const �߰�)
    string getJobName()   const;
    string getNickname()  const;
    int    getLevel()     const;
    int    getHP()        const;
    int    getMP()        const;
    int    getPower()     const;
    int    getDefence()   const;
    int    getAccuracy()  const;
    int    getSpeed()     const;

    // setter (setHP, setMP�� ���� ���� ����)
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
