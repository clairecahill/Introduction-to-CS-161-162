#ifndef CYBERDEMON_H
#define CYBERDEMON_H

#include "demon.h"
#include <ctime>
#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

class Cyberdemon: public Demon {

   public:

      Cyberdemon();
      void copyCyberdemon(const Cyberdemon &);

      string getSpecies();
      int getDamage();

};

#endif
