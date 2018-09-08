/* Program: assignment4.cpp
 * Author: Claire Cahill
 * Date: 2/24/2017
 * Description: Wheel of Fortune!! Players go through 
 * the game trying to guess a hidden message
 * Input: User inputs number of players, rounds, and guessed letters
 * Output: Program takes user through game and reveals 
 * the letters as the user guesses them correctly*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <locale>
#include <cstring>

using namespace std;

int start_game(string);
int get_players();
int get_rounds();
void get_message(string*);
string _message(ifstream&); 
void init_copy(string, string*);
int play_round(string, string*, int, int[]);
int execute_turn(string, string*, int, int[], int, bool*);
int guess_consonant(string, string*, bool*);
void print_results(int[], int);

int end_game(int, int[], string);
void menu(int, string, string*, int, int[], bool*, int, bool*);
void display_rules();
char choose();
void spin(string, string*, int, int[], bool*, int);
void solve(string, bool*, bool*);
void vowel(string, string*, int[], int, bool*);

/************************************
 * Function: main
 * Description: starts program
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none
 * Return: 0
 * *********************************/

int main(){

   string message, copy;
   bool* solved = new bool(solved);
   int x = 0, a = 0;
   cout << "Welcome to a new game of Wheel of Fortune!" << endl;
   int num_players = start_game("players");
   int num_rounds = start_game("rounds");

   srand(time(NULL));
   int file_num = (rand() % 6);

   char filename[10] = "file";
   char int_chararray[3];

   sprintf(int_chararray, "%d", file_num);
   strcat(filename, int_chararray);
   strcat(filename, ".txt");


   ifstream game_file;
   game_file.open(filename);

   int* game_arr= new int[num_players];
   int* round_arr = new int[num_players]; // = new int[num_players];

   for(int j = 0; j < num_players; j++){
   
      game_arr[j] = 0;
   }

   for(int i = 0; i < num_rounds; i++){

      for(int ii = 0; ii < num_players; ii++){

	 round_arr[ii] = 0;
      }

      message = _message(game_file);
      copy = message;

      init_copy(message, &copy);

      cout << "Message to be guessed: " << copy << endl;

      int winner = play_round(message, &copy, num_players, round_arr);


      game_arr[winner] += round_arr[winner];

      cout << "**** Game total results ****" << endl;
      print_results(game_arr, num_players);

   }

   int final_winner = end_game(num_players, game_arr, "game");
   delete[] game_arr;
   delete[] round_arr;

   return 0;
}

int start_game(string text){

   int number = 0;
   bool bad_input;

   do{


      cout << "Enter number of " << text << " (1-3): ";
      cin >> number;
      bad_input = cin.fail();

      cin.clear();
      cin.ignore(256, '\n');

      if(bad_input){
	 cout << "Enter a valid number." << endl;
      } else {
	 if(number < 1 || number > 3){
	    cout << "Enter number between 1-3." << endl;
	    bad_input = true;
	 }
      }
   }while(bad_input == true);

   return number;
}

string _message(ifstream& file){

   string phrase = "";

   getline(file, phrase);

   return phrase;
}

void init_copy(string message, string* copy){

   for(int i = 0; i < message.size(); i++){
      if(message.at(i) != ' '){
	 copy->at(i) = '-';
      }
   }

}

int play_round(string message, string* copy, int num_players, int round_arr[]){

   bool solved = false;
   int winner = 0, player = 0;
   while(solved == false){
   for(int i = 0; i < num_players; i++){
      if(solved == false){
	 player = execute_turn(message, copy, i, round_arr, num_players, &solved);
	 if(solved == true){
	    winner = player;
	    cout << "The winner of the round " << winner + 1 << "!!!" << endl;
	 }
      } 
   }
   }

   return winner;
}

int execute_turn(string message, string* copy, int player, int round_arr[], int num_players, bool* solved){

   bool continue_turn = true;

   while(continue_turn){

      if(*solved == false){

	 bool bad_input;
	 print_results(round_arr, num_players);

	 do{

	    cout << endl << "Player " << player + 1 << endl;

	    cout << endl << "Would you like to ..." << endl;
	    cout << "1) Spin the wheel" << endl;
	    cout << "2) Buy a vowel" << endl;
	    cout << "3) Solve the puzzle" << endl;

	    int input;
	    cin >> input;

	    bad_input = cin.fail();

	    if(bad_input == true){
	       cout << "Please enter a valid integer." << endl;
	       cin.clear();
	       cin.ignore(256, '\n');
	    }
	    else if(input < 1 || input > 3){
	       cout << "Enter a valid option." << endl;  
	       cin.clear();
	       cin.ignore(256, '\n');
	       bad_input = true;
	    } else {

	       if(input == 2 && round_arr[player] < 10){

		  cout << "You need at least $10 to buy a vowel." << endl;
		  bad_input = true;

	       } else {

		  bad_input = false;
		  menu(input, message, copy, player, round_arr, &continue_turn, num_players, solved);
		  if(*solved == true){
		    continue_turn = false;
		    return player;
		  }
	       }
	    }
	 }while(bad_input == true);
      }
   }

}

