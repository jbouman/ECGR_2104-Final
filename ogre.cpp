#include "ogre.h"

using namespace std;

//Cat Constructor
Ogre::Ogre(string name, int manaCost, int attack, int defense) : Card("Ogre", 2, 300, 600);

string Cat::render(int line){
    switch(line){
        case 0: return ".___________.";
        case 1: return "| Ogre      |";
        case 2: return "|  < >  < > |";
        case 3: return "|   | __ |  |";
        case 4: return "|  ( Ü__Ü ) |";
        case 5: return "|           |";
        case 6: return "|  300/600  |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}

