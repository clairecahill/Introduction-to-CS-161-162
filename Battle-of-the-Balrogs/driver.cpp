/*********************
 * Program: driver.cpp
 * Author: claire cahill
 * Date: 5/17/2017
 * Description: runs all functions for game
 * Input: answers for creatures
 * Output: battle
***************************/

#include "driver.h" 

/*************************
 * Function: main
 * Description: starts program and battle
 * Parameters: none
 * Pre-Conditions: world class must exist
 * Post-Conditions: none
 * *********************/

int main(){

   World *w;
   w = new World;
   double money = 0;

   cout << "Welcome to the game! To start, enter how much ";
   cout << "money you would like to start with in your world bank: " << endl;
   cin >> money;
   w->setBank(money);

   start(w, money);

   return 0;
}

/*************************
 * Function: start
 * Description: adds two creatures
 * Parameters: w, money
 * Pre-Conditions: none
 * Post-Conditions: none
 * *********************/

void start(World *w, double money){

   addCreature(w, money);
   addCreature(w, money);

}

/*************************
 * Function: addCreature
 * Description: adds creatures and changes bank
 * Parameters: w, money
 * Pre-Conditions: world must exist
 * Post-Conditions: none
 * *********************/

void addCreature(World *w, double &money){

   int answer = 0;

   cout << "Would you like to add (0) a human for $20, (1) an elf for $30, ";
   cout << "(2) a balrog for $35, or (3) a cyberdemon for $35: " << endl;
   cin >> answer;

   if(answer == 0){
      w->setHuman(1);
      w->setNumhumans(w->getNumhumans() + 1);
      w->setBank(w->getBank() - 20);
   }
   else if(answer == 1){
      w->setElf(1);
      w->setNumelves(w->getNumelves() + 1);
      w->setBank(w->getBank() - 30);
   }
   else if(answer == 2){
      w->setBalrog(1);
      w->setNumbalrogs(w->getNumbalrogs() + 1);
      w->setBank(w->getBank() - 35);
   }
   else if(answer == 3){
      w->setCyberdemon(1);
      w->setNumcyberdemons(w->getNumcyberdemons() + 1);
      w->setBank(w->getBank() - 35);
   }
   cout << "Money in bank: " << w->getBank() << endl;
   setName(w, answer, money);
}

/*************************
 * Function: setName
 * Description: assigns names of creatures
 * Parameters: w, answer, money
 * Pre-Conditions: world must exist
 * Post-Conditions: none
 * *********************/

void setName(World *w, int answer, double &money){

   string name;
   cout << "Enter creature's name: " << endl;
   cin.ignore();
   getline(cin, name);

   if(answer == 0){
      w->getHuman()[w->getNumhumans()-1].setName(name);
   }
   else if(answer == 1){
      w->getElf()[w->getNumelves()-1].setName(name);
   }
   else if(answer == 2){
      w->getBalrog()[w->getNumbalrogs()-1].setName(name);
   }
   else if(answer == 3){
      w->getCyberdemon()[w->getNumcyberdemons()-1].setName(name);
   }

   battle(w, money);
}

/*************************
 * Function: battle
 * Description: loops through functions until
 * winner is found
 * Parameters: w, money
 * Pre-Conditions: world must exist
 * Post-Conditions: none
 * *********************/

void battle(World *w, double money){

   int answer = 0;
   bool keepPlaying = true;
   bool winner = false;

   do{
      cout << "Would you like to add another creature (0) or battle(1): " << endl;
      cin >> answer;

      if(answer == 0){
	 addCreature(w, money);
	 keepPlaying = false;
      }
      else if(answer == 1){
	 keepPlaying = true;
	 displayAllCreatures(w);
	 getCreatures(w);
      }

      winner = checkWinner(w);
      if(winner == true){
	 keepPlaying = false;
      }

   }while(keepPlaying == true);
   findWinner(w);

}

/*************************
 * Function: checkWinner
 * Description: counts number of creatures in world
 * Parameters: w
 * Pre-Conditions: world must exist
 * Post-Conditions: none
 * *********************/

bool checkWinner(World *w){

   int a = 0;
   bool winner = false;

   for(int i = 0; i < w->getNumhumans(); i++){
      if(w->getHuman()[i].getHitpoints() > 0){
	 a++;
      }
   }
   for(int i = 0; i < w->getNumelves(); i++){
      if(w->getElf()[i].getHitpoints() > 0){
	 a++;
      }
   }
   for(int i = 0; i < w->getNumbalrogs(); i++){
      if(w->getBalrog()[i].getHitpoints() > 0){
	 a++;
      }
   }
   for(int i = 0; i < w->getNumcyberdemons(); i++){
      if(w->getCyberdemon()[i].getHitpoints() > 0){
	 a++;
      }
   }

   if(a == 1){
      winner = true;
   }
   else{
      winner = false;
   }

   return winner;
}

