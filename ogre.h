#ifndef OGRE_H
#define OGRE_H
#include "card.h"

#include <iostream>

using namespace std;

class Ogre : public Card {
	private:
		
	public:
	
	Ogre(std::string, int, int, int); //Cat Constructor
	virtual string render(int);	
	

};

#endif
