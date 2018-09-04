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

using namespace std;

int start_game(string);
int get_players();
int get_rounds();
void get_message(string*);
string _message(ifstream&); 
void guessed_message(string, string*);
int replace_letters(string, string*);
void set_game(string*, string*);
void play(int&, int&, string, string*, bool*);
void turn(int, string, string*, int&, int&, int&, bool*);
bool player(string, string*, bool*, int, int&);
char choose();
bool spin(int, string, string*, int, int&, bool);
string solve(string);
bool vowel(int, string, string*, int&, bool);
void end_round(int, int&, int&, int&, int);
void end_game(int, int, int, int);

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
   //int num_players = get_players();
   //int num_rounds = get_rounds();
   int file_num = (rand() % 6);
   //string filename = "file" + file_num + ".txt";
   
   char filename[10] = "file0.txt";
   ifstream game_file;
   game_file.open(filename);
   
   int game_arr[num_players]; // = new int[num_players];

   for(int i = 0; i < num_rounds; i++){

      int round_arr[num_players]; // = new int[num_players];

      message = _message(game_file);

      cout << message << endl;

      while(*solved == false){
         for(int ii = 0; i < num_players; ii++){
	  //  execute_turn()
	 }
      }



   }
  // play(num_players, num_rounds, message, &copy, &solved);

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

/************************************
 * Function: get_players
 * Description: user enters a number between 1-3 that is referenced throughout the game
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none
 * Return: num_players
 * *********************************/

int get_players(){

   char num_players;
   int players;
   bool good_input = false;
   cout << "Welcome to a new game of Wheel of Fortune!" << endl;

   while(good_input == false){
      cout << "Enter number of players (1-3): " << endl;
      cin >> num_players;
      players = (int)num_players;

      if(players < 49 || players > 51){
	 cout << "Please enter a number between 1-3." << endl;
	 continue;
      }
      else{
	 good_input = true;
	 break;
      }
   }

   return players;
}

/************************************
 * Function: get_rounds
 * Description: user enters number of rounds that is referenced later in the program
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none
 * Return: num_rounds
 * *********************************/

int get_rounds(){

   int num_rounds = 0;
   cout << "Enter how many rounds will be played: " << endl;
   cin >> num_rounds;

   return num_rounds;
}

string _message(ifstream& file){

   string phrase = "";

   getline(file, phrase);

   return phrase;
}

/************************************
 * Function: get_message
 * Description: user enters a message that the players of have to guess 
 * throughout the game. this message is referenced many times during the program, so it has to be a pointer
 * Parameters: string* message
 * Pre-Conditions: none
 * Post-Conditions: none
 * Return: none
 * *********************************/

/*void get_message(string* message){

   char x;
   bool bad_input; //error handling
   do{
      bad_input = false;
      cout << "Have a non-player enter a message for this round: " << endl;
      cin.ignore();
      getline(cin, *message);

      for(int i = 0; i < (*message).size(); i++){ //changes all the letters in the message to lowercase
	 (*message)[i] = tolower((*message)[i]);
      }

      for(int i = 0; i < (*message).size(); i++){ //searches all chars in message
	 x = (*message).at(i);
	 if((int)x != 32 && (int)x < 65 || (int)x > 122){         //if a char in the message is not A-Z or a-z, loop repeats
	    cout << "Invalid input, try again." << endl;
	    bad_input = true;
	 }   
      }
   }while(bad_input == true);
}*/

/************************************
 * Function: guessed_message
 * Description: takes the address of message and changes all the letters to 
 * dashes (spaces remain spaces). the dashed version of the message is then stored as the pointer copy. 
 * copy and message are used throughout the program as letters are guessed 
 * Parameters: string message, string* copy
 * Pre-Conditions: user must enter a message in get_message
 * Post-Conditions: none
 * Return: none
 * *********************************/

void guessed_message(string message, string* copy){

   for(int i = 0; i < message.size(); i++){ 
      if(message.at(i) != ' '){ //ignores the spaces
	 message[i] = '-';     //changes letters in the message to dashes 
      }
      *copy = message;
   }
   cout << *copy << endl;
}

