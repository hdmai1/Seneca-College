///////////////////////////////////////////////////////////
// 
// Workshop 05 - DIY
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
   //constructor
   Robot::Robot() {
      nickname[0] = '\0';
      durability = 0;
      legs = 0;
      arms = 0;
   }
   //constructor with provided name, force, speed, durability.
   Robot::Robot(const char* rb_name, int a_force, int l_speed, int dur):arms(a_force), legs(l_speed) {
      if (rb_name == nullptr || rb_name[0] == 0) {
         nickname[0] = '\0';
         durability = 0;
      } // safe empty state.
      else {
         strncpy(nickname, rb_name,NICK_MAX_LEN);
         nickname[NICK_MAX_LEN-1] = '\0';
         if (dur < 1)
            durability = 100;
         else
            durability = dur;
      }
   }
   
   ostream& Robot::display() const {
      if (nickname[0] == '\0' || durability <= 0 )
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


   Arms Robot::getArms() const {
      return arms;
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
         while (!a.operator bool() && !b.operator bool()) {
            if (operator>(a.getLegs(), b.getLegs())) {
               b.operator-=(a.getArms().getForce());
               if (!b.operator bool()) {
                  a.operator-=(b.getArms().getForce());
               }
            }
            else if (operator<(a.getLegs(), b.getLegs())) {
               a.operator-=(b.getArms().getForce());
               if (!a.operator bool()) {
                  b.operator-=(a.getArms().getForce());
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
      }
      else {
         cout << "At least one of the Robots isn't operational. No bout will be had." << endl;
      }
   }

   // DIY functions
   const char* Robot::getname() const {
      return nickname;
   }
   int Robot::getDur() const {
      return durability;
   }

   void Robot::setname(const char* new_name) {
      strcpy(nickname, new_name);
   }

   void Robot::setDur(int new_dur) {
      durability = new_dur;
   }
   void Robot::setArms(int new_force) {
      arms.setforce(new_force);
   }
   void Robot::setLegs(int new_speed) {
      legs.setspeed(new_speed);
   }
   void Robot::setRobot(const char* new_name,
      int new_dur,
      int new_force,
      int new_speed) {
      setname(new_name);
      setDur(new_dur);
      setArms(new_force);
      setLegs(new_speed);
   }
}