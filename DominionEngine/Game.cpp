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

vector<Card*> Game::getSupply()
{
    return supply;
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
    
    // Initialize supply
    // 60 copper, minus 7 per player
    int numVictory = 8;
    if(players.size() > 2)
        numVictory = 12;
    
    // ToDo:  Automate filling cardsInSupply
    cardsInSupply.push_back("copper");
    for(int i = 0; i < 60 - 7*players.size(); i++)
        supply.push_back(new Card("copper"));
    
    cardsInSupply.push_back("silver");
    for(int i = 0; i < 40; i++)
        supply.push_back(new Card("silver"));
    
    cardsInSupply.push_back("gold");
    for(int i = 0; i < 30; i++)
        supply.push_back(new Card("gold"));
    
    cardsInSupply.push_back("estate");
    for(int i = 0; i < numVictory; i++)
        supply.push_back(new Card("estate"));
    
    cardsInSupply.push_back("duchy");
    for(int i = 0; i < numVictory; i++)
        supply.push_back(new Card("duchy"));
    
    cardsInSupply.push_back("province");
    for(int i = 0; i < numVictory; i++)
        supply.push_back(new Card("province"));
    
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
        bool turnIsOver = false;
        
        Player *p = players.at(currentTurn);
        success = output.showOutput(O_UPDATEPLAYER, p);
        
        string in = input.getInput(I_BUYPHASE, this);
        
        if(in == "quit")
        {
            gameIsOver = true;
            break;
        }
        
        else if(in == "end turn")
        {
            turnIsOver = true;            
        }
        
        else
        {
            // Divide string into 2 words
            istringstream iss(in, istringstream::in);
            string command, target;
            iss >> command >> target;
            
            if(command == "play")
            {
                if(target == "coins")
                {
                    // Play all coins
                    players.at(currentTurn)->playAllTreasures();
                }
                else
                {
                    players.at(currentTurn)->playCard(target);
                }
            }
            
            else if(command == "buy")
            {
                players.at(currentTurn)->buyCard(target, &supply);
                if(players.at(currentTurn)->getCurrentBuys() <= 0)
                    turnIsOver = true;
            }
            else
            {
                // ERROR - unknown command
                assert(false);
            }
        }
        
        if(turnIsOver)
        {
            players.at(currentTurn)->doCleanUpStep();
            
            if(gameShouldEnd())
            {
                gameIsOver = true;
                // ToDo:  Pass information about why the game ended to output
                output.showOutput(O_GAMEOVER, NULL);
            }
            else
            {
                // Advance to next turn
                currentTurn++;

                // loop current turn back to 0 if necessary
                if(currentTurn >= players.size())
                    currentTurn = 0;

                // Output new turn
                string name = players.at(currentTurn)->getName();
                success = output.showOutput(O_NEWTURN, &name);
            }
        }
    }
}

bool Game::gameShouldEnd()
{
    vector<string> supplyCardNames = getSupplyCardNames();
    
    int numEmptyPiles = 0;
    
    vector<string>::iterator iter;
    for(iter = cardsInSupply.begin(); iter != cardsInSupply.end(); iter++)
    {
        // Search for name
        vector<string>::iterator found = find(supplyCardNames.begin(), supplyCardNames.end(), *iter);
        
        // Name not found
        if(found == supplyCardNames.end())
        {
            // no provinces left
            if(*iter == "province")
                return true;
            else
                numEmptyPiles++;
        }
    }
    
    if(numEmptyPiles >= 3)
        return true;
    else
        return false;
}

vector<string> Game::getSupplyCardNames()
{
    vector<string> supplyCardNames;
    
    // Iterate through supply and add card names to string vector
    vector<Card*>::iterator iter;
    for(iter = supply.begin(); iter != supply.end(); iter++)
    {
        supplyCardNames.push_back((*iter)->getName());
    }

    // Sort names
    sort(supplyCardNames.begin(), supplyCardNames.end());
    
    return supplyCardNames;
}