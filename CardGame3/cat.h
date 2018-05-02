#ifndef CAT_H
#define CAT_H
#include "card.h"

#include <iostream>

using namespace std;

class Cat : public Card {
	private:
		
	public:
	
	Cat(std::string, int, int, int); //Cat Constructor
	virtual string render(int);	
	

};

#endif
