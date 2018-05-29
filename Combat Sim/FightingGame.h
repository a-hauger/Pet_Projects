#ifndef FightingGame_h
#define FightingGame_h

#include<iostream>
#include<random>
#include<ctime>
#include<string>

using namespace std;

class FightingGame{
public:
    int attackResolution(string attacker, string defender, int defenderHealth, int attackerAttack, int defenderAttack);
};

#endif // FightingGame_h
