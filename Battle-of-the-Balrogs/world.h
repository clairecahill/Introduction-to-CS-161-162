#ifndef WORLD_H
#define WORLD_H

#include "human.h"
#include "elf.h"
#include "demon.h"
#include "balrog.h"
#include "cyberdemon.h"
#include "creature.h"
#include "demon.h"
#include <iostream>
#include <string>

using namespace std;

class World{

   private:
      double bank;
      Human *h;
      Elf *e;
      Balrog *b;
      Cyberdemon *c;
      int num_humans;
      int num_elves;
      int num_balrogs;
      int num_cyberdemons;

   public:
      World();

      World(const World &);
      void operator = (const World &);
      ~World();   

      void setBank(double);
      void setHuman(int);
      void setElf(int);
      void setBalrog(int);
      void setCyberdemon(int);
      void setNumhumans(int);
      void setNumelves(int);
      void setNumbalrogs(int);
      void setNumcyberdemons(int);

      double getBank();
      Human* getHuman();
      Elf* getElf();
      Balrog* getBalrog();
      Cyberdemon* getCyberdemon();
      int getNumhumans();
      int getNumelves();
      int getNumbalrogs();
      int getNumcyberdemons();
};

#endif
