#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include "world.h"

using namespace std;

void addCreature(World *, double &);
void setName(World *, int, double &);
int fight(World *, int, int);
void battle(World *, double);
void getCreatures(World *);
void round(World *, int, int, int, int);
void displayAllCreatures(World *);
bool inWorld(World *, int, int);
int chooseType(World *);
int chooseIndex(World *, int);
void changeHitpoints(World *, int, int, int);
bool checkWinner(World *);
void findWinner(World *);
void endBattle(World *, int, int);
void endGame(World *);
void start(World *, double);
void printHitpoints(World *, int, int);

