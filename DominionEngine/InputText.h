/* 
 * File:   InputText.h
 * Author: agousev
 *
 * Created on June 14, 2011, 1:31 PM
 */

#ifndef INPUTTEXT_H
#define	INPUTTEXT_H

#include "Input.h"
#include <string>
#include <iostream>


using namespace std;

class InputText : public Input{
public:
    InputText();
    InputText(const InputText& orig);
    virtual ~InputText();
    
    string getInput(int inputType, Game* game);
    
private:
    
    

};

#endif	/* INPUTTEXT_H */

