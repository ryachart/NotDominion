/* 
 * File:   Game.cpp
 * Author: agousev
 * 
 * Created on June 14, 2011, 1:22 PM
 */

#include "Game.h"

Game::Game() {
    
    gameIsOver = false;
}

Game::Game(const Game& orig) {
}

Game::~Game() {
}

void Game::startGame()
{
    dealerScore = 0;
    score = 0;
    srand ( time(NULL) );
    
    mainLoop();
}

void Game::mainLoop()
{
    bool success;
    while(!gameIsOver)
    {
        // Convert scores to string
        stringstream ss;
        ss << score << " " << dealerScore;
        output.showOutput(O_UPDATESCORES, ss.str());
            
        string action = input.getInput(I_GETACTION);
        
        if(action == "stay" || score > 21)
        {
            gameIsOver = true;
            
            bool wonGame = true;
            if(score > 21)
            {
                wonGame = false;
            }
            if(!(dealerScore > 21) && dealerScore >= score)
            {
                wonGame = false;
            }
            
            if(wonGame)
            {
                success = output.showOutput(O_GAMERESULT, "won");
            }
            else
            {
                success = output.showOutput(O_GAMERESULT, "lost");
            }                
        }
        else if(action == "hit")
        {
            score += (rand() % 10 + 1);
            dealerScore += (rand() % 10 + 1);
            
            if(score > 21)
            {
                // Convert scores to string
                stringstream ss;
                ss << score << " " << dealerScore;
                output.showOutput(O_UPDATESCORES, ss.str());
                
                success = output.showOutput(O_GAMERESULT, "lost");
                gameIsOver = true;
            }
            else if(dealerScore > 21)
            {
                // Convert scores to string
                stringstream ss;
                ss << score << " " << dealerScore;
                output.showOutput(O_UPDATESCORES, ss.str());
                
                success = output.showOutput(O_GAMERESULT, "won");
                gameIsOver = true;
            }
        }
        else
        {
            // INVALID INPUT
            // It is not the responsibility of the engine to validate input.
            // It is the responsibility of the input module.
            assert(false);
        }
        
    }
}



