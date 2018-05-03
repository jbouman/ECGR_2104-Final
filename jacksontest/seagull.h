#ifndef SEAGULL_H
#define SEAGULL_H
#include "card.h"

#include <iostream>

using namespace std;

class Seagull : public Card {
	private:
		
	public:
	
	Seagull(std::string, int, int, int); //Bear Constructor
	virtual string render(int);	
	

};

#endif
