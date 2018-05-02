#ifndef ROBOT_H
#define ROBOT_H
#include "card.h"

#include <iostream>

using namespace std;

class Robot : public Card {
	private:
		
	public:
	
	Robot(std::string, int, int, int); //Robot Constructor
	virtual string render(int);	
	

};

#endif
