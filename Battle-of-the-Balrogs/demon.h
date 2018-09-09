#ifndef DEMON_H
#define DEMON_H

#include "creature.h"
#include <ctime>
#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

class Demon: public Creature {

   public:

      Demon();

      int getDamage();

};

#endif
