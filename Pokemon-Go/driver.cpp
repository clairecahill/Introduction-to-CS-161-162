/********************************
 * Program: driver.cpp
 * Author: claire cahill
 * Date: 5/24/17
 * Description: simulates a game similar
 * to pokemon go
 * Input: command line args, move, throw pokeballs
 * Output: game is displayed
 * ******************************/

#include "driver.h"

/**********************************
 * Function: main
 * Description: starts game
 * Parameters: argc, argv
 * Pre-Conditions: none
 * Post-Conditions: none
 * *************************/

int main(int argc, char * argv[]){

   check_command_line(argc, argv);
   int height = atoi(argv[1]);
   int width = atoi(argv[2]);
   bool m = false;
   Trainer t;
   Location **map = create_map(height, width);
   set_map(height, width, map);
   t.set_pokemon();
   t.set_megastone(m);
   play_game(height, width, map, t);
   for(int i = 0; i < width; i++){
      delete map[i];
   }
   delete [] map;

   return 0;
}

/*******************************
 * Function: check_command_line
 * Description: error handles command line args
 * Parameters: argc, argv
 * Pre-Conditions: none
 * Post-Conditions: none
 ******************************/

void check_command_line(int argc, char** argv){

   if(argc > 3 || argc < 3){
      cout << "Incorrect amount of arguments." << endl;
      exit(0);
   }

   if(*argv[1] < 52 || *argv[1] > 57){
      cout << "Incorrect arguments." << endl;
      exit(0);
   }

   if(*argv[2] < 52 || *argv[2] > 57){
      cout << "Incorrect arguments." << endl;
      exit(0);
   }
}

/**********************************
 * Function: create_map
 * Description: creates a 2d array of locations
 * Parameters: height, width
 * Pre-Conditions: location class must exist
 * Post-Conditions: none
 * ********************************/

Location** create_map(int height, int width){

   Location **map = new Location*[width];
   for(int i = 0; i < width; i++){
      map[i] = new Location[height];
   }

   return map;
}

/**********************************
 * Function: start_locations
 * Description: sets all locations to null
 * then assigns certain events to random locations
 * Parameters: height, width, map
 * Pre-Conditions: location class must exist
 * Post-Conditions: none
 * ********************************/

void start_locations(int height, int width, Location **map){

   int h = rand() % height;
   int w = rand() % width;
   int total = height * width;
   for(int i = 0; i < width; i++){
      for(int j = 0; j < height; j++){
	 map[i][j].set_event("nothing");
      }
   }
}

/*********************************
 * Function: set_map
 * Description: calls functions to assign values to event *
 * Parameters: height, width, map
 * Pre-Conditions: location class must exist
 * Post-Conditions: none
 * ******************************/

void set_map(int height, int width, Location **map){

   int h = rand()%height;
   int w = rand()%width;
   bool assigned = false;
   start_locations(height, width, map);
   start_cave(height, width, map);
   start_pokestop(height, width, map);
   start_rock(height, width, map);
   start_flying(height, width, map);
   start_psychic(height, width, map);
}

/*********************************
 * Function: start_cave
 * Description: assigns cave to event array
 * Parameters: height, width, map
 * Pre-Conditions: location class must exist
 * Post-Conditions: none
 * ******************************/

void start_cave(int height, int width, Location **map){

   bool assigned = false;
   srand(time(NULL));
   int h = 0;
   int w = 0;
   do{
      h = rand() % height;
      w = rand() % width;
      if(map[w][h].get_event() == NULL){
	 map[w][h].set_event("cave");
	 assigned = true;
      }
      else{
	 assigned = false;
      }
   }while(assigned == false);
}

/**********************************
 * Function: start_rock
 * Description: assigns locations to rock pokemon
 * Parameters: height, widht, map
 * Pre-Conditions: location class must exist
 * Post-Conditions: none
 * ********************************/

void start_rock(int height, int width, Location **map){

   bool assigned = false;
   bool assigned1 = false;
   srand(time(NULL));
   int h = 0;
   int w = 0;
   do{
      h = rand() % height;
      w = rand() % width;
      if(map[w][h].get_event() == NULL){
	 map[w][h].set_event("geodude");
	 assigned = true;
      }
   }while(assigned == false);

   do{
      h = rand() % height;
      w = rand() % width;
      if(map[w][h].get_event() == NULL){
	 map[w][h].set_event("onix");
	 assigned1 = true;
      }
   }while(assigned1 == false);
}

/*********************************
 * Function: start_flying
 * Description: assigns flying pokemon
 * Parameters: height, width, map
 * Pre-Conditions: location class must exist
 * Post-Conditions: none
 * ******************************/

