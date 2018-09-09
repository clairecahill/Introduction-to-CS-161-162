/*****************************
 * Program: event.cpp
 * Author:claire cahill
 * Date: 5/26/17
 * Description: abstract base class
 * Input: none
 * Output: message when nearby event
 * ***************************/

#include "event.h"

/*************************
 * Function: default constructor
 * Desription: sets type
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none
 * **********************/

Event::Event(){

   type = "type";

}

/*************************
 * Function: assign op overload
 * Desription: assigns values
 * Parameters: const Event &other
 * Pre-Conditions: none
 * Post-Conditions: none
 * **********************/

void Event::operator = (const Event &other){

   type = other.type;
}

/*************************
 * Function: set_type
 * Desription: type modifier
 * Parameters: s
 * Pre-Conditions: none
 * Post-Conditions: none
 * **********************/

void Event::set_type(string s){
 
   type = s;
}

/*************************
 * Function: set_type
 * Desription: type getter
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none
 * **********************/

string Event::get_type(){

   return type;
}

/******************
 * Function: message
 * Description: virtual function
 * prints message if trainer is close
 * to an event
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none
 * *******************/

void Event::message(){

   cout << "Go to the nearby event." << endl;
}
