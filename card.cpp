#include "card.h"
#include <cstdlib>

using namespace std;

string Card::render(int line){
    switch(line){
        case 0: return ".___________.";
        case 1: return "|           |";
        case 2: return "|           |";
        case 3: return "|           |";
        case 4: return "|           |";
        case 5: return "|           |";
        case 6: return "|           |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}
Card::Card(string name, int manaCost, int attack, int defense){}

string Card::getName(void){
	return name;
}

int Card::getManaCost(void){
	return manaCost;
}
int Card::getAttack(void){
	return attack;
}

int Card::getDefense(void){
	return defense;
}

bool Card::isExhausted(void){
	exhausted = true;
	return exhausted;
}

void Card::unExhaust(void){
	exhausted = false;
}