void start_flying(int height, int width, Location **map){

   bool assigned = false;
   bool assigned1 = false;
   srand(time(NULL));
   int h = 0;
   int w = 0;
   do{
      h = rand() % height;
      w = rand() % width;
      if(map[w][h].get_event() == NULL){
	 map[w][h].set_event("charizard");
	 assigned = true;
      }
   }while(assigned == false);

   do{
      h = rand() % height;
      w = rand() % width;
      if(map[w][h].get_event() == NULL){
	 map[w][h].set_event("rayquaza");
	 assigned1 = true;
      }
   }while(assigned1 == false);
}

/*********************************
 * Function: start_psychic
 * Description: assigns psychic values
 * Parameters: height, width, map
 * Pre-Conditions: location class must exist
 * Post-Conditions: none
 * ******************************/

void start_psychic(int height, int width, Location **map){

   bool assigned1 = false;
   bool assigned2 = false;
   srand(time(NULL));
   int h = 0;
   int w = 0;
   do{
      h = rand() % height;
      w = rand() % width;
      if(map[w][h].get_event() == NULL){
	 map[w][h].set_event("mewtwo");
	 assigned1 = true;
      }
   }while(assigned1 == false);

   do{
      h = rand() % height;
      w = rand() % width;
      if(map[w][h].get_event() == NULL){
	 map[w][h].set_event("espeon");
	 assigned2 = true;
      }
   }while(assigned2 == false);
}


/**********************************
 * Function: start_pokestop
 * Description: assigns locations for pokestops
 * Parameters: height, width, map
 * Pre-Conditions: location class must exist
 * Post-Conditions: none
 * ********************************/

void start_pokestop(int height, int width, Location **map){

   bool assigned = false;
   srand(time(NULL));
   int w = 0;
   int h = 0;
   do{
      w = rand() % width;
      h = rand() % height;
      if(map[w][h].get_event() == NULL){
	 map[w][h].set_event("pokestop");
	 assigned = true; 
      }
      else{
	 assigned = false;
      }
   }while(assigned == false);

}

/**********************************
 * Function: start_trainer
 * Description: gives trainer a random starting location
 * Parameters: height, width, map
 * Pre-Conditions: location class must exist
 * Post-Conditions: none
 * ********************************/

Location start_trainer(int height, int width, Location **map, Trainer &t){

   srand(time(NULL));
   int h = rand() % height;
   int w = rand() % width;

   Location professor;

   professor.set_width(w);
   professor.set_height(h);
   t.set_location(h, w);

   return professor;

}

/**********************************
 * Function: move_trainer
 * Description: changes trainer location based on user input
 * Parameters: map, t
 * Pre-Conditions: location class must exist
 * Post-Conditions: none
 * ********************************/

void move_trainer(int height, int width, Location** map, Trainer &t){

   char answer;
   Location new_location;
   bool off_grid;
   do{
      cout << "Press (w) to move up; press (a) to move left; ";
      cout << "press (d) to move right; press(s) to move down." << endl;
      cin >> answer;
   }while(answer != 'w' && answer != 'a' && answer != 's' && answer != 'd');

   if(answer == 'w'){
      new_location.set_height(t.get_location().get_height() + 1);
      new_location.set_width(t.get_location().get_width());
   }
   else if(answer == 'a'){
      new_location.set_height(t.get_location().get_height());
      new_location.set_width(t.get_location().get_width() - 1);
   }
   else if(answer == 'd'){
      new_location.set_height(t.get_location().get_height());
      new_location.set_width(t.get_location().get_width() + 1);
   }
   else if(answer == 's'){
      new_location.set_height(t.get_location().get_height() - 1);
      new_location.set_width(t.get_location().get_width());
   }

   off_grid = check_off_grid(height, width, new_location);
   if(off_grid == true){
      cout << "Cannot move trainer off the grid." << endl;
   }
   else{
      t.set_location(new_location.get_height(), new_location.get_width());
   }
}

/*********************************
 * Function: play_game
 * Description: starts game and calls functions
 * Parameters: height, width, map, t
 * Pre-Conditions: location class must exist
 * Post-Conditions: none
 * ******************************/

void play_game(int height, int width, Location **map, Trainer &t){

   bool end_of_game = false;

   Location professor = start_trainer(height, width, map, t);
   cout << "Welcome to Pokemon Go. I am your professor. My location is ";
   cout << "width: " << professor.get_width() << " & height: " << professor.get_height();
   cout << ". Make sure to remember this location when you have evolved all your pokemon. ";
   cout << "Good luck." << endl;

//#ifdef DEBUG
   for(int i = 0; i < width; i++){
      for(int j = 0; j < height; j++){
	 if(map[i][j].get_event() != NULL){
	    cout << map[i][j].get_event()->get_type() << " height: " << j << " width: " << i << endl;
	 }
      }
   }
//#endif

   check_messages(height, width, map, t);
   check_event(height, width, map, t);

   while(end_of_game == false){
      cout << "trainer height: " << t.get_location().get_height() << endl;
      cout << "trainer width: " << t.get_location().get_width() << endl;
      move_trainer(height, width, map, t);
      check_messages(height, width, map, t);
      check_event(height, width, map, t);
   }
}

