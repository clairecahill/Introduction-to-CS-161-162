#ifndef FLYING_H
#define FLYING_H

#include <iostream>
#include <string>
#include "pokemon.h"

using namespace std;

class Flying: public Pokemon {

   public:

      //non default constructor
      Flying(string, string, int, float, int);

      void operator = (const Flying &);
      void message();

};
#endif
