/*************************
 * Program: cave.cpp
 * Author: claire cahill
 * Date: 5/22/17
 * Description: is an event
 * Input: none
 * Output: message when nearby
 * ***********************/

#include "cave.h"

/************************
 * Function: constructor
 * Description: used to create new cave
 * Parameters: none
 * Pre-Conditions: cave.h
 * Post-Conditions: none
 *************************/

Cave::Cave(){

   type = "Cave";

}

/**********************
 * Function: message
 * Description: prints when nearby cave
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none
 ************************/

void Cave::message(){

   cout << "You see a precious stone nearby." << endl;

}

