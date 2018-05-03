#ifndef VIPER_H
#define VIPER_H
#include "card.h"

#include <iostream>

using namespace std;

class Viper : public Card {
	private:
		
	public:
	
	Viper(std::string, int, int, int); //Viper Constructor
	virtual string render(int);	
	

};

#endif
