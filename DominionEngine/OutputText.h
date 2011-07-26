/* 
 * File:   OutputText.h
 * Author: agousev
 *
 * Created on July 21, 2011, 4:56 PM
 */

#ifndef OUTPUTTEXT_H
#define	OUTPUTTEXT_H

#include "Output.h"
#include <vector>
#include <iostream>

using namespace std;

class OutputText : public Output {
public:
    OutputText();
    OutputText(const OutputText& orig);
    virtual ~OutputText();
    
    // Return value is if it is successful or not
    bool showOutput(int outputType, void* output);
private:

};

#endif	/* OUTPUTTEXT_H */

