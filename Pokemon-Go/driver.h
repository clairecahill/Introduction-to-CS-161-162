#include <iostream>
#include <string>
#include <cstdlib>
#include "location.h"
#include "event.h"
//#include "cave.h"
#include "pokestop.h"
#include "pokemon.h"
#include "flying.h"
#include "rock.h"
#include "psychic.h"
#include "trainer.h"

using namespace std;

void check_command_line(int, char**);
Location** create_map(int, int);
void start_locations(int, int, Location**);
void assign_locations(int, int, Location**, string);
void start_cave(int, int, Location**);
void start_flying(int, int, Location**);
void start_psychic(int, int, Location**);
void start_rock(int, int, Location**);
void start_pokestop(int, int, Location**);
void set_map(int, int, Location**);
Location start_trainer(int, int, Location**, Trainer&);
void move_trainer(int, int, Location**, Trainer&);
void play_game(int, int, Location**, Trainer&);
bool check_off_grid(int, int, Location);
void check_messages(int, int, Location**, Trainer);
void cave(int, int, Location**, Trainer &);
void pokestop(int, int, Location**, Trainer &);
void pokemon(int, int, Location**, Trainer &, string);
void check_event(int, int, Location**, Trainer);
