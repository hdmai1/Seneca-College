///////////////////////////////////////////////////////////
// 
// Workshop 05 - At-home
//
// Robot.cpp
//
// Name: Huu Duc Mai
// 
// ID: 121367189
//
// Email: hdmai1@myseneca.ca
//
///////////////////////////////////////////////////////////

#include "Robot.h"
#include <cstring>
using namespace std;
namespace sdds {
   Robot::Robot() {
      nickname[0] = '\0';
      durability = -1;
   }
   
   Robot::Robot(const char* rb_name, int a_force, int l_speed, int dur):arms(a_force), legs(l_speed) {
      if (rb_name == nullptr || rb_name[0] == 0) {
         nickname[0] = '\0';
         durability = 0;
      } // safe empty state.
      else {
         strcpy(nickname, rb_name);
         nickname[NICK_MAX_LEN] = '\0';
         if (dur < 1)
            durability = 100;
         else
            durability = dur;
      }
   }

   ostream& Robot::display() const {
      if (nickname[0] == '\0' && durability <= 0)
         cout << "This Robot isn't operational" << endl;
      else {
         cout << "***Robot Summary***" << endl;
         cout << "Nickname: " << nickname << endl;
         cout << "Arm Power: " << arms.getForce() <<endl;
         cout << "Durability: " << durability << endl;
         cout << "Legs: " << legs.getSpeed() << endl;
      }
      return cout;
   }
   Robot::operator bool() const {
      bool ok = false;
      if (nickname[0] == '\0' || durability == 0)
         ok = true;
      return ok;
   }
   Robot::~Robot() {
     
   }


   int Robot::getArms() const {
      return arms.getForce();
   }

   Legs Robot::getLegs() const {
      int a = legs.getSpeed();
      return a;
   }

   Robot& Robot::operator-=(int decrease) {
      durability -= decrease;
      if (durability < 1)
         durability = 0;
      return *this;
   }

   void box(Robot& a, Robot& b) {
      cout << "Attempting to begin a Robot boxing match" << endl;
      if (!a.operator bool() && !b.operator bool()) {
         cout << "Both participants are operational... beginning the bout" << endl;
         // begin combat: 
         /// NOT DONE
         while (!a.operator bool() && !b.operator bool()) {
            if (operator>(a.getLegs(), b.getLegs())) {
               b.operator-=(a.getArms());
               if (!b.operator bool()) {
                  a.operator-=(b.getArms());
               }
            }
            else if (operator<(a.getLegs(), b.getLegs())) {
               a.operator-=(b.getArms());
               if (!a.operator bool()) {
                  b.operator-=(a.getArms());
               }
            }
            
         }
         cout << "The bout has concluded... the winner is: " << endl;
         if (a.operator bool()) {
            b.display();
         }
         else if (b.operator bool()) {
            a.display();
         }

         // ** not done.

      }
      else {
         cout << "At least one of the Robots isn't operational. No bout will be had." << endl;
      }
   }
}