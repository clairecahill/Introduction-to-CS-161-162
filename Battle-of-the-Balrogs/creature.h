#ifndef CREATURE_H
#define CREATURE_H

#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

class Creature{

   protected:
      int type; //0 human, 1 elf, 2 balrog, 3 cyberdemon
      int strength; //how much damage we can inflict
      int hitpoints; //damage we can sustain
      string name; 
      double payoff; //how much you win for the creature
      double cost; 
      string getSpecies(); //returns type of species

   public:
      Creature();
      Creature (int, int, int, string, double, double);
      void operator = (const Creature &);

      void setType(int);
      void setStrength(int);
      void setHitpoints(int);
      void setName(string);
      void setPayoff(double);
      void setCost(double);

      int getType();
      int getStrength();
      int getHitpoints();
      string getName();
      double getPayoff();
      double getCost();

      int getDamage();
};

#endif
