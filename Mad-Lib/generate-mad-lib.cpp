/*************************
 * Program Filename: assignment6.cpp
 * Author: Claire Cahill
 * Date: 3/17/2017
 * Description: redirects the file input to read a word file
 * and randomly generates the words in a mad lib story
 * Input: command line arguments - executable, story number, file redirect
 * Output: mad lib story 
 * *********************/

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>

using namespace std;

void read_words(char*, char**&, char**&, char**&, char**&, char**&, int&, int&, int&, int&, int&);
char **create_noun_array();
char **create_verb_array();
char **create_adj_array();
char **create_verb_ing_array();
char **create_noun_s_array();
void story1(char*, char**, char**, char**, char**, char**, int, int, int, int, int);
void story2(char*, char**, char**, char**, char**, char**, int, int, int, int, int);
void story3(char*, char**, char**, char**, char**, char**, int, int, int, int, int);

/*************************
 * Function: main 
 * Description: handles errors in command line arguments
 * and goes to story 1, 2, or 3 based on user inputs
 * Parameters: argc, argv
 * Pre-Conditions: none
 * Post-Conditions: none
 * Return: 0
 * **********************/

int main(int argc, char *argv[]){

   int num_nouns = 0, num_verbs = 0, num_adj = 0, num_ing_verbs = 0, num_noun_s = 0;
   char *cat_words;
   char **nouns = create_noun_array();
   char **verbs = create_verb_array();
   char **adj = create_adj_array();
   char **noun_s = create_noun_s_array();
   char **verb_ing = create_verb_ing_array();

   cat_words = new char [30];

   if(argc < 2){ 				//error handling for too few arguments
      cout <<"Too few arguments." << endl;
      exit(0);
   }

   else if(argc > 2){				//error handling for too many arguments
      cout <<"Too many arguments." << endl;
      exit(0);
   }

   if(strcmp(argv[1], "1") == 0){
      story1(cat_words, nouns, verbs, adj, noun_s, verb_ing, num_nouns, num_verbs, num_adj, num_ing_verbs, num_noun_s);
   }

   else if(strcmp(argv[1], "2") == 0){				//go to story number chosen by user in command line
      story2(cat_words, nouns, verbs, adj, noun_s, verb_ing, num_nouns, num_verbs, num_adj, num_ing_verbs, num_noun_s);
     
   }

   else if(strcmp(argv[1], "3") == 0){
      story3(cat_words, nouns, verbs, adj, noun_s, verb_ing, num_nouns, num_verbs, num_adj, num_ing_verbs, num_noun_s);
   }

   else{
      cout << "You did not enter the information correctly." << endl;  //error if anything else is entered
      exit(0);
   }

   return 0;

}

/*************************
 * Function: read_words
 * Description: reads words from file and assigns them to an 
 * array based on it's conditions
 * Parameters: cat_words, nouns, verbs, adj, verb_ing, noun_s, num_nouns, num_verbs
 * num_adj, num_ing_verbs, num_noun_s
 * Pre-Conditions: none
 * Post-Conditions: none 
 * Return: none
 * **********************/

void read_words(char *cat_words, char **&nouns, char **&verbs, char **&adj, char **&verb_ing, char **&noun_s, int &num_nouns, int &num_verbs, int &num_adj, int& num_ing_verbs, int& num_noun_s){

   char *words = new char[30];

   while(cin.eof() != true){
      cin.getline(cat_words, 30, ' ');
      cin.getline(words, 30);

      if(cat_words[0] == 'n'){
	 if(nouns[num_nouns][strlen(nouns[num_nouns])-1] == 's'){
	    num_noun_s++;
	    strcpy(noun_s[num_noun_s], words);
	 }
	 else{
	    num_nouns++;
	    strcpy(nouns[num_nouns], words);
	 }
      }

      else if(cat_words[0] == 'v'){
	 if(verbs[num_verbs][strlen(verbs[num_verbs])-1] == 'g' 
	    && verbs[num_verbs][strlen(verbs[num_verbs])-2] == 'n' 
	    && verbs[num_verbs][strlen(verbs[num_verbs])-3] == 'i'){
	    num_ing_verbs++;
	    strcpy(verb_ing[num_ing_verbs], words);
	 }
	 else {
	    num_verbs++;
	    strcpy(verbs[num_verbs], words);
	 }
      }

      else if(cat_words[0] == 'a'){
	 num_adj++;
	 strcpy(adj[num_adj], words);
      }
   }
}

/*************************
 * Function: create_noun_array
 * Description: creates space in memory for noun array 
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none
 * Return: nouns
 * **********************/

char **create_noun_array(){

   char **nouns;
   nouns = new char *[25];		

   for(int i = 0; i < 25; i++){		//creating nouns array	
      nouns[i] = new char [30];
   }

   return nouns;
}

/*************************
 * Function: create_verb_array
 * Description: creates space in memory for verb array
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none
 * Return: verbs
 * **********************/

char **create_verb_array(){

   char **verbs;
   verbs = new char *[25];		

   for(int i = 0; i < 25; i++){		//creating verbs array	
      verbs[i] = new char [30];
   }

   return verbs;
}

/*************************
 * Function: create_adj_array
 * Description: creates space in memory for adjective array
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none
 * Return: adj
 * **********************/

char **create_adj_array(){

   char **adj;
   adj = new char *[25];

   for(int i = 0; i < 25; i++){  		//create adj array 
      adj[i] = new char [30];
   }

   return adj;

}

/*************************
 * Function: create_noun_s_array
 * Description: creates space in memory for plural nouns
 * Parameters: none
 * Pre-Conditions: none 
 * Post-Conditions: none
 * Return: noun_s
 * **********************/

