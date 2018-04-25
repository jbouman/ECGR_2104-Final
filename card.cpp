#include "card.h"

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

string getName(void){
	return name;
}

int getManaCost(void){
	return manaCost;
}
int getAttack(void){
	return attack;
}

int getDefense(void){
	return defense;
}

bool isExhausted(void){
	exhausted = true;
	return exhausted;
}

void unExhaust(bool){
	exhausted = false;
}
