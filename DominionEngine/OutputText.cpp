/* 
 * File:   OutputText.cpp
 * Author: agousev
 * 
 * Created on July 21, 2011, 4:56 PM
 */

#include "OutputText.h"

OutputText::OutputText() {
}

OutputText::OutputText(const OutputText& orig) {
}

OutputText::~OutputText() {
}

bool OutputText::showOutput(int outputType, string output)
{
    if(outputType == O_UPDATESCORES)
    {
        stringstream ss;
        ss << output;
        int score, dealerScore;
        ss >> score >> dealerScore;
        
        cout << "Your score is " << score << ".  Dealer\'s score is " << dealerScore << endl;
        
        return true;
    }
    
    else if(outputType == O_GAMERESULT)
    {
        if(output == "won")
        {
            cout << "You won the game!" << endl;
        }
        else if(output == "lost")
        {
            cout << "You lost the game!" << endl;
        }
        else
        {
            // Neither won nor lost the game (draws aren't possible).
            assert(false);
        }
    }    
    else
    {
        // Unknown output type
        assert(false);
    }
}
