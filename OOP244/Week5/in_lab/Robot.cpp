// Robot.cpp
#include "Robot.h"
#include <cstring>
using namespace std;
namespace sdds {
   Robot::Robot() {
      nickname[0] = '\0';
      durability = -1;
   }
   
   Robot::Robot(const char* rb_name, int a_force, int dur):arms(a_force) {
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
      if (nickname[0] == '\0' && durability <= 0 )
         cout << "This Robot isn't operational" << endl;
      else {
         cout << "***Robot Summary***" << endl;
         cout << "Nickname: " << nickname << endl;
         cout << "Arm Power: " << arms.getForce() <<endl;
         cout << "Durability: " << durability << endl;
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
}