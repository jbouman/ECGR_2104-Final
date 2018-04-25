#ifndef CARD_H
#define CARD_H

#include <iostream>

using namespace std;

class Card{
    private:
        string name;
        int manaCost;
        int attack;
        int defense;
        
        bool exhausted;
    
    public:
        /* Card Constructor
         * 
         * This constructor initializes the card object with a
         * name, mana cost, attack, and defense values.
         * This will be used by derived classes.
         */
        Card(string, int, int, int);
    
        /* Render
         *
         * This function is used to print the ASCII image
         * of the card, line by line. The line to print is
         * specified by the value passed to render.
         */
        virtual string render(int);
        

        // Accessors and Mutators
        virtual string getName(void);
        virtual int getManaCost(void);
        virtual int getAttack(void);
        virtual int getDefense(void);
        virtual bool isExhausted(void);
        virtual void unExhaust(void);
};

#endif
