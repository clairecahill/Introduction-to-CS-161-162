#ifndef EVENT_H
#define EVENT_H

#include <iostream>
#include <string>

using namespace std;

class Event{

   protected:
      string type;

   public:
      Event();

      void operator = (const Event &other);

      void set_type(string);
      string get_type();

      virtual void message() = 0;
};

#endif
