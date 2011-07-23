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
    srand ( time(NULL) );
    
    // Assuming there's only 1 players for now
    //players.push_back(new Player("Alexei", false));    
    players.push_back(new Player("Ka Shing", false));
    
    // Initialize players
    vector<Player*>::iterator iter;
    for(iter = players.begin(); iter != players.end(); iter++)
    {
        (*iter)->initLibrary();
        
        // draw starting hand
        (*iter)->doCleanUpStep();
    }
    
    mainLoop();
}

void Game::mainLoop()
{
    bool success; // success of output
    currentTurn = 0;
    
    string name = players.at(currentTurn)->getName();
    success = output.showOutput(O_NEWTURN, &name);
    
    while(!gameIsOver)
    {
        Player *p = players.at(currentTurn);
        success = output.showOutput(O_UPDATEPLAYER, p);
        
        string in = input.getInput(I_BUYPHASE);
        
        if(in == "quit")
        {
            gameIsOver = true;
            break;
        }
        
        else if(in == "end turn")
        {
            players.at(currentTurn)->doCleanUpStep();
            
            // Advance to next turn
            currentTurn++;
            
            // loop current turn back to 0 if necessary
            if(currentTurn >= players.size())
                currentTurn = 0;
            
            // Output new turn
            string name = players.at(currentTurn)->getName();
            success = output.showOutput(O_NEWTURN, &name);
            
        }
        
        else
        {
            // Divide string into 2 words
            istringstream iss(in, istringstream::in);
            string command, target;
            iss >> command >> target;
            
            if(command == "play")
            {
                players.at(currentTurn)->playCard(target);
            }
            else if(command == "buy")
            {
                // not implemented yet
            }
            else
            {
                // ERROR - unknown command
                assert(false);
            }
        }
    }
}
