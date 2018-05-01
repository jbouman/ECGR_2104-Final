#ifndef OGRE_H
#define OGRE_H
#include "card.h"

#include <iostream>

using namespace std;

class Ogre : public Card {
	private:
		
	public:
	
	Ogre(std::string, int, int, int); //Ogre Constructor || Smash Mouth plays everytime Ogre is played
	virtual string render(int);	
	

};

#endif
