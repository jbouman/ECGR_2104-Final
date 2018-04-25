#ifndef CAT_H
#define CAT_H

#include <iostream>

using namespace std;

class Cat : public Card {
	private:
		
	public:
	
	Cat(void); //Cat Constructor
	virtual string render(int);	
};
