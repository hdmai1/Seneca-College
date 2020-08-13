///////////////////////////////////////////////////////////
// 
// Workshop 05 - DIY
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
      char nickname[NICK_MAX_LEN+1];
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
      Arms getArms() const;
      Legs getLegs() const;
     
      Robot& operator-=(int);

      const char* getname() const;
      int getDur() const;
      void setname(const char* new_name);
      void setDur(int new_dur);
      void setArms(int new_force);
      void setLegs(int new_speed);
      void setRobot(const char* new_name, int new_dur, int new_force, int new_speed);
   };
   void box(Robot& a, Robot& b);

}
#endif // !SDDS_ROBOT_H
