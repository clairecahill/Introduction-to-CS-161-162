/****************************************
 * Program: state_facts.cpp
 * Author: Claire Cahill
 * Date: 4/15/2017
 * Description: User enters command line argument and 
 * the program takes file information and sortes
 * it into arrays. The program prints the stats and additional 
 * information.
 * Input: executable, -s, amount of states, -f, file name
 * Output: Prints out stats followed by other information
 * ***************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>

using namespace std;

#include "./state_facts.h"

/************************************
 * Function: is_valid_arguments
 * Description: error checks command line arguments
 * Parameters: argc, argv
 * Pre-Conditions: none
 * Post-Conditions: none
 * Return valid_arguments
 * *********************************/

bool is_valid_arguments(char **argv, int argc){

   bool valid_arguments = true;
   int x = 0;
   char* file_location;

   if(argc > 5 || argc < 5){                                                  //incorrect number of arguments
      valid_arguments = false;
      cout << "Incorrect amount of arguments." << endl;
   }

   if(strcmp(argv[1], "-s") != 0){    //if argument is not -s it checks for -f                                    
      if(strcmp(argv[1], "-f") != 0){	//checks if its not -f or -s, then valid arguments is false
	 valid_arguments = false;
	 cout << "Incorrect arguments (please use -s and -f)." << endl;  	//checking for -s and -f in command line args
      }
   }

   else if(strcmp(argv[3], "-f") != 0){
      if(strcmp(argv[3], "-s") != 0){
	 valid_arguments = false;
	 cout << "Incorrect arguments (please use -s and -f)." << endl;
      }
   }

   return valid_arguments;
}

/************************************
 * Function: create_states
 * Description: creates space in memory for states array
 * Parameters: num_states
 * Pre-Conditions: none
 * Post-Conditions: none
 * Return: states
 * *********************************/

state * create_states(int num_states){

   state *states = new state[num_states];

   return states;
}

/*****************************************
 * Function: get_state_data
 * Description: reads in information from a file, then 
 * calls on get_county_data 
 * Parameters: states, num_states, the_file
 * Pre-Conditions: the_file must be open
 * Post-Conditions: none
 * Return: none
 * *************************************/

void get_state_data(state *states, int num_states, ifstream &the_file){

   int num_counties = 0;
   ofstream info_file;
   for(int i = 0; i < num_states; i++){
      the_file >> states[i].name;
      the_file >> states[i].population;
      the_file >> states[i].counties;					//reads all state info from file and assigns array
      states[i].c = create_counties(states[i].counties);
      get_county_data(states[i].c, states[i].counties, the_file);
   }
   for(int i = 0; i < num_states; i++){
      num_counties = states[i].counties; 				//assigns variable
   }
   county *c = create_counties(num_counties);

   print_stats(states, c, num_states, num_counties);
   char *answer = print_or_save(states, num_states, the_file);
}

/*****************************************
 * Function: create_counties
 * Description:assigns county array memory on heap
 * Parameters: num_counties
 * Pre-Conditions: none
 * Post-Conditions: none
 * Return: none
 * *************************************/

county *create_counties(int num_counties){

   county *c = new county [num_counties];

   return c;

}

/*****************************************
 * Function:get_county_data
 * Description: reads in county info from file
 * Parameters: c, num_counties, the_file
 * Pre-Conditions: c and the file must exist
 * Post-Conditions: none
 * Return: none
 * *************************************/

void get_county_data(county *c, int num_counties, ifstream &the_file){

   int num_cities = 0, largest_pop = 0;
   for(int i= 0; i < num_counties; i++){
      the_file >> c[i].name;
      the_file >> c[i].population;
      the_file >> c[i].avg_income;				//reads in and assigns array info from file
      the_file >> c[i].avg_house;
      the_file >> c[i].cities;
      num_cities = c[i].cities;
      c[i].city = new string [num_cities];
      for(int j = 0; j < num_cities; j++){
	 the_file >> c[i].city[j];
      }
   }
}

/*****************************************
 * Function: print_stats
 * Description: prints all information to screen
 * Parameters: states, c, num_states, num_counties
 * Pre-Conditions: none
 * Post-Conditions: none
 * Return: none
 * *************************************/

void print_stats(state *states, county *c, int num_states, int num_counties){

   for(int i = 0; i < num_states; i++){
      cout << "         " << endl;
      cout << "State name: " << states[i].name << ". ";
      cout << "State population: " << states[i].population << ". ";
      cout << "Number of counties: " << states[i].counties << endl;
      for(int j = 0; j < num_counties; j++){
	 cout << "County name: " << states[i].c[j].name << ". ";
	 cout << "County population: " << states[i].c[j].population << ". ";
	 cout << "Number of cities: " << states[i].c[j].cities << ". ";
	 for(int k = 0; k < states[i].c[j].cities; k++){
	    cout << "City name: " << states[i].c[j].city[k] << endl;
	 }
	 cout << "Average income: " << states[i].c[j].avg_income << ". ";
	 cout << "Average household price: " << states[i].c[j].avg_house << endl;
      }
   }

}

