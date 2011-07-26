/* 
 * File:   InputText.cpp
 * Author: agousev
 * 
 * Created on June 14, 2011, 1:31 PM
 */

#include "InputText.h"
#include "Game.h"

InputText::InputText() {
    
}

InputText::InputText(const InputText& orig) {
}

InputText::~InputText() {
}

string InputText::getInput(int inputType, Game* game)
{
    if(inputType == I_BUYPHASE)
    {
        string command, target;
        bool invalid = false;  // if true, that means input could not parsed
        do
        {
            if(invalid)
                cout << "Invalid input!" << endl;
            invalid = false;
            
            cout << "What do you want to do? (options are \"play <card>\", \"play coins\", \"buy <card>\", \"see supply\", \"end turn\" or \"quit\")" << endl;
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
            
            if(command == "see")
            {
                cin >> target;
                if(target != "supply")
                {
                    invalid = true;
                }
                else
                {
                    // Get names of all cards in supply
                    vector<string> supplyCardNames = game->getSupplyCardNames();
                    
                    // Iterate through sorted names and output them.
                    cout << "Supply contains:" << endl;
                    string previousString = "";
                    int stringCount = 0;
                    vector<string>::iterator iter2;
                    for(iter2 = supplyCardNames.begin(); iter2 != supplyCardNames.end(); iter2++)
                    {
                        // if string changed between previous iteration and this one, print it out
                        if(*iter2 != previousString && previousString != "")
                        {
                            cout << stringCount << "x " << previousString << endl;
                            stringCount = 1;
                        }
                        // else increment count
                        else
                        {
                            stringCount++;
                        }
                        
                        previousString = *iter2;
                    }
                    // Print out last supply pile
                    cout << stringCount << "x " << previousString << endl;
                    stringCount = 1;
                    
                    cout << endl;
                }
            }
            
            if(command == "play" || command == "buy")
            {
                cin >> target;
                // ToDo:  check legality of target
                cout << endl;
                return command + " " + target;    
            }

        } while(true); // if we get this far, the input is invalid, or we need to loop through again (in the case of "see supply")
        
        
    }
    
    // This should never happen
    return "nil";
}
