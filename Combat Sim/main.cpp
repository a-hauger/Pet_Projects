#include<iostream>
#include<random>
#include<ctime>
#include<string>

using namespace std;

int attackResolution(string attacker, string defender, int defenderHealth, int attackerAttack, int defenderAttack);

int main(){

    int player1health = 100;
    int player2health = 100;
    int numPlayers;
    string player1;
    string player2;

    cout<< "How many players will be fighting?  1 or 2?" <<endl;
    cin>> numPlayers;
    if(numPlayers == 1){
        int p1Attack;
        mt19937 diceRoll(time(NULL));
        uniform_int_distribution<int> player2Attack(1, 4);
        cout<< "What is your name, fighter?" <<endl;
        cin>> player1;
        player2 = "Bruce Lee";
        while (player1health > 0 && player2health > 0){
            cout<<player1health<<endl<<player2health<<endl;
            cout << player1 << ", choose your attack!\n" << "1. High Attack\n" << "2. Low Attack\n" << "3. High Block\n" << "4. Low BLock\n";
            cin >> p1Attack;
            int p2Attack = player2Attack(diceRoll);
            player2health = attackResolution(player1, player2, player2health, p1Attack, p2Attack);
            player1health = attackResolution(player2, player1, player1health, p2Attack, p1Attack);
            cout<<player1health<<endl<<player2health<<endl;
        }
    } else {
        int p1Attack;
        int p2Attack;
        cout << "Fighter 1, what is your name?" << endl;
        cin >> player1;
        cout << "Fighter 2, what is your name?" << endl;
        cin >> player2;
        while (player1health > 0 && player2health > 0){
            cout<<player1health<<endl<<player2health<<endl;
            cout << player1 << ", choose your attack!\n" << "1. High Attack\n" << "2. Low Attack\n" << "3. High Block\n" << "4. Low BLock\n";
            cin >> p1Attack;
            cout << player2 << ", choose your attack!\n" << "7. High Attack\n" << "8. Low Attack\n" << "9. High Block\n" << "0. Low BLock\n";
            cin >> p2Attack;
            p2Attack = p2Attack - 6;
            player2health = attackResolution(player1, player2, player2health, p1Attack, p2Attack);
            player1health = attackResolution(player2, player1, player1health, p2Attack, p1Attack);
            cout<<player1health<<endl<<player2health<<endl;
        }
        if (player1health <= 0){
            cout<<player1<<" loses! "<<player2<<" is the winner!"<<endl;
        } else{
            cout<<player2<<" loses! "<<player1<<" is the winner!"<<endl;
        }
    }
}

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
