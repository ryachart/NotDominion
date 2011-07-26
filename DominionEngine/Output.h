        /* 
 * File:   Output.h
 * Author: agousev
 *
 * Created on July 21, 2011, 1:28 PM
 */
#ifndef OUTPUT_H
#define	OUTPUT_H

#include <string>
#include "IOTags.h"
#include <sstream>
#include "Player.h"
//#include "Game.h"



using namespace std;

class Output {
public:
    Output();
    Output(const Output& orig);
    virtual ~Output();
    
    // returns if it is successful or not
    bool showOutput(int outputType, void* output);
private:

};

#endif	/* INPUT_H */

