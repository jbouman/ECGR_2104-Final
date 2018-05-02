#include "goblin.h"
#include <cstdlib> //prob not necessary

using namespace std;

//Goblin constructor, may or may not be right
Goblin::Goblin(string name, int manaCost, int attack, int defense) : Card("Goblin", 1, 200, 100){}
string Goblin::render(int line){
    
    switch(line){
        case 0: return ".___________.";
        case 1: return "|Goblin     |";
        case 2: return "|   ^___^   |";
        case 3: return "|  ( . . )  |";
        case 4: return "|     v     |";
        case 5: return "|           |";
        case 6: return "|  200/100  |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}
