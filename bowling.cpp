#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdlib>

using namespace std;

int get_players();
char** get_names(int);
int bowl();
int** create_scoreboard_array(int);
int frames(int**, int, char**, int**);
int** frame_score(char**, int**, int, int, int**);
int** current_frame_total(int**, int, int, int);
void print_scoreboard(char**, int**, int, int**, int**, int, int);
int** total(int**, int);

/**************************
 *Function: main
 *Description: declares all 2d arrays, and calls functions 
 get_players, get_names, scoreboard, and frames
 *Parameters: none
 *Pre-Conditions: none
 *Post-Conditions: none
 *Return: 0
 *************************/

int main(){

   char **names;
   int **scoreboard;
   int **total_score;
   int **ftotal;
   int curr_frame = 0;
   int num_players = get_players();
   names = get_names(num_players);
   scoreboard = create_scoreboard_array(num_players);
   curr_frame = frames(scoreboard, num_players, names, ftotal);

   return 0;
}

/**************************
 *Function: get_players
 *Description: gets num_players from user
 *Parameters: none
 *Pre-Conditions: none
 *Post-Conditions: none
 *Return: num_players
 *************************/
int get_players(){

   bool bad_input = false;
   int num_players = 0;
   do{
      cout << "How many players? (1-5): " << endl;
      cin >> num_players;
      if(num_players < 1 || num_players > 5){
         bad_input = true;
      }
      else {
	 bad_input = false;
      }
   }while(bad_input == true);

   return num_players;
}

/**************************
 *Function: get_names
 *Description: gets each player's name and stores names 
 in a char array
 *Parameters: num_players
 *Pre-Conditions: none
 *Post-Conditions: none
 *Return: names
 *************************/
char** get_names(int num_players){

   bool bad_input = false;
   char** names;
   names = new char*[num_players];
   do{
   cout << "Enter players names (less than 12 letters)" << endl;
   cin.ignore();
   for(int i = 0; i < num_players; i++){
      cout << "Player " << i+1 << "'s name: ";
      names[i] = new char[13];
      cin.getline(names[i], 12);
         if(strlen(names[i]) > 12){
	    bad_input = true;
	 }
      names[i][12] = '\0';
   }
   }while(bad_input == true);
   return names;
}

/**************************
 *Function: bowl
 *Description: generates a random number between 0 and (10-x)
 *Parameters: int x
 *Pre-Conditions: none
 *Post-Conditions: none
 *Return: int bowl
 *************************/
int bowl(int x){

   int bowl = 0;
   cout << "Press enter to bowl " << endl;
   cin.get();
   srand(time(NULL));
   bowl = rand()%(11-x);
   cout << "You knocked down " << bowl << " pins!" << endl;

   return bowl;
}

/**************************
 *Function: create_scoreboard_array
 *Description: creates 2d array to store bowl values
 *Parameters: num_players
 *Pre-Conditions: none
 *Post-Conditions: none
 *Return: scoreboard
 *************************/
int **create_scoreboard_array(int num_players){

   int **scoreboard;
   scoreboard = new int *[num_players];
   for(int i = 0; i < num_players; i++){
      scoreboard[i] = new int[21];
   }

   for(int i = 0; i < num_players; i++){
      for(int j = 0; j < 21; j++){
	 scoreboard[i][j] = 0;
      }
   }

   return scoreboard; 
}
/**************************
 *Function: frames
 *Description: loops through the number of frames and calls
 on function scoreboard
 *Parameters: scoreboard, num_players, **names
 *Pre-Conditions: none
 *Post-Conditions: none
 *Return: curr_frame
 *************************/

int frames(int **scoreboard, int num_players, char **names, int **ftotal){

   int num_frames = 10; 
   int curr_frame = 0;
   int num_throws = 21;
   for(int i = 1; i <= num_frames; i++){
      curr_frame = i;
      scoreboard = frame_score(names, scoreboard, num_players, curr_frame, ftotal);
   }

   return curr_frame;

}