/*********************************
 * Function: check_off_grid
 * Description: checks command line arguments to protect user
 * from leaving grid
 * Parameters: height, width, new_location
 * Pre-Conditions: location class must exist
 * Post-Conditions: none
 * ******************************/

bool check_off_grid(int height, int width, Location new_location){

   bool off_grid = false;

   if(new_location.get_width() >= width || new_location.get_width() < 0){
      off_grid = true;
   }
   if(new_location.get_height() >= height || new_location.get_height() < 0){
      off_grid = true;
   }

   return off_grid;
}

/*********************************
 * Function: check_messages
 * Description: checks four surrounding locations for events
 * Parameters: height, width, map, t
 * Pre-Conditions: location class must exist
 * Post-Conditions: none
 * ******************************/

void check_messages(int height, int widht, Location **map, Trainer t){

   if(map[t.get_location().get_width()+1][t.get_location().get_height()].get_event() != NULL){
      map[t.get_location().get_width()+1][t.get_location().get_height()].get_event()->message();
   } 
   if(map[t.get_location().get_width()-1][t.get_location().get_height()].get_event() != NULL){
      map[t.get_location().get_width()-1][t.get_location().get_height()].get_event()->message();
   } 
   if(map[t.get_location().get_width()][t.get_location().get_height()+1].get_event() != NULL){
      map[t.get_location().get_width()][t.get_location().get_height()+1].get_event()->message();
   } 
   if(map[t.get_location().get_width()][t.get_location().get_height()-1].get_event() != NULL){
      map[t.get_location().get_width()][t.get_location().get_height()-1].get_event()->message();
   } 
}

/*********************************
 * Function: check_event
 * Description: checks type of event if trainer lands on same 
 * location
 * Parameters: height, width, map, t
 * Pre-Conditions: location class must exist, 
 * trainer class must exist
 * Post-Conditions: none
 * ******************************/

void check_event(int height, int width, Location **map, Trainer t){

   if(map[t.get_location().get_width()][t.get_location().get_height()].get_event() != NULL){
      if(map[t.get_location().get_width()][t.get_location().get_height()].get_event()->get_type() == "Cave"){
	 cave(height, width, map, t);
      }
      if(map[t.get_location().get_width()][t.get_location().get_height()].get_event()->get_type() == "Pokestop"){
	 pokestop(t.get_location().get_width(), t.get_location().get_height(), map, t);
      }
      if(map[t.get_location().get_width()][t.get_location().get_height()].get_event()->get_type() == "Geodude"){
	 pokemon(height, width, map, t, "Geodude");
      }
   }

}

/*********************************
 * Function: cave
 * Description: gives trainer a megastone 
 * Parameters: height, width, map, t
 * Pre-Conditions: location class must exist, 
 * trainer class must exist
 * Post-Conditions: none
 * ******************************/

void cave(int height, int width, Location **map, Trainer &t){

   bool megastone = t.get_megastone();
   bool m = true;
   cout << "You entered a cave." << endl;
   if(megastone == false){
      cout << "You found a megastone!" << endl;
      t.set_megastone(m);
   }
   else if(megastone == true){
      cout << "The cave is empty." << endl;
   }
}

/*********************************
 * Function: pokestop
 * Description: gives trainer 3-10 pokeballs
 * Parameters: height, width, map, t
 * Pre-Conditions: location class must exist, 
 * trainer class must exist
 * Post-Conditions: none
 * ******************************/

void pokestop(int height, int width, Location **map, Trainer &t){

   cout << "You entered a pokestop." << endl;
   srand(time(NULL));
   int num = (rand() % 8) + 3;
   cout << "You have " << num << " more pokeballs." << endl;
   t.set_num_pokeballs(t.get_num_pokeballs() + num);

}

/*********************************
 * Function: pokemon
 * Description: changes values in trainer pokemon array
 * Parameters: height, width, map, t
 * Pre-Conditions: location class must exist, 
 * trainer class must exist
 * Post-Conditions: none
 * ******************************/

void pokemon(int height, int width, Location **map, Trainer &t, string name){

   int answer = 0;
   cout << "You found a " << name << "!" << endl;
   cout << "Would you like to throw a pokeball? (0) yes or (1) no: ";
   cin >> answer;
   if(answer == 0){
      if(t.get_num_pokeballs() == 0){
	 cout << "You have no pokeballs! Find a pokestop to refill." << endl;
      }
      else{
	 cout << "You have captured a " << name << "!" << endl;
	 //t.get_pokemon()->set_num_capture(t.get_pokemon()->get_num_capture() + 1);
      }
   }

}





















