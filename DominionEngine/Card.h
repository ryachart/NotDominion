/* 
 * File:   Card.h
 * Author: agousev
 *
 * Created on July 22, 2011, 1:01 PM
 */

#ifndef CARD_H
#define	CARD_H

#include <string>
#include <iostream>
using namespace std;

class Card {
public:
    Card();
    Card(const Card& orig);
    Card(string aname);
    virtual ~Card();
    
    // Accessor functions
    int getCoinValue();
    int getPointValue();
    int getCost();
    string getName();
    bool isATreasure();
    bool isAVictory();
    
private:
    
    string name;
    
    // How much money you get when you play the card
    int coinValue;
    
    // How many VPs the card is worth
    int pointValue;
    
    // Cost to buy the card
    int cost;
    
    // Keep track of the card type
    bool isTreasure;
    bool isVictory;
    
};

#endif	/* CARD_H */

