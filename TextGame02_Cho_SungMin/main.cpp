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
    cout << "\n[����] "
        << p->getNickname() << " HP: " << p->getHP()
        << "  |  " << m.getName() << " HP: " << m.getHP() << "\n";
}

// ���ǵ�� ���� ����, �⺻ 5���� ���� ����
static void Battle(Player* player, Monster& monster, int rounds = 5) {
    cout << "\n���� ����: " << monster.getName() << " ����!\n";
    PrintHPBars(player, monster);

    // ���� ����
    for (int r = 1; r <= rounds; ++r) {
        cout << "\n=== ���� " << r << " ===\n";

        bool playerFirst = player->getSpeed() >= monster.getSpeed();
        // ������ 1
        if (playerFirst) {
            player->attack(&monster);
            if (monster.getHP() <= 0) { // ���� ����
                PrintHPBars(player, monster);
                cout << "\n���� ����: " << player->getNickname() << "�� �¸�!\n";
                return;
            }
        }
        else {
            monster.attack(player);
            if (player->getHP() <= 0) { // �÷��̾� ������
                PrintHPBars(player, monster);
                cout << "\n���� ����: " << monster.getName() << "�� �¸�!\n";
                return;
            }
        }

        // ������ 2
        if (playerFirst) {
            monster.attack(player);
            if (player->getHP() <= 0) {
                PrintHPBars(player, monster);
                cout << "\n���� ����: " << monster.getName() << "�� �¸�!\n";
                return;
            }
        }
        else {
            player->attack(&monster);
            if (monster.getHP() <= 0) {
                PrintHPBars(player, monster);
                cout << "\n���� ����: " << player->getNickname() << "�� �¸�!\n";
                return;
            }
        }

        // ���� ���� ��Ȳ
        PrintHPBars(player, monster);
    }

    cout << "\n���� ����: ���� ����(" << rounds << ")�� �������ϴ�.\n";
    if (player->getHP() > monster.getHP()) {
        cout << player->getNickname() << "��(��) �켼�մϴ�.\n";
    }
    else if (player->getHP() < monster.getHP()) {
        cout << monster.getName() << "��(��) �켼�մϴ�.\n";
    }
    else {
        cout << "���º��Դϴ�.\n";
    }
}


int main() {
    string jobs[] = { "����", "������", "����", "�ü�" };
    int job_choice = 0;
    string nickname;

    Player* player = nullptr;

    cout << "* �г����� �Է����ּ���: ";
    cin >> nickname;

    cout << "<���� �ý���>\n";
    cout << nickname << "��, ȯ���մϴ�!\n";
    cout << "* ���Ͻô� ������ �������ּ���.\n";

    for (int i = 0; i < 4; i++) {
        cout << (i + 1) << ". " << jobs[i] << '\n';
    }

    cout << "����: ";
    cin >> job_choice;

    switch (job_choice) {
    case 1: player = new Warrior(nickname);  break;
    case 2: player = new Magician(nickname); break;
    case 3: player = new Thief(nickname);    break;
    case 4: player = new Archer(nickname);   break;
    default:
        cout << "�߸��� �Է��Դϴ�.\n";
        return 1;
    }

    //���� �� �������ͽ� ���
    cout << "* " << player->getNickname() << "�� " << player->getJobName() << "���� �����ߴ�!" << '\n';
    player->printPlayerStatus();

    // ���� ���� Ȯ��
    if (!Confirm("��ó�� ���Ͱ� ��Ÿ�����ϴ�. �����Ͻðڽ��ϱ�?")) {
        cout << "������ ���߽��ϴ�. ������ ���ư��ϴ�.\n";
        delete player;
        return 0;
    }

    // ���� ���� (5����)
    Monster slime("������");
    Battle(player, slime, 5);

    delete player;
    return 0;
}
