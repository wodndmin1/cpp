#include<iostream>
#include<string>
#include <cstdlib>
#include <ctime>
using namespace std;

#include "game.h"

GamblingGame::GamblingGame() {
    cout << "***** ���� ������ �����մϴ�. *****\n";
    srand(time(NULL));
}

void GamblingGame::nameS() {
    string name;
    cout << "ù��° ���� �̸�>>";
    cin >> name;
    p[0].sName(name);
    cout << "�ι�° ���� �̸�>>";
    cin >> name;
    p[1].sName(name);
}

string GamblingGame::ranNum(string n) {
    int a[3];
    cout << "\t\t";
    for (int i = 0; i < 3; i++) {
        a[i] = rand() % 3;
        cout << a[i] << "\t";
    }
    if (a[0] == a[1] && a[0] == a[2]) {
        n += "�� �¸�!!";
        return n;
    }
    else
        return "�ƽ�����!";
}

void GamblingGame::rGame() {
    string n;
    int i = 0;
    while (true) {
        string m;
        cout << p[i % 2].gName() << ":\n";
        getline(cin, n);
        m = p[i % 2].gName();
        n = ranNum(n);
        if (n == "�� �¸�!!") {
            cout << m + n;
            break;
        }
        else
            cout << n << endl;
        i++;
    }
}

void Player::sName(string n) {
    name = n;
}
