/* 
 * File:   Game.h
 * Author: agousev
 *
 * Created on June 14, 2011, 1:22 PM
 */

#ifndef GAMEZ_H
#define	GAMEZ_H

#include <iostream>
#include <string>
#include <time.h> // for random seed
#include <assert.h>
#include <sstream> // for converting ints to strings
#include "Input.h"
#include "InputText.h"
#include "OutputText.h"
#include "IOTags.h"
#include "Player.h"
#include "Card.h"

// Forward declarations to avoid dependency loop
//class OutputText;
//class Player;


using namespace std;

class Game {
public:
    Game();
    Game(const Game& orig);
    virtual ~Game();
    
    // Initializes the game and starts running the main loop.  To be called externally.
    void startGame();
    
    // Accessor functions
    vector<Card*> getSupply();
    
    // Returns sorted list of names of cards in supply
    vector<string> getSupplyCardNames(); 
    
private:
    
    // To be called by startGame();
    void mainLoop();
    
    // Checks the supply piles to see if either all the provinces are empty, or any 3 piles are empty.
    bool gameShouldEnd();
    
    InputText input;
    OutputText output;
    
    bool gameIsOver;
    
    vector<Player*> players;
    
    // Stores the appropriate amount of each supply card.  Changes as the game goes on.
    vector<Card*> supply;
    
    // Stores only one string for each supply pile.  Does not change after it is initialized.
    vector<string> cardsInSupply;
    
    // keeps track of whose turn it is
    int currentTurn;

};

#endif	/* GAMEZ_H */

