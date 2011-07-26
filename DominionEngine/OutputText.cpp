/* 
 * File:   OutputText.cpp
 * Author: agousev
 * 
 * Created on July 21, 2011, 4:56 PM
 */

#include "OutputText.h"
#include "Card.h"

OutputText::OutputText() {
}

OutputText::OutputText(const OutputText& orig) {
}

OutputText::~OutputText() {
}

bool OutputText::showOutput(int outputType, void* output)
{
    switch(outputType)
    {
        case O_UPDATEPLAYER:
        {
            Player *p = ((Player*)output);
            vector<Card*> hand = p->getHand();
            cout << "You have " << p->getCurrentCoins() << " coins and " << p->getCurrentBuys() << " buys available" << endl;
            cout << "Your hand is ";
            vector<Card*>::iterator iter;
            for(iter = hand.begin(); iter != hand.end(); iter++)
            {
                cout << (*iter)->getName() << ", ";
            }
            cout << endl;
            break;
        }
            
        case O_NEWTURN:
        {
            cout << "It is now " << *((string*)output) << "'s turn" << endl;
            break;
        }
        
        case O_GAMEOVER:
        {
            cout << "The game is now over!  (Either the Provinces are gone, or any 3 supply piles are empty!)" << endl;
            break;
        }
            
            
        default:
            // Unknown output type
            assert(false);
    }
}
