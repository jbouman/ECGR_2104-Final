#ifndef CYCLOPS_H
#define CYCLOPS_H
#include "card.h"

#include <iostream>

using namespace std;

class Cyclops : public Card {
	private:
		
	public:
	
	Cyclops(std::string, int, int, int); //Cyclops Constructor
	virtual string render(int);	
	

};

#endif
