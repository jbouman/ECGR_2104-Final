#include "cyclops.h"

using namespace std;

//Cyclops Constructor
Cyclops::Cyclops(string name, int manaCost, int attack, int defense) : Card("Cyclops", 5, 400, 400);

string Cyclops::render(int line){
    switch(line){
        case 0: return ".___________.";
        case 1: return "| Cyclops   |";
        case 2: return "|  ^_____^  |";
        case 3: return "|  (  O  )  |";
        case 4: return "| ( vvvvv ) |";
        case 5: return "|           |";
        case 6: return "|  500/200  |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}

