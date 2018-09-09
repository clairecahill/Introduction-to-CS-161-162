#ifndef POKESTOP_H
#define POKESTOP_H

#include "event.h"
#include <ctime>
#include <cstdlib>
#include <iostream>

class Pokestop: public Event{

   public:
      Pokestop();

      void set_name();
      void set_type();

      string get_name();
      string get_type();

      void message();
      int get_num_pokeballs();

};

#endif
