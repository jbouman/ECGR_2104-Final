#ifndef DALEK_H
#define DALEK_H
#include "card.h"

#include <iostream>

using namespace std;

class Dalek : public Card {
	private:
		
	public:
	
	Dalek(std::string, int, int, int); //Dalek Constructor
	virtual string render(int);	
	

};

#endif
