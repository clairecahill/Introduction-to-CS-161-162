#ifndef ELF_H
#define ELF_H

#include "creature.h"
#include <ctime>
#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

class Elf: public Creature {

   public:

      Elf();
      void operator = (const Elf &);

      string getSpecies();
      int getDamage();

};

#endif
