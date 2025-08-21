#include <iostream>
#include <string>
#include "Player.h"
#include "Warrior.h"
#include "Magician.h"
#include "Thief.h"
#include "Archer.h"
#include "Monster.h"
using namespace std;

static bool Confirm(const string& question) {
    cout << question << " (Y/N): ";
    char c;
    cin >> c;
    return c == 'Y' || c == 'y';
}

static void PrintHPBars(const Player* p, const Monster& m) {
    cout << "\n[상태] "
        << p->getNickname() << " HP: " << p->getHP()
        << "  |  " << m.getName() << " HP: " << m.getHP() << "\n";
}

// 스피드로 선공 결정, 기본 5라운드 교대 공격
static void Battle(Player* player, Monster& monster, int rounds = 5) {
    cout << "\n전투 시작: " << monster.getName() << " 등장!\n";
    PrintHPBars(player, monster);

    // 라운드 루프
    for (int r = 1; r <= rounds; ++r) {
        cout << "\n=== 라운드 " << r << " ===\n";

        bool playerFirst = player->getSpeed() >= monster.getSpeed();
        // 공격자 1
        if (playerFirst) {
            player->attack(&monster);
            if (monster.getHP() <= 0) { // 몬스터 격파
                PrintHPBars(player, monster);
                cout << "\n전투 종료: " << player->getNickname() << "의 승리!\n";
                return;
            }
        }
        else {
            monster.attack(player);
            if (player->getHP() <= 0) { // 플레이어 쓰러짐
                PrintHPBars(player, monster);
                cout << "\n전투 종료: " << monster.getName() << "의 승리!\n";
                return;
            }
        }

        // 공격자 2
        if (playerFirst) {
            monster.attack(player);
            if (player->getHP() <= 0) {
                PrintHPBars(player, monster);
                cout << "\n전투 종료: " << monster.getName() << "의 승리!\n";
                return;
            }
        }
        else {
            player->attack(&monster);
            if (monster.getHP() <= 0) {
                PrintHPBars(player, monster);
                cout << "\n전투 종료: " << player->getNickname() << "의 승리!\n";
                return;
            }
        }

        // 라운드 종료 현황
        PrintHPBars(player, monster);
    }

    cout << "\n전투 종료: 제한 라운드(" << rounds << ")가 끝났습니다.\n";
    if (player->getHP() > monster.getHP()) {
        cout << player->getNickname() << "이(가) 우세합니다.\n";
    }
    else if (player->getHP() < monster.getHP()) {
        cout << monster.getName() << "이(가) 우세합니다.\n";
    }
    else {
        cout << "무승부입니다.\n";
    }
}


int main() {
    string jobs[] = { "전사", "마법사", "도적", "궁수" };
    int job_choice = 0;
    string nickname;

    Player* player = nullptr;

    cout << "* 닉네임을 입력해주세요: ";
    cin >> nickname;

    cout << "<전직 시스템>\n";
    cout << nickname << "님, 환영합니다!\n";
    cout << "* 원하시는 직업을 선택해주세요.\n";

    for (int i = 0; i < 4; i++) {
        cout << (i + 1) << ". " << jobs[i] << '\n';
    }

    cout << "선택: ";
    cin >> job_choice;

    switch (job_choice) {
    case 1: player = new Warrior(nickname);  break;
    case 2: player = new Magician(nickname); break;
    case 3: player = new Thief(nickname);    break;
    case 4: player = new Archer(nickname);   break;
    default:
        cout << "잘못된 입력입니다.\n";
        return 1;
    }

    //전직 밑 스테이터스 출력
    cout << "* " << player->getNickname() << "은 " << player->getJobName() << "으로 전직했다!" << '\n';
    player->printPlayerStatus();

    // 전투 여부 확인
    if (!Confirm("근처에 몬스터가 나타났습니다. 전투하시겠습니까?")) {
        cout << "전투를 피했습니다. 마을로 돌아갑니다.\n";
        delete player;
        return 0;
    }

    // 전투 시작 (5라운드)
    Monster slime("슬라임");
    Battle(player, slime, 5);

    delete player;
    return 0;
}
