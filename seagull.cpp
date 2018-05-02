#include "seagull.h"

using namespace std;

//seagull Constructor
Seagull::Seagull(string name, int manaCost, int attack, int defense) : Card("Seagull", 1, 100, 100){}


string Seagull::render(int line){
    switch(line){
        case 0: return ".___________.";
        case 1: return "| Seagull   |";
        case 2: return "|     ^     |";
        case 3: return "|  //| |\\\\  |";
        case 4: return "| // | | \\\\ |";
        case 5: return "|           |";
        case 6: return "|  100/100  |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}

