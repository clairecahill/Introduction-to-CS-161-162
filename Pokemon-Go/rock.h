#ifndef ROCK_H
#define ROCK_H

#include <iostream>
#include <string>
#include "pokemon.h"

using namespace std;

class Rock: public Pokemon {

   public:

      Rock();

      //non default constructor
      Rock(string, string, int, float, int);
      
      void operator = (const Rock &);
      void message();
};

#endif
