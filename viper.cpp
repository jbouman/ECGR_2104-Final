#include "viper.h"

using namespace std;

//Cyclops Constructor
Viper::Viper(string name, int manaCost, int attack, int defense) : Card("Viper", 2, 300, 100);

string Viper::render(int line){
    switch(line){
        case 0: return ".___________.";
        case 1: return "| Viper     |";
        case 2: return "|    \ \    |";
        case 3: return "|    / /    |";
        case 4: return "|    \ \    |";
        case 5: return "|     SS    |";
        case 6: return "|  500/200  |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}

