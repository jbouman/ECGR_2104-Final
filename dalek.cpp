#include "dalek.h"

using namespace std;

//Dalek Constructor
Dalek::Dalek(string name, int manaCost, int attack, int defense) : Card("Dalek", 5, 300, 700);

string Dalek::render(int line){
    switch(line){
        case 0: return ".___________.";
        case 1: return "| Dalek     |";
        case 2: return "|   ____    |";
        case 3: return "|  /  Ø \   |";
        case 4: return "| /      \  |";
        case 5: return "|           |";
        case 6: return "|  500/200  |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}

