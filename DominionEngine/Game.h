/* 
 * File:   Game.h
 * Author: agousev
 *
 * Created on June 14, 2011, 1:22 PM
 */

#ifndef GAMEZ_H
#define	GAMEZ_H

#include <iostream>
#include <string>
#include <time.h> // for random seed
#include <assert.h>
#include <sstream> // for converting ints to strings
#include "Input.h"
#include "InputText.h"
#include "OutputText.h"
#include "IOTags.h"


using namespace std;

class Game {
public:
    Game();
    Game(const Game& orig);
    virtual ~Game();
    
    void startGame();
    
private:
    
    void mainLoop();
    
    InputText input;
    OutputText output;
    
    bool gameIsOver;
    int score;
    int dealerScore;

};

#endif	/* GAMEZ_H */

