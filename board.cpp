#include "board.h"
#include <cstdlib>
#include <vector>

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
    //cout << "MANA: " << mana << " " << maxMana;
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

Board::Board(void){
	hp = 2000;	
}

void Board::addToDeckList(Card * C){
	
	deck.push_back(C);
}

void Board::draw(int j){
	for (int i = 0; i < j; i++){
		hand.push_back(deck[i]);
		deck.erase(deck.begin() + j);
	}
} 

void Board::playCardFromHand(int h){
	mana = getMana() - hand[h]->getManaCost(); //this is adding the value because it's negative for some reason
	field.push_back(hand[h]);
	hand.erase(hand.begin() + h);
}

Card* Board::getCardOnField(int l){
	Card* fieldCard= field.at(l);
	return fieldCard;
}

Card* Board::getCardInHand(int k){
	Card* handCard = hand[k];
	return handCard;
}

int Board::getHP(){
	return hp;
}

void Board::setHP(int o){
	hp = o;
}

int Board::getHandSize(){
	int vSize;
	vSize = hand.size();
	return vSize;
}

int Board::getFieldSize(){
	int fSize;
	fSize = field.size();
	return fSize;
}

int Board::getMana(){
	return mana;
}

void Board::setMana(int p){
	mana = p;
} 

void Board::discardCardFromField(int m){
	discard.push_back(field[m]);
	field.erase(field.begin() +  m);
}

void Board::unExhaustField(){
	for (int i = 0; i < field.size(); i++){
		field.at(i)->unExhaust();
	}
}

