/* 
 * File:   InputText.cpp
 * Author: agousev
 * 
 * Created on June 14, 2011, 1:31 PM
 */

#include "InputText.h"

InputText::InputText() {
    
}

InputText::InputText(const InputText& orig) {
}

InputText::~InputText() {
}

string InputText::getInput(int inputType)
{
    if(inputType == I_GETACTION)
    {
        string in;
        bool first = true;
        do
        {
            if(!first)
                cout << "Invalid input!" << endl;
            first = false;
            
            cout << "What do you want to do?  hit or stay?" << endl;
            cin >> in;
        } while(in != "hit" && in != "stay");
        
        return in;
    }
    
    return "nil";
}
