#ifndef TRAINER_H
#define TRAINER_H

#include "location.h"
#include "pokemon.h"
#include "rock.h"
#include "flying.h"
#include "psychic.h"
#include <iostream>

using namespace std;

class Trainer{

   private:

      Location l;
      int num_pokeballs;
      bool megastone;
      Pokemon **p;
      
   public:
      
      Trainer();

      Trainer(const Trainer &);
      void operator = (const Trainer &);
      ~Trainer();

      void set_location(int, int);
      void set_num_pokeballs(int);
      void set_megastone(bool);
      void set_pokemon();

      Location get_location();
      int get_num_pokeballs();
      bool get_megastone();
      Pokemon** get_pokemon();
      
      void move(); //changes location based on user input = error proof

};

#endif
