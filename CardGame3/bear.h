#ifndef BEAR_H
#define BEAR_H
#include "card.h"

#include <iostream>

using namespace std;

class Bear : public Card {
	private:
		
	public:
	
	Bear(std::string, int, int, int); //Bear Constructor
	virtual string render(int);	
	

};

#endif
