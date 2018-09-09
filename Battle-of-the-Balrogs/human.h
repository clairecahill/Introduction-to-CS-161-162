#ifndef HUMAN_H
#define HUMAN_H

#include <iostream>
#include <string>
#include "creature.h"

using namespace std;

class Human: public Creature {

   public:

      Human();
      void operator = (const Human &);

      string getSpecies();
      int getDamage();
};

#endif
