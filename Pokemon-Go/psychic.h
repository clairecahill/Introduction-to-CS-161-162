#ifndef PSYCHIC_H
#define PSYCHIC_H

#include <iostream>
#include <string>
#include "pokemon.h"

using namespace std;

class Psychic: public Pokemon{

   public:

      //non default constructor
      Psychic(string, string, int, float, int);

      void operator = (const Psychic &);
      void message();
};
#endif