/************************************
 * Function: replace_letters
 * Description: prompts user for a character to guess and searches message for 
 * that letter. the pointer copy is then modified to reveal all the places where the letter exists. x is
 * a integer that counts how many times the letter appears in the message (and is the return value).
 * Parameters: string message, string* copy
 * Pre-Conditions: user must enter a message, copy should exist as dashes
 * Post-Conditions: none
 * Return: x
 * *********************************/

int replace_letters(string message, string* copy){

   char a; int x = 0, i = 0;
   string str;
   bool bad_input;    //error handling
   do{
      bad_input = false;
      cout << "Guess a consonant: " << endl;
      cin >> a;
      a = tolower(a);     //changes to lowercase
      if(a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u'){  //repeats loop if user enters a vowel
	 cout << "That is not a consonant, try again." << endl;
	 bad_input = true;
      }
   }while(bad_input == true);
   for(int i = 0; i < message.size(); i++){  //replaces dashes with letters found
      if(message.at(i) == a){
	 copy->at(i) = a;
	 x++;
      }
   }	
   if(x == 0){
      cout << "That letter is not in the message." << endl;
   }

   cout << *copy << endl;
   return x;   //amount of letters found in the message
}

/************************************
 * Function: set_game 
 * Description: used in the play function to get the message from the user, 
 * clear the screen, and display the dashed version of the message (copy)
 * Parameters: string message, string* copy
 * Pre-Conditions: none
 * Post-Conditions: none
 * Return: none
 * *********************************/

void set_game(string* message, string* copy){

  // get_message(message);
   for(int i = 0; i < message->size(); i++){   //changes the message to lowercase
      (*message)[i] = tolower((*message)[i]);
   }
   system("clear");    //clears the screen so players cannot see secret message
   guessed_message(*message, copy);

}

/************************************
 * Function: play 
 * Description: contains the for loop for the amount of rounds, calls on set game to get 
 * a new message for each round, sets a bool pointer to false. this is changed to true
 * when a player guesses the message and breaks out of the loop to go to a new round. calls
 * on turn function to continue 
 * Parameters: int& num_players, int& num_rounds, string message, string* copy, bool* solved
 * Pre-Conditions: must have num_players, num_rounds, message, and copy entered by user
 * Post-Conditions: solved must be true to exit loop
 * Return: none
 * *********************************/

void play(int& num_players, int& num_rounds, string message, string* copy, bool* solved){

   int p1_gametotal = 0, p2_gametotal = 0, p3_gametotal = 0;
   int p1_money = 0, p2_money = 0, p3_money = 0;
   for(int j = 1; j <= num_rounds; j++){
      p1_money = 0;    //resets all player round totals to zero after each round
      p2_money = 0; 
      p3_money = 0;
      cout << "Round " << j << ":" << endl;
      set_game(&message, copy);
      for(int i = 0; i < message.size(); i++){
	 message[i] = tolower(message[i]);
      }
      *solved = false;
      while(*solved == false){
	 turn(num_players, message, copy, p1_money, p2_money, p3_money, solved);
      }

      p1_gametotal += p1_money;
      p2_gametotal += p2_money;
      p3_gametotal += p3_money;
   }
   end_game(num_players, p1_gametotal, p2_gametotal, p3_gametotal);
}      

/************************************
 * Function: turn
 * Description: sets solved bool to false and continue_p1 to false. these repeat a players turn and 
 * the solved bool is a pointer to change the bool in the play function to exit the rounds loop. turn 
 * calls on player function based on the amount of players the user inputs. when the puzzle is solved, 
 * the end_round function is called
 * Parameters: num_players, string message, string* copy, int& p1_money, p2_money, p3_money, bool* solved
 * Pre-Conditions: must have num_players, message, and copy
 * Post-Conditions: other functions use p1, p2, p3 money
 * Return: none
 * *********************************/