/*****************************************
 * Function: print_or_save
 * Description: asks user if he/she wants to print or 
 * save the additional information and calls on functions
 * for that information
 * Parameters: states, num_states, the_file
 * Pre-Conditions: none
 * Post-Conditions: none
 * Return: answer
 * *************************************/

char *print_or_save(state *states, int num_states, ifstream &the_file){

   char *answer = new char [256];
   char *filename = new char [256];
   ofstream info_file;
   do{
      cout << "Would you like to print(1) or save the the information to a file(2): " << endl;

      cin >> answer;
   }while(strcmp(answer, "1") != 0 && strcmp(answer, "2") != 0);

   if(strcmp(answer, "2") == 0){
      cout << "Enter file name: " << endl;
      cin.ignore();
      cin.getline(filename, 256);						//gets file name from user to store info
      info_file.open(filename);
   }

   largest_state_pop(states, num_states, answer, info_file);
   largest_county_pop(states, num_states, answer, info_file);
   county_income(states, num_states, answer, info_file);
   average_house(states, num_states, answer, info_file);			//all function calls for sorting functions
   sort_state_names(states, num_states, answer, info_file);
   sort_state_population(states, num_states, answer, info_file);
   sort_county_population(states, num_states, answer, info_file);

   return answer;

} 


/*****************************************
 * Function: largest_state_function
 * Description: reads through state population and 
 * assigns largest index to largest variable
 * Parameters: states, num_states, answer, info_file
 * Pre-Conditions: none
 * Post-Conditions: none
 * Return: none
 * *************************************/


void largest_state_pop(state *states, int num_states, char *answer, ofstream &info_file){

   int largest = 0;
   for(int i = 0; i < num_states; i++){
      for(int j = 0; j < num_states; j++){
	 if(states[j].population > states[largest].population){		//if population larger than largest, replaces
	    largest = j;						//largest = index for largest state
	 }
      }
   }

   if(strcmp(answer, "1") == 0){
      cout << "Largest state by population: " << states[largest].name << endl;
   }
   else if(strcmp(answer, "2") == 0){
      info_file << "Largest state by population: " << endl;
      info_file << states[largest].name << endl;
   }

}

/*****************************************
 * Function: largest_county_pop
 * Description: reads all counties and assigns largest 
 * index to the one with the greatest population
 * Parameters: states, num_states, answer, info_file
 * Pre-Conditions: none
 * Post-Conditions: none
 * Return: none
 * *************************************/

void largest_county_pop(state *states, int num_states, char *answer, ofstream &info_file){

   int largest_s = 0, largest_c = 0;
   for(int k = 0; k < num_states; k++){
      for(int i = 0; i < states[k].counties; i++){				//assigns largest to largest index
	 for(int j = 0; j < states[k].counties; j++){
	    if(states[k].c[j].population > states[largest_s].c[largest_c].population){
	       largest_s = k;
	       largest_c = j; 
	    }
	 }
      }
   }											//print or save largest index

   if(strcmp(answer, "1") == 0){
      cout << "Largest county by population: " << states[largest_s].c[largest_c].name << endl;
   }
   else if(strcmp(answer, "2") == 0){
      info_file << "Largest county by population: " << states[largest_s].c[largest_c].name << endl;
   }
}

/*****************************************
 * Function: county_income
 * Description: asks user for a minimum income and 
 * prints all counties whose average income is above that number
 * Parameters: states, num_states, answer, info_file
 * Pre-Conditions: none
 * Post-Conditions: none
 * Return: none
 * *************************************/

void county_income(state *states, int num_states, char *answer, ofstream &info_file){

   int min_income = 0;
   cout << "Enter the minimum income: " << endl;
   cin >> min_income;								//gets min from user

   if(strcmp(answer, "1") == 0){
      cout << "Counties with income above minimum income: " << endl;
   }
   else if(strcmp(answer, "2") == 0){
      info_file << "Counties with income above minimum income: " << endl;
   }

   for(int i = 0; i < num_states; i++){						//reads through county arrays and prints
      for(int j = 0; j < states[i].counties; j++){				//if avg_income is above min_income
	 if(states->c[j].avg_income >= min_income){
	    if(strcmp(answer, "1") == 0){
	       cout << states[i].c[j].name << endl;
	    }
	    else if(strcmp(answer, "2") == 0){
	       info_file << states[i].c[j].name << endl;
	    }
	 }
      }
   }
}

/*****************************************
 * Function: average_house
 * Description: prints out the average price of a house
 * for each county
 * Parameters: states, num_states, answer, info_file
 * Pre-Conditions: none
 * Post-Conditions: none
 * Return: none
 * *************************************/

