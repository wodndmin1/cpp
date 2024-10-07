#pragma once
#include<iostream>
using namespace std;

class Player {
    string name;
public:
    void sName(string name);
    string gName() { return name; };
};

class GamblingGame {
    Player* p = new Player[2];
public:
    GamblingGame();
    void nameS();
    string ranNum(string n);
    void rGame();
};
