        /* 
 * File:   Output.h
 * Author: agousev
 *
 * Created on July 21, 2011, 1:28 PM
 */

#include <string>
#include "IOTags.h"
#include <sstream>
//#include "Game.h"

#ifndef OUTPUT_H
#define	OUTPUT_H

using namespace std;

class Output {
public:
    Output();
    Output(const Output& orig);
    virtual ~Output();
    
    // returns if it is successful or not
    bool showOutput(int outputType, string output);
private:

};

#endif	/* INPUT_H */

