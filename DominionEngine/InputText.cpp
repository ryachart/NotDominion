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
    if(inputType == I_BUYPHASE)
    {
        string command, target;
        bool first = true;
        bool invalid = false;
        do
        {
            if(!first)
                cout << "Invalid input!" << endl;
            first = false;
            
            cout << "What do you want to do? (options are \"play <card>\", \"buy <card>\", \"end turn\" or \"quit\")" << endl;
            cin >> command;
            
            if(command == "quit")
            {
                cout << endl;
                return command;
            }
            
            if(command == "end")
            {
                cin >> target;
                if(target != "turn")
                    invalid = true;
                else
                {
                    cout << endl;
                    return command + " " + target;
                }
            }
            
            if(command == "play" || command == "buy")
            {
                cin >> target;
                // ToDo:  check legality of target
                cout << endl;
                return command + " " + target;    
            }

        } while(true); // if we get this far, the input is invalid
        
        
    }
    
    return "nil";
}