/**************************
 *Function: frame_score
 *Description: loops through num_players and gives each player two 
 throws, assigns bowl values to scoreboard
 *Parameters: names, scoreboard, num_players, curr_frame
 *Pre-Conditions: none
 *Post-Conditions: none
 *Return: scoreboard
 *************************/

int **frame_score(char **names, int **scoreboard, int num_players, int curr_frame, int **ftotal){

   int **total_score;
   int num_frames = 10;
   int frame_total = 0;

   for(int i = 0; i < num_players; i++){
      cout << "Player " << i+1 << "'s turn" << endl;
      for(int j = 0; j < 2; j++){
	 if(j == 0){
	    scoreboard[i][(curr_frame - 1) * 2] = bowl(0);
	 }
	 else if(j == 1){
	    scoreboard[i][(curr_frame * 2) - 1] = bowl(scoreboard[i][(curr_frame - 1) * 2]);
	    frame_total = scoreboard[i][(curr_frame - 1) * 2] + scoreboard[i][(curr_frame * 2) - 1];
	 }
      }
      cout << "Frame total: " << frame_total << endl;
      ftotal = current_frame_total(scoreboard, num_players, curr_frame, frame_total);
      for(int k = 0; k < curr_frame; k++){
         ftotal[i][k] += frame_total;
      }
      cout << "197 frame total: " << ftotal[i][curr_frame] << endl;
      cout << "198 curr_frame " << curr_frame << endl;
      print_scoreboard(names, scoreboard, num_players, total_score, ftotal, curr_frame, frame_total);
   }

   return scoreboard;
}

int **current_frame_total(int **scoreboard, int num_players, int curr_frame, int frame_total){

   int num_frames = 10;
   int **ftotal;
   int a = 0;
   ftotal = new int *[num_players];

   for(int i = 0; i < num_players; i++){
      ftotal[i] = new int [num_frames];
   }
   
   for(int i = 0; i < num_players; i++){
      a = 0;
      for(int j = 0; j < (2 * curr_frame) - 1; j++){
         a += scoreboard[i][j];
      }
      for(int n = 0; n < curr_frame; n++){
         ftotal[i][n] = a;
      }
   }

   return ftotal;
}

/**************************
 *Function: total
 *Description: creates a total array and adds all the 
 scores for each player, assigns total values to total_score[i][0]
 *Parameters: scoreboard, num_players
 *Pre-Conditions: none
 *Post-Conditions: none
 *Return: total_score
 *************************/

int** total(int **scoreboard, int num_players){

   int **total_score;
   int total = 0;
   total_score = new int *[num_players];

   for(int i = 0; i < num_players; i++){
      total_score[i] = new int[21];
   }

   for(int i = 0; i < num_players; i++){
      total = 0;
      for(int j = 0; j < 21; j++){
	 total += scoreboard[i][j];
      }
      total_score[i][0] = total;
   }

   return total_score;
}

/**************************
 *Function: print_scoreboard
 *Description: prints scorechart after each players throws twice
 *Parameters: names, scoreboard, num_players, total_score
 *Pre-Conditions: none
 *Post-Conditions: none
 *Return: none
 *************************/

void print_scoreboard(char **names, int **scoreboard, int num_players, int** total_score, int **ftotal, int curr_frame, int frame_total){

   cout << "Names       1  | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10  | Total" << endl;

   for(int i = 0; i < num_players; i++){
      for(int j = 0; j < 12; j++){
	 cout << names[i][j];
      }
      for(int k = 0; k < (12 - strlen(names[i])); k++){
	 cout << " ";
      }
      for(int j = 0; j < 21; j++){
	 cout << scoreboard[i][j] << " ";
      }
      total_score = total(scoreboard, num_players);
      cout << total_score[i][0];
      cout << endl;
      cout << "              ";
      for(int n = 0; n < curr_frame; n++){
        cout << ftotal[i][n] << "   "; 
      }
      cout << endl;
   }
   cout << endl;
}

