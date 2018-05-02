#ifndef GOBLIN_H
#define GOBLIN_H

#include <iostream>
#include "card.h"

using namespace std;

class Goblin : public Card {
    private:
    
    public:
    Goblin(string, int, int, int);
    Goblin(void);
    virtual string render(int);
    //virtual void Card::setManaCost(int);
};

#endif
