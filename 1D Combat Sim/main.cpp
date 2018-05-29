#include <iostream>
#include <string>
#include <random>
#include <ctime>

using namespace std;

int main(){
    int humans;
    int skeletons;
    int hStart;
    int sStart;
    int human_health = 100;
    int skeleton_health = 50;
    mt19937 randomGenerator(time(NULL));
    uniform_real_distribution<float> humanChance(0.0f, 1.0f);
    uniform_real_distribution<float> skeletonChance(0.0f, 1.0f);
    uniform_int_distribution<int> humanDamage(1, 20);
    uniform_int_distribution<int> skeletonDamage(1, 10);
    uniform_real_distribution<float> goesFirst(0.0f, 1.0f);

    cout<<"***SKELETONS VS HUMANS***\n"<< "How many humans will there be?\n";
    cin>>humans;
    cout<<"How many skeletons will there be?\n";
    cin>>skeletons;
    float whoGoesFirst = goesFirst(randomGenerator);
    hStart = humans;
    sStart = skeletons;
    if (.5f<=whoGoesFirst<=1.0f){
        //humans go first
        while(humans != 0 && skeletons != 0){
            float hStrike = humanChance(randomGenerator);
            float sStrike = skeletonChance(randomGenerator);
            if (hStrike <= .40f){
                int hDamage = humanDamage(randomGenerator);
                skeleton_health = skeleton_health - hDamage;
                if (skeleton_health <= 0){
                    skeletons--;
                    skeleton_health = 50;
                }
            } if (sStrike <= .30f){
                int sDamage = skeletonDamage(randomGenerator);
                human_health = human_health - sDamage;
                if (human_health <= 0){
                    humans--;
                    human_health = 100;
                }
            }
        }
    } else{
        //skeletons go first
        while(humans != 0 && skeletons != 0){
            float sStrike = skeletonChance(randomGenerator);
            float hStrike = humanChance(randomGenerator);
            if (sStrike <= .30f){
                int sDamage = skeletonDamage(randomGenerator);
                human_health = human_health - sDamage;
                if (human_health <=0){
                    humans--;
                    human_health = 100;
                }
            } if (hStrike <= .40f){
                int hDamage = humanDamage(randomGenerator);
                skeleton_health = skeleton_health - hDamage;
                if (skeleton_health <= 0){
                    skeletons--;
                    skeleton_health = 50;
                }
            }
        }
    }
    cout<<"The battle has been won!  Out of " << hStart << " humans and " << sStart << " skeletons, " << humans << " humans remain and " << skeletons << " skeletons remain!\n";
    if (humans == 0){
        cout<< "The skeletons win!\n";
    } else{
        cout<< "The humans win!\n";
    }
}