void average_house(state *states, int num_states, char *answer, ofstream &info_file){

   for(int i = 0; i < num_states; i++){
      for(int j = 0; j < states[i].counties; j++){
	 if(strcmp(answer, "1") == 0){
	    cout << "Average house cost for " << states[i].c[j].name << ": " << states[i].c[j].avg_house << endl;
	 }
	 else if(strcmp(answer, "2") == 0){
	    info_file << "Average house cost for " << states[i].c[j].name << ": " << states[i].c[j].avg_house << endl;
	 }
      }
   }
}

/*****************************************
 * Function: sort_state_names
 * Description: sorts all states alphabetically 
 * Parameters: states, num_states, answer, info_file
 * Pre-Conditions: none
 * Post-Conditions: none
 * Return: none
 * *************************************/

void sort_state_names(state *states, int num_states, char *answer, ofstream &info_file){

   string *array = new string[num_states];
   for(int i = 0; i < num_states; i++){
      array[i] = states[i].name;				//create temporary array
   }
   if(strcmp(answer, "1") == 0){
      cout << "States alphabetically: " << endl;
   }
   else if(strcmp(answer, "2") == 0){
      info_file << "States alphabetically: " << endl;
   }

   string temp;
   for(int i = 0; i < num_states; i++){
      for(int j = 0; j < num_states; j++){
	 if(j == (num_states-1)){
	 }
	 else if(array[j] > array[j+1]){
	    swap(array[j], array[j+1]);						//swaps names in temp array to sort alphabetically
	 }
	 else if(states[j].name[0] == states[j+1].name[0]){
	    if((int)states[j].name[1] > (int)states[j+1].name[1]){		//checks second letter if first is the same
	       swap(array[j], array[j+1]);
	    }
	 } 
      }
   }

   for(int i = 0; i < num_states; i++){
      if(strcmp(answer, "1") == 0){							//print to screen or file
	 cout << array[i] << " " << endl;
      }

      else if(strcmp(answer, "2") == 0){
	 info_file << array[i] << " " << endl;
      }
   }
}

/*****************************************
 * Function: sort_state_population
 * Description: puts states in order based on population
 * Parameters: states, num_states, answer, info_file
 * Pre-Conditions: none
 * Post-Conditions: none
 * Return: none
 * *************************************/

void sort_state_population(state *states, int num_states, char *answer, ofstream &info_file){

   string *array = new string [num_states];
   for(int i = 0; i < num_states; i++){
      array[i] = states[i].name;				//creates temp array for names
   }

   if(strcmp(answer, "1") == 0){
      cout << "States by population: " << endl;
   }
   else if(strcmp(answer, "2") == 0){
      info_file << "States by population: " << endl;
   }

   for(int i = 0; i < num_states; i++){
      for(int j = 0; j < num_states; j++){
	 if(j != (num_states-1) && states[j].population > states[j+1].population){
	    swap(array[j], array[j+1]);							//swap array name if larger pop
	 }
      }
   }
   for(int i = 0; i < num_states; i++){
      if(strcmp(answer, "1") == 0){
	 cout << array[i] << endl;
      }
      else if(strcmp(answer, "2") == 0){
	 info_file << array[i] << endl;
      }
   }
}

/*****************************************
 * Function:sort_county_population
 * Description:puts counties in order by population
 * Parameters:states, num_states, answer, info_file
 * Pre-Conditions: none
 * Post-Conditions: none
 * Return:none
 * *************************************/

void sort_county_population(state *states, int num_states, char *answer, ofstream &info_file){

   int num_counties = 0;
   for(int i = 0; i < num_states; i++){
      num_counties = states[i].counties;		//assign variable
   }
   string *array = new string[num_counties];		//create temp array for names
   for(int i = 0; i < num_states; i++){
      for(int j = 0; j < states[i].counties; j++){
	 array[i] = states[i].c[j].name;
	 cout << array[i]<< endl;
      }
   }

   for(int i = 0; i < num_states; i++){

      if(strcmp(answer, "1") == 0){
	 cout << states[i].name << " counties by population: " << endl;
      }
      else if(strcmp(answer, "2") == 0){
	 info_file << states[i].name << " counties by population: " << endl;
      }											//swap names if pop is larger

      for(int k = 0; k < num_counties; k++){
	 if((k!= (num_counties-1))&& states[i].c[k].population > states[i].c[k+1].population){
	    swap(array[k], array[k+1]);
	 }
      }
   }
   for(int i = 0; i < num_counties; i++){
      if(strcmp(answer, "1") == 0){
	 cout << array[i] << endl;
      }
      else if(strcmp(answer, "2") == 0){
	 cout << array[i] << endl;
      }
   }
}

/*****************************************
 * Function: delete_info
 * Description: deletes city, county and state arrays
 * Parameters: *states, num_states
 * Pre-Conditions: none
 * Post-Conditions: none 
 * Return: none
 * *************************************/

void delete_info(state **states, int num_states){

   for(int i = 0; i < num_states; i++){
      for(int j = 0; j < (*states)[i].counties; j++){
	 delete [] (*states)[i].c[j].city;
      }
      delete [] (*states)[i].c;
   }
   delete [] (*states);

   states = NULL;
}