char **create_noun_s_array(){

   char **noun_s; 
   noun_s = new char *[25];

   for(int i = 0; i < 25; i++){ 		//create array for nouns ending in s
      noun_s[i] = new char [30];
   }

   return noun_s;
}

/*************************
 * Function: create_verb_ing_array
 * Description: creates space in memory for verb_ing array
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none
 * Return: verb_ing
 * **********************/

char **create_verb_ing_array(){

   char **verb_ing; 
   verb_ing = new char *[25];			//create array for verbs ending in ing

   for(int i = 0; i < 25; i++){
      verb_ing[i] = new char [30];
   }

   return verb_ing;

}

/*************************
 * Functions: story1, story2, story3 
 * Description: takes in multiple arrays and prints out those 
 * arrays at random indexes to complete the mad lib story
 * Parameters: cat_words, nouns, verbs, adj, noun_s, verb_ing, num_nouns, 
 * num_verbs. num_adj, num_ing_verbs, num_noun_s
 * Pre-Conditions: arrays must exist and hold space in memory
 * Post-Conditions: none
 * Return: none
 * **********************/

void story1(char *cat_words, char **nouns, char **verbs, char **adj, char **noun_s, char **verb_ing, int num_nouns, int num_verbs, int num_adj, int num_ing_verbs, int num_noun_s){

   read_words(cat_words, nouns, verbs, adj, verb_ing, noun_s, num_nouns, num_verbs, num_adj, num_ing_verbs, num_noun_s);
   srand(time(NULL));

   cout << "Most doctors agree that " << verb_ing[rand()%(num_ing_verbs)+1] << " is a ";
   cout << adj[rand()%(num_adj)+1] << " form of exercise. " << verb_ing[rand()%(num_ing_verbs)+1] << " a bicycle enables ";
   cout << "you to develop your " << nouns[rand()%(num_nouns)+1] << " muscles, as well as increase the rate ";
   cout << "of your " << nouns[rand()%(num_nouns)+1] << " beat. More "; 
   cout << noun_s[rand()%(num_noun_s)+1] << " around the world ";
   cout << verbs[rand()%(num_verbs)+1] << " bicycles than drive " << noun_s[rand()%(num_noun_s)+1]; 
   cout << ". No matter what kind of ";
   cout << nouns[rand()%(num_nouns)+1] << " you " << verbs[rand()%(num_verbs)+1]; 
   cout << ", always be sure you wear a/an " << adj[rand()%(num_adj)+1] << " helmet. ";
   cout << "Make sure to have " << adj[rand()%(num_adj)+1] << " reflectors too!" << endl;

}

void story2(char *cat_words, char **nouns, char **verbs, char **adj, char **noun_s, char **verb_ing, int num_nouns, int num_verbs, int num_adj, int num_ing_verbs, int num_noun_s){

   read_words(cat_words, nouns, verbs, adj, verb_ing, noun_s, num_nouns, num_verbs, num_adj, num_ing_verbs, num_noun_s);
   srand(time(NULL));

   cout << "Yesterday " << nouns[rand()%(num_nouns)+1] << " and I went to the park. ";
   cout << "On our way to the " << adj[rand()%(num_adj)+1] << " park, we saw a ";
   cout << adj[rand()%(num_adj)+1] << " " << nouns[rand()%(num_nouns)+1] << " on a bike. ";
   cout << "We also saw big " << adj[rand()%(num_adj)+1] << " balloons tied to a " << nouns[rand()%(num_nouns)+1] << ". ";
   cout << "Once we got to the " << adj[rand()%(num_adj)+1] << " park, the sky turned " << adj[rand()%(num_adj)+1] << ".";
   cout << " It started to " << verbs[rand()%(num_verbs)+1] << " and " << verbs[rand()%(num_verbs)+1] << ". ";
   cout << nouns[rand()%(num_nouns)+1] << " and I " << verbs[rand()%(num_verbs)+1] << " all the way home. Tomorrow ";
   cout << "we will try to go to the " << adj[rand()%(num_adj)+1] << " park again and hope it doesn't ";
   cout << verbs[rand()%(num_verbs)+1] << "." << endl;

}


void story3(char *cat_words, char **nouns, char **verbs, char **adj, char **noun_s, char **verb_ing, int num_nouns, int num_verbs, int num_adj, int num_ing_verbs, int num_noun_s){
   
   read_words(cat_words, nouns, verbs, adj, verb_ing, noun_s, num_nouns, num_verbs, num_adj, num_ing_verbs, num_noun_s);
   srand(time(NULL));

   cout << "Spring break 2017, oh how I have been waiting for you! Spring break is when you go to some " << adj[rand()%(num_adj)+1];
   cout << " place to spend some time with " << nouns[rand()%(num_nouns)+1] << ". Getting to " << nouns[rand()%(num_nouns)+1];
   cout << " is going to take " << adj[rand()%(num_adj)+1] << " hours. My favorite part of spring break is ";
   cout << verb_ing[rand()%(num_ing_verbs)+1] << " in the " << nouns[rand()%(num_nouns)+1] << ". ";
   cout << "During spring break, " << nouns[rand()%(num_nouns)+1] << " and I plan to " << verbs[rand()%(num_verbs)+1];
   cout << " all the way to " << nouns[rand()%(num_nouns)+1] << ". After spring break, I will be ready to return ";
   cout << "to " << nouns[rand()%(num_nouns)+1] << " and " << verbs[rand()%(num_verbs)+1] << " hard to finish ";
   cout << nouns[rand()%(num_nouns)+1] << ". Thanks spring break 2017!" << endl;

}
