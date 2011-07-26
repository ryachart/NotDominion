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

int Player::getCurrentCoins()
{
    return currentCoins;
}

int Player::getCurrentBuys()
{
    return currentBuys;
}

void Player::initLibrary()
{
    for(int i = 0; i < 7; i++)
        library.push_back(new Card("copper"));

    for(int i = 0; i < 3; i++)
        library.push_back(new Card("estate"));
    
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
    
    // Discard cards from play
    graveyard.insert(graveyard.end(), inPlay.begin(), inPlay.end());
    inPlay.clear();
    
    // Draw 5 cards
    for(int i = 0; i < 5; i++)
        drawCard();
    
    // Reset turn
    currentCoins = 0;
    currentBuys = 1;
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
    inPlay.push_back(*iter);
    
    // Remove card from hand
    hand.erase(iter);
}

void Player::playAllTreasures()
{
    // Iterate through cards in hand
    vector<Card*>::iterator iter;
    for(iter = hand.begin(); iter != hand.end();)
    {
        // If the card is a treasure, play it. (This removes the card from hand, so we don't need to increment iterator).
        if((*iter)->isATreasure())
            playCard((*iter)->getName());
        
        // Otherwise, increment iterator
        else
            iter++;
    }
}

void Player::buyCard(string card, vector<Card*>* supply)
{
    // Find the card to be bought (expressed as an iterator)
    vector<Card*>::iterator iter;
    for(iter = supply->begin(); iter != supply->end(); iter++)
    {
        if( (*iter)->getName() == card)
            break;
    }
    
    // ERROR - Card not found in supply
    if(iter == supply->end())
        assert(false);
    
    // ERROR - Don't have enough coins to buy card
    if(currentCoins < (*iter)->getCost())
        assert(false);
    
    // ERROR - No buys available
    if(currentBuys <= 0)
        assert(false);
    
    // Subtract cost of card from coins
    currentCoins -= (*iter)->getCost();
    
    // Add card to graveyard
    graveyard.push_back(*iter);
    
    // Remove card from supply
    supply->erase(iter);
    
    // Decrement number of buys
    currentBuys--;
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
