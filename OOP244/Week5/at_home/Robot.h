///////////////////////////////////////////////////////////
// 
// Workshop 05 - At-home
//
// Robot.h
//
// Name: Huu Duc Mai
// 
// ID: 121367189
//
// Email: hdmai1@myseneca.ca
//
///////////////////////////////////////////////////////////
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
      Legs legs;
   public:
      Robot();
      Robot(const char* rb_name, int a_force,int l_speed, int dur);
      // other Members:
      std::ostream& display()const;
      operator bool() const;
      ~Robot();
      int getArms() const;
      Legs getLegs() const;

      Robot& operator-=(int);

   };
   void box(Robot& a, Robot& b);

}
#endif // !SDDS_ROBOT_H
