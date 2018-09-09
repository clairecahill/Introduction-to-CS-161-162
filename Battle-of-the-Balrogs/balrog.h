#ifndef BALROG_H
#define BALROG_H

#include "demon.h"
#include <ctime>
#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

class Balrog: public Demon {

   public:

      Balrog();
      //void operator = (const Balrog &);

      string getSpecies();
      int getDamage();

};

#endif
