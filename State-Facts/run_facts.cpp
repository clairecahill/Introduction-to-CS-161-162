#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>

using namespace std;

#include "state_facts.h"
/*****************************************
 * Function: main
 * Description: error checks, exits if bad error, calls functions, 
 * repeats if new filename is entered
 * Parameters: argc, argv
 * Pre-Conditions: none
 * Post-Conditions: none
 * Return: 0
 * **************************************/
int main(int argc, char **argv){
   int yesorno = 0;
   do{
      int num_states = 0, num_counties = 0;
      bool valid_arguments = is_valid_arguments(argv, argc);   //calls on error checking function
      char *file_location = new char [256];
      ifstream the_file;

      if(valid_arguments = false){                                //if there is an error, ends program
	 exit(0);
      }

      for(int i = 0; i < argc; i++){                              //finds -s and makes the next value num_states
	 if(strcmp(argv[i], "-s") == 0){
	    num_states = atoi(argv[i+1]);
	 }
      }

      while(num_states < 1){                                       
	 cout << "Please enter a positive, non-zero number for the amount of states: ";
	 cin >> num_states;
      }

      for(int i = 0; i < argc; i++){						
	 if(strcmp(argv[i], "-f") == 0){
	    file_location = argv[i+1];
	 }
      }

      the_file.open(file_location);

      if(the_file.fail()){									//check if filename is valid
	 cout << "The file is invalid. Please enter a valid file name: " << endl;
	 cin.getline(file_location, 256);
      } 

      state *states = create_states(num_states);
      get_state_data(states, num_states, the_file);

      delete_info(&states, num_states);

      the_file.close();

      cout << "Would you like to read another file? 1-yes or 0-no" << endl;
      cin >> yesorno;
      if(yesorno == 1){
	 cout << "Enter file name: " << endl;
	 cin.ignore();
	 cin.getline(file_location, 256);
      }
      else{
	 exit(0);
      }
   }while(yesorno == 1);
      return 0;
}
