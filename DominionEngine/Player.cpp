/* 
 * File:   Player.cpp
 * Author: agousev
 * 
 * Created on July 22, 2011, 12:58 PM
 */

#include "Player.h"

Player::Player() {
}

Player::~Player() {
}

Player::Player(string aname, bool AI)
{
    name = aname;
    playerIsAI = AI;
}

vector<Card*> Player::getHand()
{
    return hand;
}

vector<Card*> Player::getLibrary()
{
    return library;
}

vector<Card*> Player::getGraveyard()
{
    return graveyard;
}

vector<Card*> Player::getInPlay()
{
    return inPlay;
}

bool Player::isAI()
{
    return playerIsAI;
}

string Player::getName()
{
    return name;
}

void Player::initLibrary()
{
    for(int i = 0; i < 7; i++)
        library.push_back(new Card("copper"));

    for(int i = 0; i < 3; i++)
        library.push_back(new Card("estate"));

    /*
    // For testing purposes    
    library.push_back(new Card("1"));
    library.push_back(new Card("2"));
    library.push_back(new Card("3"));
    library.push_back(new Card("4"));
    library.push_back(new Card("5"));
    library.push_back(new Card("6"));
    library.push_back(new Card("7"));
    library.push_back(new Card("8"));
    library.push_back(new Card("9"));
    library.push_back(new Card("10"));
    library.push_back(new Card("11"));
    library.push_back(new Card("12"));
    library.push_back(new Card("13"));
     */  
    
    // shuffle
    shuffleGraveyardIntoLibrary();
}

void Player::shuffleGraveyardIntoLibrary()
{
    // Merge graveyard into library
    library.insert( library.end(), graveyard.begin(), graveyard.end() );
   
    // Clear graveyard
    graveyard.clear();
    
    // Shuffle library
    random_shuffle( library.begin(), library.end() );
    
}

void Player::doCleanUpStep()
{
    // Discard hand
    graveyard.insert(graveyard.end(), hand.begin(), hand.end());
    hand.clear();
    
    // Draw 5 cards
    for(int i = 0; i < 5; i++)
        drawCard();
    
    // Reset turn
    currentCoins = 0;
}

void Player::drawCard()
{
    // If library is not empty, draw a card
    if(library.size() > 0)
    {
        // Add top of library to hand
        hand.push_back(library.front());
        
        // Delete top of library
        library.erase(library.begin());
    }
    // else reshuffle graveyard, then draw
    else
    {
        shuffleGraveyardIntoLibrary();
        
        // if there are cards left to draw
        if(library.size() > 0)
        {
            // Add top of library to hand
            hand.push_back(library.front());

            // Delete top of library
            library.erase(library.begin());            
        }
    }
}

void Player::playCard(string card)
{
    // Find the card to be played (expressed as an iterator)
    vector<Card*>::iterator iter;
    for(iter = hand.begin(); iter != hand.end(); iter++)
    {
        if( (*iter)->getName() == card)
            break;
    }
    
    // ERROR - Card not found in hand
    if(iter == hand.end())
        assert(false);
    
    // ERROR - Attempted to play victory card (actions not implemented yet)
    if(!(*iter)->isATreasure())
        assert(false);
    
    // Add coin value of card to player
    currentCoins += (*iter)->getCoinValue();
    
    // Add card to inPlay
    inPlay.insert(inPlay.end(), iter, iter);
    
    // Remove card from hand
    hand.erase(iter);
}

int Player::getPointTotal()
{
    int total = 0;
    vector<Card*>::iterator iter;
    
    // Iterate through library, hand, and inPlay, summing up the points
    for(iter = library.begin(); iter != library.end(); iter++)
        total += (*iter)->getPointValue();
    
    for(iter = hand.begin(); iter != hand.end(); iter++)
        total += (*iter)->getPointValue();
 
    for(iter = inPlay.begin(); iter != inPlay.end(); iter++)
        total += (*iter)->getPointValue();
    
    return total;
}
