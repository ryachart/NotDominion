/* 
 * File:   Card.cpp
 * Author: agousev
 * 
 * Created on July 22, 2011, 1:01 PM
 */

#include "Card.h"

Card::Card() {
}

Card::Card(const Card& orig){
}

Card::~Card() {
}

Card::Card(string aname)
{
    name = aname;
    
    if(name == "copper")
    {
        coinValue = 1;
        pointValue = 0;
        cost = 0;
        isTreasure = true;
        isVictory = false;
    }
    else if(name == "silver")
    {
        coinValue = 2;
        pointValue = 0;
        cost = 3;
        isTreasure = true;
        isVictory = false;
    }    
    else if(name == "gold")
    {
        coinValue = 3;
        pointValue = 0;
        cost = 6;
        isTreasure = true;
        isVictory = false;
    }    
    else if(name == "estate")
    {
        coinValue = 0;
        pointValue = 1;
        cost = 2;
        isTreasure = false;
        isVictory = true;
    }    
    else if(name == "duchy")
    {
        coinValue = 0;
        pointValue = 3;
        cost = 5;
        isTreasure = false;
        isVictory = true;
    }    
    else if(name == "province")
    {
        coinValue = 0;
        pointValue = 6;
        cost = 8;
        isTreasure = false;
        isVictory = true;
    }    
}

int Card::getPointValue()
{
    return pointValue;
}

int Card::getCoinValue()
{
    return coinValue;
}

int Card::getCost()
{
    return cost;
}

string Card::getName()
{
    return name;
}

bool Card::isATreasure()
{
    return isTreasure;
}

bool Card::isAVictory()
{
    return isVictory;
}
