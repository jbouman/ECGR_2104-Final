#ifndef GIANT_H
#define GIANT_H
#include "card.h"

#include <iostream>

using namespace std;

class Giant : public Card {
	private:
		
	public:
	
	Giant(std::string, int, int, int); //Giant Constructor
	virtual string render(int);	
	

};

#endif
