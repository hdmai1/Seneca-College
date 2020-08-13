// Robot.h
#ifndef SDDS_ROBOT_H
#define SDDS_ROBOT_H
#include "Parts.h"
#include <iostream>
#define NICK_MAX_LEN 10
namespace sdds {
   class Robot {
      char nickname[NICK_MAX_LEN + 1];
      int durability;
      Arms arms;
   public:
      Robot();
      Robot(const char* rb_name, int a_force, int dur);
      // other Members:
      std::ostream& display()const;
      operator bool() const;
      ~Robot();
   };
}
#endif // !SDDS_ROBOT_H
