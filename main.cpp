#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sstream>
#include <list>
#include <string>
#include <vector>
#include "board.cpp"
#include "goblin.cpp"
#include "card.cpp"

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
    pb.addToDeckList(new Goblin("Goblin", 1, 200, 100));
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
    
    pb.draw(5);
    
    
    // Set up opponent board
    Board ob;
    // Create opponent deck and draw initial hand here:
    for (int i = 0; i < 20; i++)
    ob.addToDeckList(new Goblin("Goblin", 1, 200, 100));
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
    
    ob.draw(5);
    
    while(pb.getHP() > 0 && ob.getHP() > 0){
        int turn = rand() % 1;
        // Take turns here:
        //renderBoard(pb, ob);
        if (turn % 2 == 0){
            //Player turn
            while (getPlayerAction(pb, ob) != 1);
        } else {
            // Enemy turn
            getOpponentAction(pb, ob);
        }
        
        turn++;
        if (pb.getMana() < 10)
        pb.setMana(pb.getMana() + 1);
        if (ob.getMana() < 10)
        ob.setMana(ob.getMana() + 1);
    }
    if (pb.getHP() > 0){
        cout << "You win!" << endl;
    } else {
        cout << "You lose!" << endl;
    }
    
    return 0;
}

void renderBoard(Board & pb, Board & ob){
    // Render opponent field
    ob.renderMana(); //Take this out eventually, no peeking!
    ob.renderHand();
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
            // look through all cards on player's board. If the card is capable of killing one of those, it will choose the first one as its target
            int targetIndex = -1;
            for(int j = 0; j < playerBoard.getFieldSize(); j++){
                if(opponentBoard.getCardOnField(i)->getAttack() > opponentBoard.getCardOnField(j)->getDefense()){
                    targetIndex = j;
                    break;
                }
            }
            if(targetIndex != -1){
                // destroy creature
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
    string input = "input here";
    int choice = int(input.at(0)) - 48;
    
    renderBoard(playerBoard, opponentBoard);
    cout << "Your turn. What would you like to do?" << endl;
    cout << "0: Play card from hand" << endl;
    cout << "1: Attack with a field card" << endl;
    cout << "2: End turn" << endl;
    cin >> input;
    choice = int(input.at(0)) - 48;
    switch (choice){
        case 0:
            //Play card from hand
            if (playerBoard.getHandSize() > 0){
                cout << "What card would you like to play? (0 - " << playerBoard.getHandSize() - 1 << ")" << endl;
                cin >> input;
                choice = int(input.at(0)) - 48;
                if (choice <= playerBoard.getHandSize() - 1 && choice >= 0){
                    if (playerBoard.getCardInHand(choice)->getManaCost() <= playerBoard.getMana()){
                        playerBoard.playCardFromHand(choice);
                        //Mana is dealt with inside the playCardFromHand function
                        return 0;
                    } else {
                        cout << "That card costs " << playerBoard.getCardInHand(choice)->getManaCost() << " mana to play, you only have " << playerBoard.getMana() << "." << endl;
                        return 0;
                    }
                } else {
                    cout << input << " is not a valid space in your hand." << endl;
                    return 0;
                }
            } else {
                cout << "You don't have any cards to play!" << endl;
                return 0;
            }
            break;
        case 1:
            //Attack with a field card
            if (playerBoard.getFieldSize() > 0){
                int choice2;
                cout << "What card would you like to attack with? (0 - " << playerBoard.getFieldSize() - 1 << ")" << endl;
                cin >> input;
                choice = int(input.at(0)) - 48;
                if (choice <= playerBoard.getFieldSize() - 1 && choice >= 0){
                    if (!playerBoard.getCardOnField(choice)->isExhausted()){
                        if (opponentBoard.getFieldSize() > 0) {
                            //Attack card on field
                            cout << "What card would you like to attack? (0 - " << opponentBoard.getFieldSize() - 1 << ")" << endl;
                            cin >> input;
                            choice2 = int(input.at(0)) - 48;
                            if (choice2 <= opponentBoard.getFieldSize() - 1 && choice2 >= 0){
                                if (opponentBoard.getCardOnField(choice2)->getDefense() < playerBoard.getCardOnField(choice)->getAttack()){
                                    cout << "Your " << playerBoard.getCardOnField(choice)->getName() << " destroyed the opponent's " << opponentBoard.getCardOnField(choice2)->getName() << "!" << endl;
                                    opponentBoard.discardCardFromField(choice2);
                                    renderBoard(playerBoard, opponentBoard);
                                } else {
                                    cout << "The target's defense is too high!" << endl;
                                    return 0;
                                }
                            } else {
                                cout << input << " is not a valid space in their field." << endl;
                                return 0;
                            }
                        } else {
                            //Attack opponent himself
                            cout << "Your opponent has no cards to defend him!" << endl;
                            opponentBoard.setHP(opponentBoard.getHP() - playerBoard.getCardOnField(choice)->getAttack());
                            return 0;
                        }
                    } else {
                        cout << "That card is exhausted and can't attack this turn!" << endl;
                        return 0;
                    }
                } else {
                    cout << input << " is not a valid space in your field." << endl;
                    return 0;
                }
            } else {
                cout << "You don't have any cards on the field!" << endl;
                return 0;
            }
            break;
        case 2:
            //End turn
            playerBoard.unExhaustField();
            return 1;
            break;
        default:
            cout << input << " is not a valid input." << endl;
            return 0;
            break;
    }
}