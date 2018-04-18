#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <unistd.h>
#include <sstream>
#include <list>
#include <string>
#include <vector>
#include "board.h"
#include "goblin.h"
#include "card.h"

using namespace std;

void getOpponentAction(Board&, Board&);
int getPlayerAction(Board&, Board&);
void renderBoard(Board&, Board&);

int main(int argc, char * arv[]){
    cout << "begin" << endl;
    srand(time(0));
    
    // Set up Player board
    Board pb;
    // Create player deck and draw initial hand here:
    for (int i = 0; i < 20; i++)
    pb.addToDeckList(new Goblin);
    // for (int i = 20; i < 20; i++)
    // pb.addToDeckList(Goblin);
    // for (int i = 20; i < 20; i++)
    // pb.addToDeckList(Goblin);
    // for (int i = 20; i < 20; i++)
    // pb.addToDeckList(Goblin);
    // for (int i = 20; i < 20; i++)
    // pb.addToDeckList(Goblin);
    // for (int i = 20; i < 20; i++)
    // pb.addToDeckList(Goblin);
    // for (int i = 20; i < 20; i++)
    // pb.addToDeckList(Goblin);
    // for (int i = 20; i < 20; i++)
    // pb.addToDeckList(Goblin);
    // for (int i = 20; i < 20; i++)
    // pb.addToDeckList(Goblin);
    // for (int i = 20; i < 20; i++)
    // pb.addToDeckList(Goblin);

    pb.shuffleDeck();
    
    // Set up opponent board
    Board ob;
    // Create opponent deck and draw initial hand here:
    for (int i = 0; i < 20; i++)
    ob.addToDeckList(new Goblin);
    // for (int i = 20; i < 20; i++)
    // ob.addToDeckList(Goblin);
    // for (int i = 20; i < 20; i++)
    // ob.addToDeckList(Goblin);
    // for (int i = 20; i < 20; i++)
    // ob.addToDeckList(Goblin);
    // for (int i = 20; i < 20; i++)
    // ob.addToDeckList(Goblin);
    // for (int i = 20; i < 20; i++)
    // ob.addToDeckList(Goblin);
    // for (int i = 20; i < 20; i++)
    // ob.addToDeckList(Goblin);
    // for (int i = 20; i < 20; i++)
    // ob.addToDeckList(Goblin);
    // for (int i = 20; i < 20; i++)
    // ob.addToDeckList(Goblin);
    // for (int i = 20; i < 20; i++)
    // ob.addToDeckList(Goblin);
    
    ob.shuffleDeck();
    
    
    while(pb.getHP() > 0 && ob.getHP() > 0){
        int turn = rand() % 1;
        // Take turns here:
        renderBoard(pb, ob);
        if (turn % 2 == 0){
            //Player turn
            while (getPlayerAction(pb, ob) != 1){}
        } else {
            // Enemy turn
            getOpponentAction(pb, ob);
        }
        
        turn++;
        break;
    }
    
    
    return 0;
}

void renderBoard(Board & pb, Board & ob){
    // Render opponent field
    ob.renderField();
    cout << endl;
    // Render player field
    pb.renderField();
    pb.renderHand();
    
    pb.renderMana();
    cout << "HP: " << pb.getHP() << " Opponent's HP: " << ob.getHP() << endl;
    
    //clearScreen(1);
}

void getOpponentAction(Board & playerBoard, Board & opponentBoard){
    // Go through hand and play cards that the opponent can afford to play
    for(int i = 0; i < opponentBoard.getHandSize(); i++){
        if(opponentBoard.getCardInHand(i)->getManaCost() <= opponentBoard.getMana()){
            opponentBoard.playCardFromHand(i);
        }
        renderBoard(playerBoard, opponentBoard);
    }
   
    // Attack with all creatures not exhausted
    for(int i = 0; i < opponentBoard.getFieldSize(); i++){
        if(!opponentBoard.getCardOnField(i)->isExhausted()){
            // get target for attack
            // look through all cards on player's board. If the card is capable of killing one of those, it will chose the first one as its target
            int targetIndex = -1;
            for(int j = 0; j < playerBoard.getFieldSize(); j++){
                if(opponentBoard.getCardOnField(i)->getAttack() > opponentBoard.getCardOnField(j)->getDefense()){
                    targetIndex = j;
                    break;
                }
            }
            if(targetIndex != -1){
                // destory creature
                cout << "Opponent's " << opponentBoard.getCardOnField(i)->getName() << " destroyed your " << playerBoard.getCardOnField(targetIndex)->getName() << "!" << endl;
                playerBoard.discardCardFromField(targetIndex);
                renderBoard(playerBoard, opponentBoard);
            } else {
                // opponent's creature attacks player directly
                cout << "Opponent's " << opponentBoard.getCardOnField(i)->getName() << " attacks you directly for " << opponentBoard.getCardOnField(i)->getAttack() << " damage!" << endl;
                playerBoard.setHP(playerBoard.getHP() - opponentBoard.getCardOnField(i)->getAttack());
            }
        }
                
    }
}

int getPlayerAction(Board & playerBoard, Board & opponentBoard){
    int choice = 3;
    cout << "Your turn. What would you like to do?" << endl;
    cout << "0: Play card from hand" << endl;
    cout << "1: Attack with a field card" << endl;
    cout << "2: End turn" << endl;
    cin >> choice;
    switch (choice){
        case 0:
            //Play card from hand
            if (playerBoard.getHandSize() > 0){
                cout << "What card would you like to play? (0 - " << playerBoard.getHandSize() - 1 << ")" << endl;
                cin >> choice;
                if (choice <= playerBoard.getHandSize() - 1 && choice >= 0){
                    if (playerBoard.getCardInHand(choice)->getManaCost() <= playerBoard.getMana()){
                        playerBoard.playCardFromHand(choice);
                        //Mana is dealt with inside the playCardFromHand function
                        return 0;
                    } else {
                        cout << "That card costs " << playerBoard.getCardInHand(choice)->getManaCost << " mana to play, you only have " << playerBoard.getMana() << "." << endl;
                        return 0;
                    }
                } else {
                    cout << choice << " is not a valid space in your hand." << endl;
                    return 0;
                }
            } else {
                cout << "You don't have any cards to play!" << endl;
                return 0;
            }
            break;
        case 1:
            //Attack with a field card
            
            break;
        case 2:
            //End turn
            return 1;
            break;
        default:
            cout << choice << " is not a valid input." << endl;
            return 0;
            break;
    }
}