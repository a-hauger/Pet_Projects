#include "FightingGame.h"

using namespace std;

//variables and random generators

int attackResolution(string attacker, string defender, int defenderHealth, int attackerAttack, int defenderAttack){
    mt19937 diceRoll(time(0));
    uniform_real_distribution<float> strikeChance(0.0f, 1.0f);
    uniform_real_distribution<float> critChance(0.0f, 1.0f);
    uniform_real_distribution<float> dodgeChance(0.0f, 1.0f);
    uniform_int_distribution<int> player2Attack(1, 4);
    uniform_int_distribution<int> highAttack(5, 15);
    uniform_int_distribution<int> highAttackCrit(13, 20);
    uniform_int_distribution<int> lowAttack(2, 10);
    uniform_int_distribution<int> lowAttackCrit(5, 13);

    float dodge = dodgeChance(diceRoll); //check victim dodge
    if (dodge > .80f){ //if dodged
        cout<<defender<<" dodged the attack!"<<endl;
        return defenderHealth;
    }
    else if (attackerAttack == 1 || attackerAttack == 2){ //if not dodged and attacker attacks
        float strike = strikeChance(diceRoll); //roll for attacker strike
        if (strike > .30f){ //if strike hits
            float crit = critChance(diceRoll); //roll for attacker crit chance
            if (crit >= .80f){ //if crit
                    cout<<attacker<< " got a critical hit!"<<endl;
                    if (attackerAttack == 1){ //if high attack
                        if (defenderAttack == 3){ //if high block
                            int damage = highAttackCrit(diceRoll)/8;
                            cout<<damage<<endl;
                            return defenderHealth - damage;
                        } else if (defenderAttack == 4){ //if low block
                            int damage = highAttackCrit(diceRoll)/2;
                            cout<<damage<<endl;
                            return defenderHealth - damage;
                        } else{ //if no block
                            int damage = highAttackCrit(diceRoll);
                            cout<<damage<<endl;
                            return defenderHealth - damage;
                        }
                    } else if (attackerAttack == 2){ //if low attack
                        if (defenderAttack == 4){ //if low block
                            int damage = lowAttackCrit(diceRoll)/4;
                            cout<<damage<<endl;
                            return defenderHealth - damage;
                        } else if (defenderAttack == 3){ //if high block
                            int damage = lowAttackCrit(diceRoll)/2;
                            cout<<damage<<endl;
                            return defenderHealth - damage;
                        } else{ // if no block
                            int damage = lowAttackCrit(diceRoll);
                            cout<<damage<<endl;
                            return defenderHealth - damage;
                        }
                    }
            } else if(crit < .80f){ //if no crit
                if (attackerAttack == 1){ //if high attack
                    if (defenderAttack == 3){ //if high block
                        int damage = highAttack(diceRoll)/4;
                        cout<<damage<<endl;
                        return defenderHealth - damage;
                    } else if (defenderAttack == 4){ //if low block
                        int damage = highAttack(diceRoll)/2;
                        cout<<damage<<endl;
                        return defenderHealth - damage;
                    } else{ //if no block
                        int damage = highAttack(diceRoll);
                        cout<<damage<<endl;
                        return defenderHealth - damage;
                    }
                } else if (attackerAttack == 2){ //if low attack
                    if (defenderAttack == 4){ //if low block
                        int damage = lowAttack(diceRoll)/4;
                        cout<<damage<<endl;
                        return defenderHealth - damage;
                    } else if (defenderAttack == 3){ //if high block
                        int damage = lowAttack(diceRoll)/2;
                        cout<<damage<<endl;
                        return defenderHealth - damage;
                    } else{ //if no block
                        int damage = lowAttack(diceRoll);
                        cout<<damage<<endl;
                        return defenderHealth - damage;
                    }
                }
            }
        }
    } else {return defenderHealth;} //if not dodged and if attacker blocks
}
