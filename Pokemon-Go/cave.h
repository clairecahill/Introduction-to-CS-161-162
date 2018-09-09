#ifndef CAVE_V
#define CAVE_H

#include "event.h"

class Cave: public Event{

   public:
      Cave();
      
      void message();
};

#endif
