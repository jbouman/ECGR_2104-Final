#include "giant.h"

using namespace std;

//Giant Constructor
Giant::Giant(string name, int manaCost, int attack, int defense) : Card("Giant", 4, 300, 300);

string Giant::render(int line){
    switch(line){
        case 0: return ".___________.";
        case 1: return "| Giant     |";
        case 2: return "|   >   <   |";
        case 3: return "|   _____   |";
        case 4: return "|  /_|_|_\  |";
        case 5: return "|  \ | | /  |";
        case 6: return "|  500/200  |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}

