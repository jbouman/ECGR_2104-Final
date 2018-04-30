#include "robot.h"

using namespace std;

//Cat Constructor
Robot::Robot(string name, int manaCost, int attack, int defense) : Card("Robot", 3, 500, 200);

string Cat::render(int line){
    switch(line){
        case 0: return ".___________.";
        case 1: return "| Robot     |";
        case 2: return "|  < >  < > |";
        case 3: return "|   |____|  |";
        case 4: return "|  ( 0__0 ) |";
        case 5: return "|           |";
        case 6: return "|  500/200  |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}

