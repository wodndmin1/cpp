#include<iostream>
#include<string>
#include <cstdlib>
#include <ctime>
using namespace std;

#include "game.h"

GamblingGame::GamblingGame() {
    cout << "***** 갬블링 게임을 시작합니다. *****\n";
    srand(time(NULL));
}

void GamblingGame::nameS() {
    string name;
    cout << "첫번째 선수 이름>>";
    cin >> name;
    p[0].sName(name);
    cout << "두번째 선수 이름>>";
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
        n += "님 승리!!";
        return n;
    }
    else
        return "아쉽군요!";
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
        if (n == "님 승리!!") {
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