/*************************
 * Function: findWinner
 * Description: loops through creatures to 
 * find winner
 * Parameters: w
 * Pre-Conditions: world must exist
 * Post-Conditions: none
 * *********************/

void findWinner(World *w){

   int type = 0;
   int index = 0;

   for(int i = 0; i < w->getNumhumans(); i++){
      if(w->getHuman()[i].getHitpoints() > 0){
	 type = 0;
	 index = i;
      }
   }

   for(int i = 0; i < w->getNumelves(); i++){
      if(w->getElf()[i].getHitpoints() > 0){
	 type = 1;
	 index = i;
      }
   }

   for(int i = 0; i < w->getNumbalrogs(); i++){
      if(w->getBalrog()[i].getHitpoints() > 0){
	 type = 2;
	 index = i;
      }
   }

   for(int i = 0; i < w->getNumcyberdemons(); i++){
      if(w->getCyberdemon()[i].getHitpoints() > 0){
	 type = 3;
	 index = i;
      }
   }

   endBattle(w, type, index);

}

/*************************
 * Function: endBattle
 * Description: sets bank based on winner
 * Parameters: w, type, index
 * Pre-Conditions: world must exist
 * Post-Conditions: none
 * *********************/

void endBattle(World *w, int type, int index){

   if(type == 0){
      cout << w->getHuman()[index].getName() << " is the winner!" << endl;
      w->setBank(w->getBank() + 300);
   }
   else if(type == 1){
      cout << w->getElf()[index].getName() << " is the winner!" << endl;
      w->setBank(w->getBank() +200);
   }
   else if(type == 2){
      cout << w->getBalrog()[index].getName() << " is the winner!" << endl;
      w->setBank(w->getBank() + 150);
   }
   else if(type == 3){
      cout << w->getCyberdemon()[index].getName() << " is the winner!" << endl;
      w->setBank(w->getBank() + 150);
   }

   endGame(w);
}

/*************************
 * Function: endGame
 * Description: tells user if game owes them or not
 * Parameters: w
 * Pre-Conditions: world must exist
 * Post-Conditions: none
 * *********************/

void endGame(World *w){

   cout << "Money in the bank: " << w->getBank() << endl;

   if(w->getBank() < 0){
      cout << "You owe the game!" << endl;
   }
   else if(w->getBank() > 0){
      cout << "The game owes you!" << endl;
   }
   else{
      cout << "Break even!" << endl;
   }

   exit(0);
}

/*************************
 * Function: displayAllCreaturess
 * Description: prints all creatues in world
 * Parameters: w
 * Pre-Conditions: world must exist
 * Post-Conditions: none
 * *********************/

void displayAllCreatures(World *w){

   cout << "All creatures still in the world: " << endl;

   for(int i = 0; i < w->getNumhumans(); i++){
      if(w->getHuman()[i].getHitpoints() > 0){
	 cout << w->getHuman()[i].getName() << endl;
      }
   }

   for(int i = 0; i < w->getNumelves(); i++){
      if(w->getElf()[i].getHitpoints() > 0){
	 cout << w->getElf()[i].getName() << endl;
      }
   }

   for(int i = 0; i < w->getNumbalrogs(); i++){
      if(w->getBalrog()[i].getHitpoints() > 0){
	 cout << w->getBalrog()[i].getName() << endl;
      }
   }

   for(int i = 0; i < w->getNumcyberdemons(); i++){
      if(w->getCyberdemon()[i].getHitpoints() > 0){
	 cout << w->getCyberdemon()[i].getName() << endl;
      }
   }
}

/*************************
 * Function: inWorld
 * Description: checks if hitpoints > 0
 * Parameters: w, type, index
 * Pre-Conditions: world must exist
 * Post-Conditions: none
 * *********************/

bool inWorld(World *w, int type, int index){

   bool inWorld = false;

   if(type == 0){
      if(w->getHuman()[index].getHitpoints() > 0){
	 inWorld = true;
      }
   }
   else if(type == 1){
      if(w->getElf()[index].getHitpoints() > 0){
	 inWorld = true;
      }
   }
   else if(type == 2){
      if(w->getBalrog()[index].getHitpoints() > 0){
	 inWorld = true;
      }
   }
   else if(type == 3){
      if(w->getCyberdemon()[index].getHitpoints() > 0){
	 inWorld = true;
      }
   }

   return inWorld;

}

/*************************
 * Function: chooseType
 * Description: gets type on user input
 * Parameters: w
 * Pre-Conditions: world must exist
 * Post-Conditions: none
 * *********************/

int chooseType(World *w){

   int answer = 0;
   cout << "Would you like to choose human (0), elf (1), balrog (2), or cyberdemon(3): " << endl;
   cin >> answer;

   return answer;

}

/*************************
 * Function: chooseIndex
 * Description: chooses specific creature
 * Parameters: w, type
 * Pre-Conditions: world must exist
 * Post-Conditions: none
 * *********************/