void menu(int option, string message, string* copy, int player, int round_arr[], bool* cont_turn, int num_players, bool* solved){

   switch(option){
      case 1:
	 spin(message, copy, player, round_arr, cont_turn, num_players);
	 break;
      case 2:
	 vowel(message, copy, round_arr, player, cont_turn);
	 break;
      case 3:
	 solve(message, solved, cont_turn);
	 break;
      default:
	 break;
   }
}

void spin(string message, string* copy, int player, int round_arr[], bool* cont_turn, int num_players){

   srand(time(NULL));
   int wheel_num = rand() % 22;
   cout << "The wheel landed on " << wheel_num << "!" << endl;

   if(wheel_num == 0){ 

      *cont_turn = false;
      cout << "Uh oh, you lose your turn and your round earnings." << endl;
      round_arr[player] = 0;

   } else if(wheel_num == 21){

      *cont_turn = false;
      cout << "Uh oh, your turn is over." << endl;

   } else { 

      int num = guess_consonant(message, copy, cont_turn);
      cout << "You found " << num << " letters in the message !" << endl;
      cout << *copy << endl;
      round_arr[player] += (num * wheel_num);

   }
}

void print_results(int round_arr[], int num_players){

   cout << endl << "**********************" << endl;
   for(int i = 0; i < num_players; i++){
      cout << "*  Player " << i + 1 << ": $" << round_arr[i] << endl;
   }
   cout << "**********************" << endl << endl;

}

/************************************
 * Function: guess_constant
 * Description: prompts user for a character to guess and searches message for 
 * that letter. the pointer copy is then modified to reveal all the places where the letter exists. x is
 * a integer that counts how many times the letter appears in the message (and is the return value).
 * Parameters: string message, string* copy
 * Pre-Conditions: user must enter a message, copy should exist as dashes
 * Post-Conditions: copy is changed to hold the letters found
 * Return: found
 * *********************************/

int guess_consonant(string message, string* copy, bool* cont_turn){

   int found = 0;
   string str;
   char a;
   bool bad_input;    //error handling
   do {
      cout << *copy << endl;
      cout << "Guess a consonant: " << endl;
      cin >> str;

      if(str.length() != 1){

	 bad_input = true;
	 cout << "Enter a valid character." << endl;

      } else {

	 a = str[0];
	 a = tolower(a);
	 if(a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u'){
	    cout << "That is not a consonant, try again." << endl;
	    bad_input = true;
	 } else {
	    bad_input = false;
	 } 
      }

   }while(bad_input == true);

   for(int i = 0; i < message.size(); i++){  //replaces dashes with letters found
      if(message.at(i) == a){
	 copy->at(i) = a;
	 found++;
      }
   }	
   if(found == 0){
      *cont_turn = false;
   }

   return found;   //amount of letters found in the message
}

void display_rules(){

   cout << "function to be written!!" << endl;
}

/************************************
 * Function: solve
 * Description: gets an input from the user to use in other functions
 * Parameters: string message
 * Pre-Conditions: must have a message
 * Post-Conditions: none
 * Return: solve_puzzle
 * *********************************/

void solve(string message, bool* solved, bool* cont_turn){

   string solve_puzzle;
   cout << "Guess the message: " << endl;
   cin.ignore();
   getline(cin, solve_puzzle);
   for(int i = 0; i < solve_puzzle.size(); i++){
      solve_puzzle[i] = tolower(solve_puzzle[i]);
      if(solve_puzzle[i] != message[i]){
	 *solved = false;
	 *cont_turn = false;
	 break;
      } 
   } 

   if(solve_puzzle == message){
      *solved = true;
   }
}

/************************************
 * Function: vowel
 * Description: similar to replace_letters, counts how many times the vowel
 * is found in the message. subtracts 10 from the player's money
 * Parameters: num_players, message, copy, money, continue_p1
 * Pre-Conditions: continue_p1 must be false
 * Post-Conditions: money must be decreased by 10
 * Return: continue_p1
 * *********************************/

void vowel(string message, string* copy, int round_arr[], int player, bool* cont_turn){

   char v;
   string str;
   int found = 0;
   bool bad_input;

   round_arr[player] -= 10;

   do{
      cout << "Guess a vowel: " << endl;
      cin >> str;

      if(str.length() != 1){

	 bad_input = true;
	 cout << "Enter a valid character." << endl;

      } else {
	 v = str[0];
	 v = tolower(v);
	 if(v != 'a' && v!= 'i' && v != 'e' && v!= 'o' && v != 'u'){
	    cout << "That is not a vowel, try again." << endl;
	    bad_input = true;
	 } else {
	    bad_input = false;
	 }
      }
   }while(bad_input == true);

   for(int i = 0; i < message.size(); i++){
      if(message.at(i) == v){
	 copy->at(i) = v;
	 found++;
      }
   }   

   if(found == 0){
      cout << "That letter is not in the message." << endl;
      *cont_turn = false;
   } else {
      cout << "You found " << found << " letters in the message." << endl;
      *cont_turn = true;
   }

   cout << *copy << endl;

}

int end_game(int num_players, int array[], string text){

   int winner = 0;
   int highest = 0;
   for(int i = 0; i < num_players; i++){
      if(array[i] > highest){
         highest = array[i];
	 winner = i;
      }
   }

   cout << "The winner of the " << text << " player " << winner+1 << "!!!" << endl;
   return winner;

}
