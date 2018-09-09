/************************
 * Program: pokestop.cpp
 * Author: claire cahill
 * Date: 5/22/17
 * Description: is an event with a location
 * Input: none
 * Output: number of pokeballs received
 * *********************/

#include "pokestop.h"

/****************************
 * Function: defauly constructor
 * Description: assigns values 
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none
 * *****************************/

Pokestop::Pokestop(){

   type = "Pokestop";
}
/****************************
 *
 * Function: message
 * Description: prints when nearby
 * Parameters: none
 * Pre-Conditions: location must exist
 * Post-Conditions: none
 * ********************/

void Pokestop::message(){

   cout << "Fill up on pokeballs." << endl;

}

/***********************
 * Function: get_num_pokeballs
 * Description: assigns rand num 3-10
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none
 * ********************/

int Pokestop::get_num_pokeballs(){

   int num_pokeballs = 0;
   srand(time(NULL));
   
   num_pokeballs = (rand()%8) + 3; //0-7 plus 3 gives a randmon int from 3-10

   return num_pokeballs;
}