int chooseIndex(World *w, int type){

   int answer;
   bool world;
   do{
      switch(type){

	 case 0: for(int i = 0; i < w->getNumhumans(); i++){
		    if(w->getHuman()[i].getHitpoints() > 0);
		    cout << "(" << i << ")" << w->getHuman()[i].getName() << endl;
		 }
		 break;
	 case 1: for(int i = 0; i < w->getNumelves(); i++){
		    if(w->getElf()[i].getHitpoints() > 0);
		    cout << "(" << i << ")" << w->getElf()[i].getName() << endl;
		 }
		 break;
	 case 2: for(int i = 0; i < w->getNumbalrogs(); i++){
		    if(w->getBalrog()[i].getHitpoints() > 0);
		    cout << "(" << i << ")" << w->getBalrog()[i].getName() << endl;
		 }
		 break;
	 case 3: for(int i = 0; i < w->getNumcyberdemons(); i++){
		    if(w->getCyberdemon()[i].getHitpoints() > 0);
		    cout << "(" << i << ")" << w->getCyberdemon()[i].getName() << endl;
		 }
		 break;
      }

      cin >> answer;

      world = inWorld(w, type, answer);
      if(world == false){
	 cout << "Not in world" << endl;
      }
   }while(world == false);

   return answer;
}

/*************************
 * Function: getCreatures
 * Description: calls on other functions
 * Parameters: w
 * Pre-Conditions: world must exist
 * Post-Conditions: none
 * *********************/

void getCreatures(World *w){

   int type1 = 0;
   int type2 = 0;
   int index1 = 0;
   int index2 = 0;

   cout << "Creature 1" << endl;
   type1 = chooseType(w);
   index1 = chooseIndex(w, type1);
   cout << "Creature 2" << endl;
   type2 = chooseType(w);
   index2 = chooseIndex(w, type2);

   round(w, type1, index1, type2, index2);

}

/*************************
 * Function: round
 * Description: calls specific functions to 
 * execute battle
 * Parameters: w, type 1, index1, type2, index2
 * Pre-Conditions: world must exist
 * Post-Conditions: none
 * *********************/

void round(World *w, int type1, int index1, int type2, int index2){

   int damage1 = fight(w, type1, index1);
   int damage2 = fight(w, type2, index2);

   changeHitpoints(w, type1, index1, damage2);
   changeHitpoints(w, type2, index2, damage1);

   printHitpoints(w, type1, index1);
   printHitpoints(w, type2, index2);

}

/*************************
 * Function: printHitpoints
 * Description: prints hitpoints after round
 * Parameters: w, type, index
 * Pre-Conditions: world must exist
 * Post-Conditions: none
 * *********************/

void printHitpoints(World *w, int type, int index){

   switch(type){
      case 0: cout << w->getHuman()[index].getName();
	      cout << " has " << w->getHuman()[index].getHitpoints() << " hitpoints!" << endl;
	      break;
      case 1: cout << w->getElf()[index].getName();
	      cout << " has " << w->getElf()[index].getHitpoints() << " hitpoints!" << endl;
	      break;
      case 2: cout << w->getBalrog()[index].getName();
	      cout << " has " << w->getBalrog()[index].getHitpoints() << " hitpoints!" << endl;
	      break;
      case 3: cout << w->getCyberdemon()[index].getName();
	      cout << " has " << w->getCyberdemon()[index].getHitpoints() << " hitpoints!" << endl;
	      break;
   }
}

/*************************
 * Function: fight
 * Description: calls on getDamage functions
 * Parameters: w, type, index
 * Pre-Conditions: world must exist
 * Post-Conditions: none
 * *********************/

int fight(World *w, int type, int index){

   int damage = 0;

   switch(type){
      case 0: damage = w->getHuman()[index].getDamage();
	      break;
      case 1: damage = w->getElf()[index].getDamage();
	      break;
      case 2: damage = w->getBalrog()[index].getDamage();
	      break;
      case 3: damage = w->getCyberdemon()[index].getDamage();
	      break;
   }

   return damage;
}

/*************************
 * Function: changeHitpoints
 * Description: changes hitpoints in world class
 * Parameters: w, type, index, damage
 * Pre-Conditions: world must exist
 * Post-Conditions: none
 * *********************/

void changeHitpoints(World *w, int type, int index, int damage){

   if(type == 0){
      w->getHuman()[index].setHitpoints(w->getHuman()[index].getHitpoints() - damage); 
   }
   else if(type == 1){
      w->getElf()[index].setHitpoints(w->getElf()[index].getHitpoints() - damage); 
   }
   else if(type == 2){
      w->getBalrog()[index].setHitpoints(w->getBalrog()[index].getHitpoints() - damage); 
   }
   else if(type == 3){
      w->getCyberdemon()[index].setHitpoints(w->getCyberdemon()[index].getHitpoints() - damage); 
   }

}



