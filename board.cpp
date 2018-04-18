#include "board.h"

using namespace std;



void Board::shuffleDeck(void){
    Card * temp;
    int numOfShuffles = 100;
    int idx1, idx2;
    for(int i = 0; i < numOfShuffles; i++){
        idx1 = rand() % deck.size();
        idx2 = rand() % deck.size();
        temp = deck[idx1];
        deck[idx1] = deck[idx2];
        deck[idx2] = temp;
    }
}


void Board::renderMana(void){
    cout << "MANA: ";
    for(int i = 1; i <= maxMana; i++){
        if(i <= mana)
            cout << "@ ";
        else
            cout << "O ";
    }
        
    cout << endl;
}

void Board::renderHand(void){
    if(hand.size() > 0){
        for(int i = 0; i <= 7; i++){
            for(int j = 0; j < hand.size(); j++){
                cout << hand[j]->render(i) << " ";
            }
            cout << endl;
        }
    } else {
        for(int i = 0; i <= 7; i++)
            cout << endl;
    }
}

void Board::renderField(void){
    if(field.size() > 0){
        for(int i = 0; i <= 7; i++){
            for(int j = 0; j < field.size(); j++){
                cout << field[j]->render(i) << " ";
            }
            cout << endl;
        }
    } else {
        for(int i = 0; i <= 7; i++)
            cout << endl;
    }
}

void Board::Board(void){
	healthPoints = hp;	
}

void Board::addToDeckList(Card*){
	deck.push_back(Card*);
}

void Board::draw(int){
	for (int i = 0; i < int; i++){
		hand.push_back(deck[i]);
		deck.erase(deck.begin() + int);
	}
} 

void Board::playCardFromHand(int){
	field.push_back(hand[int]);
	hand.erase(hand.begin() + int);
	mana = mana - field[int].getManaCost();
	
}

Card* Board::getCardOnField(int){
	Card* fieldCard= field.at(int);
	return fieldCard;
}

Card* Board::getCardinHand(int){
	Card* handCard = hand.at(int);
	return handCard;
}


