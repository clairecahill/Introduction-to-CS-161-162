#ifndef LOCATION_H
#define LOCATION_H

#include "event.h"
#include "cave.h"
#include "pokestop.h"
#include "pokemon.h"
#include "rock.h"
#include "flying.h"
#include "psychic.h"
#include <ctime>
#include <cstdlib>

using namespace std;

class Location{

   protected:
      int height;
      int width;
      Event *e;

   public:
      Location();

      Location(const Location &);
      void operator = (const Location &);
      ~Location();
      
      void set_height(int);
      void set_width(int);
      void set_event(string);

      int get_height();
      int get_width();
      Event* get_event();

};
#endif
