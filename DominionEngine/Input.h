        /* 
 * File:   Input.h
 * Author: agousev
 *
 * Created on June 14, 2011, 1:28 PM
 */

#ifndef INPUT_H
#define	INPUT_H
#include <string>
#include "IOTags.h"

// Forward declaration
class Game;

using namespace std;

class Input {
public:
    Input();
    Input(const Input& orig);
    virtual ~Input();
    
    // game pointer is usually not necessary, but it might be in order to get information about the game.
    string getInput(int inputType, Game* game);
private:

};

#endif	/* INPUT_H */