void turn(int num_players, string message, string* copy, int& p1_money, int& p2_money, int& p3_money, bool* solved){

   int i = 1, answer = 0, x = 0, a = 0, winner = 0;
   bool continue_p1 = false, continue_p2 = false, continue_p3 = false;
   *solved = false;

   while(continue_p1 == false && *solved == false){
      cout << "Player 1 turn:" << endl;
      continue_p1 = player(message, copy, solved, 1, p1_money); 
      if(*solved == true){
	 end_round(num_players, p1_money, p2_money, p3_money, 1);
      }
   }

   if(num_players > 1 && *solved == false){ 
      while(continue_p2 == false){ 
	 cout << "Player 2 turn:" << endl;
	 continue_p2 = player(message, copy, solved, 2, p2_money);
	 if(*solved == true){
	    end_round(num_players, p1_money, p2_money, p3_money, 2);
	 }
      }
   }		 

   if(num_players > 2 && *solved == false){
      while(continue_p3 == false){
	 cout << "Player 3 turn:" << endl;
	 continue_p3 = player(message, copy, solved, 3, p3_money);
	 if(*solved == true){
	    end_round(num_players, p1_money, p2_money, p3_money, 3);
	 }   
      }
   }
}

/************************************
 * Function: player
 * Description: executes game, calls on "menu" or choose function and repeats for the 
 * same player as they guess correctly
 * Parameters: message, copy, solved (bool), num_players, and money
 * Pre-Conditions: must have a message and a copy, and num_players
 * Post-Conditions: none
 * Return: continue_p1 or solved
 * *********************************/

bool player(string message, string* copy, bool* solved, int num_players, int& money){

   int p1_money = 0, p2_money = 0, p3_money = 0;
   int a = 0, x = 0;
   string solve_puzzle;
   char answer; 
   bool continue_p1 = false; 
   *solved = false;
   while(continue_p1 == false){
      answer = choose();
      if(answer == 49){  //uses ascii values from the choose() function
	 continue_p1 = spin(a, message, copy, num_players, money, continue_p1);
	 return continue_p1;
      }

      else if(answer == 50){
	 solve_puzzle = solve(message);
	 if(solve_puzzle == message){
	    *solved = true;
	    return *solved;
	 }
	 else if(solve_puzzle != message){
	    cout << "Incorrect" << endl;
	    continue_p1 = true;
	    return continue_p1;
	 }
      }
      else if(answer == 51){
	 if(money < 10){
	    cout << "You need $10 to buy a vowel." << endl;
	    continue_p1 = false;
	 }
	 else if(money >= 10){
	    continue_p1 = vowel(num_players, message, copy, money, continue_p1);
	 }
	 return continue_p1;
      }
   }
}

/************************************
 * Function: choose
 * Description: menu option for player, uses ascii values for error handling
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none
 * Return: char answer
 * *******************************/

char choose(){

   char answer;
   bool bad_input = false;
   do{
      cout << "Would you like to spin (1), solve the puzzle (2), or buy a $10 vowel (3): " << endl;
      cin >> answer;
      if((int)answer < 49 || (int)answer > 51){
	 cout << "Invalid input, try again." << endl;
	 bad_input = true;
      }
      else
	 bad_input = false;
      break;
   }while(bad_input == true);

   return answer;
}

/************************************
 * Function: spin
 * Description: generates a random number and calls replace letters for
 * the player to guess and letter. multiplies random number by the integers for
 * the amount of letters found in the message (that is the money). player loses
 * turn when the wheel lands on 0 or 21 or when they guess a letter not in the message
 * Parameters: int a, message, copy, num_players, money, continue_p1
 * Pre-Conditions: musts have a message, copy, and num_players
 * Post-Conditions: continue_p1 must be true
 * Return: continue_p1 (as true)
 * *********************************/

bool spin(int a, string message, string* copy, int num_players, int& money, bool continue_p1){

   int x = 0;
   continue_p1 = false;
   srand(time(NULL));    
   a = rand()%22;       //spin the wheel!
   cout << "The wheel landed on " << a << endl;
   if(a == 0){
      cout << "Uh oh, you've gone bankrupt (dang)." << endl;
      money = 0;
      continue_p1 = true;
   }
   else if(a == 21){
      cout << "Lose a turn (dang)." << endl;
      continue_p1 = true;
   }
   else if(a > 0 && a < 21){
      x = replace_letters(message, copy);
      cout << "Letters found in message: " << x << endl;
      money += x * a;
      cout << "Player " << num_players << " total money: $" << money << endl;
      if(x == 0){
	 continue_p1 = true;
      }   
   }

   return continue_p1;
}

