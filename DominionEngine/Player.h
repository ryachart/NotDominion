/* 
 * File:   Player.h
 * Author: agousev
 *
 * Created on July 22, 2011, 12:58 PM
 */

#ifndef PLAYER_H
#define	PLAYER_H

#include <iostream>
#include <vector>
#include <assert.h>
#include <algorithm> // for vector shuffle
#include "Card.h"
//#include "Game.h"

// Forward declaration
class Game;

using namespace std;

class Player {
public:
    Player();
    Player(string aname, bool AI);
    virtual ~Player();
    
    // accessor functions
    vector<Card*> getHand();
    vector<Card*> getLibrary();
    vector<Card*> getGraveyard();
    vector<Card*> getInPlay();
    string getName();
    bool isAI();
    int getCurrentCoins();
    int getCurrentBuys();
    
    // Initializes the library to 7x Copper, 3x Estate
    void initLibrary();
    
    // Discards all cards from hand and from play, and draws new hand of 5 cards
    void doCleanUpStep();
    
    // Returns the sum of the victory values of all cards in hand, library and in play
    int getPointTotal();
    
    // Shuffles the contents of the graveyard and library together into new library
    void shuffleGraveyardIntoLibrary();
    
    // Plays card from hand.  We're assuming this is a legal play, and failing an assertion if it's not.
    void playCard(string card);
    
    // Plays all treasures from hand
    void playAllTreasures();
    
    // Buys card from supply.  Fails an assertion if it's illegal.
    void buyCard(string card, vector<Card*> *supply);
    
private:
    
    string name;
    
    // Draw a card from library.  If library is empty, reshuffle graveyard, then try again
    void drawCard();
    
    bool playerIsAI;
    vector<Card*> library;
    vector<Card*> graveyard;
    vector<Card*> hand;
    vector<Card*> inPlay;
    
    int currentCoins;
    int currentBuys;
    
};

#endif	/* PLAYER_H */

