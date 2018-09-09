#ifndef POKEMON_H
#define POKEMON_H

#include <string>
#include <iostream>
#include "event.h"

using namespace std;

class Pokemon: public Event {

   protected:
      
      string name;
      string type;
      int num_capture; //the amount of that pokemon captured by trainer
      float chance; //the chance that the pokemon will be caught when the ball is thrown
      int stage; //0 is basic, 1 is stage 1, 2 is stage 2

   public:

      // default constructor
      Pokemon();

      Pokemon(const Pokemon &);
      void operator = (const Pokemon &);
      ~Pokemon();

      //non default constructor
      Pokemon(string, string, int, float, int);

      //modifiers
      void set_name(string);
      void set_type(string);
      void set_num_capture(int);
      void set_chance(float);
      void set_stage(int);

      //getters
      string get_name();
      string get_type();
      int get_num_capture();
      float get_chance();
      int get_stage();

      //additional functions
      virtual void message();

}; 

#endif