/************************************
 * Function: solve
 * Description: gets an input from the user to use in other functions
 * Parameters: string message
 * Pre-Conditions: must have a message
 * Post-Conditions: none
 * Return: solve_puzzle
 * *********************************/

string solve(string message){

   string solve_puzzle;
   cout << "Guess the message: " << endl;
   cin.ignore();
   getline(cin, solve_puzzle);
   for(int i = 0; i < solve_puzzle.size(); i++){
      solve_puzzle[i] = tolower(solve_puzzle[i]);
   }

   return solve_puzzle;
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

bool vowel(int num_players, string message, string* copy, int& money, bool continue_p1){

   char v;
   int x = 0;
   bool bad_input;
   do{
      cout << "Guess a vowel: " << endl;
      cin >> v;
      v = tolower(v);
      if(v != 'a' && v!= 'i' && v != 'e' && v!= 'o' && v != 'u'){
	 cout << "That is not a vowel, try again." << endl;
	 bad_input = true;
      }
   }while(bad_input == true);

   for(int i = 0; i < message.size(); i++){
      if(message.at(i) == v){
	 copy->at(i) = v;
	 x++;
	 cout << *copy << endl;
      }
   }   
   money = money - 10;
   if(x == 0){
      continue_p1 = true;	
   }
   if(x == 0){
      cout << "That letter is not in the message." << endl;
      continue_p1 = true;
   }
   cout << "Player " << num_players << " total money: $" << money << endl;
   return continue_p1;
}

/************************************
 * Function: end_round
 * Description: determines who is the winner and makes all other totals 0 
 * Parameters: num_players, p1_money, p2_money, p3_money, and winner
 * Pre-Conditions: all the parameters must be entered
 * Post-Conditions: none
 * Return: none
 * *********************************/

void end_round(int num_players, int& p1_money, int& p2_money, int& p3_money, int winner){

   switch (winner){
      case 1: 
	 p2_money = 0;
	 p3_money = 0;
	 cout << "Player 1 wins the round!" << endl;
	 break;
      case 2:
	 p1_money = 0;
	 p3_money = 0;
	 cout << "Player 2 wins the round!" << endl;
	 break;
      case 3:
	 p2_money = 0;
	 p1_money = 0;
	 cout << "Player 3 wins the round!" << endl;
	 break;	 
   }
   cout << "Player 1 round total: $" << p1_money << endl;
   if(num_players > 1)
      cout << "Player 2 round total: $" << p2_money << endl;
   if(num_players > 2)
      cout << "Player 3 round total: $" << p3_money << endl;
}

/************************************
 * Function: end_game
 * Description: takes the total game earnings and compares each player's. the player 
 * with the highest amount of money at the end of the all the rounds wins. 
 * Parameters: num_players, p1_gametotal, p2_gametotal, and p3_gametotal, 
 * Pre-Conditions: num_players must be entered and gametotals must exist
 * Post-Conditions: none
 * Return: none
 * *********************************/

void end_game(int num_players, int p1_gametotal, int p2_gametotal, int p3_gametotal){

   if(p1_gametotal > p2_gametotal && p1_gametotal > p3_gametotal){
      cout << "Player 1 wins the game!!" << endl;
   }   
   else if(p2_gametotal > p1_gametotal && p2_gametotal > p3_gametotal){
      cout << "Player 2 wins the game!!" << endl;
   }
   else if(p3_gametotal > p1_gametotal && p3_gametotal > p2_gametotal){
      cout << "Player 3 wins the game!!" << endl;
   }

   cout << "Player 1 game total: $" << p1_gametotal << endl;
   if(num_players == 2){
      cout << "Player 2 game total: $" << p2_gametotal << endl;
   }
   else if(num_players == 3){
      cout << "Player 2 game total: $" << p2_gametotal << endl;
      cout << "Player 3 game total: $" << p3_gametotal << endl;
   }
}
