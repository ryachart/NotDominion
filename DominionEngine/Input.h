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
//#include "Game.h"

using namespace std;

class Input {
public:
    Input();
    Input(const Input& orig);
    virtual ~Input();
    
    string getInput(int inputType);
private:

};

#endif	/* INPUT_H */

