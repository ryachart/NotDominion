/* 
 * File:   Input.cpp
 * Author: agousev
 * 
 * Created on June 14, 2011, 1:28 PM
 */

#include "Input.h"

Input::Input() {
}

Input::Input(const Input& orig) {
}

Input::~Input() {
}

string Input::getInput(int inputType, Game* game)
{
    return "ERROR!  No input method found in Input child class!";
}

