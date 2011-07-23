/* 
 * File:   Output.cpp
 * Author: agousev
 * 
 * Created on July 22, 2011, 1:28 PM
 */

#include "Output.h"

Output::Output() {
}

Output::Output(const Output& orig) {
}

Output::~Output() {
}

bool Output::showOutput(int outputType, void* output)
{
    return false;  // not successful because output child method was not found
}

