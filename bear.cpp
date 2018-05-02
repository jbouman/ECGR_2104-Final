#include "bear.h"

using namespace std;

//Bear Constructor
Bear::Bear(string name, int manaCost, int attack, int defense) : Card("Bear", 2, 200, 300){}


string Bear::render(int line){
    switch(line){
        case 0: return ".___________.";
        case 1: return "| Bear     2|";
        case 2: return "|  ^____^   |";
        case 3: return "| ( O  O )  |";
        case 4: return "| v(____)v  |";
        case 5: return "|   ||||    |";
        case 6: return "|  200/300  |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}

