// Parts.cpp
#include "Parts.h"
using namespace std;
namespace sdds {
   Arms::Arms() {
      force = 0;
   }
   Arms::Arms(int arms_force) {
      if (arms_force < 1) {
         force = MIN_FORCE;
      }
      else
         force = arms_force;
   }
   int Arms::getForce()const {
      return force; 
   }

   Arms& Arms::operator++() {
      force += 10;
      return *this;
   }

   Arms Arms::operator++(int) {
      Arms a = *this;
      ++(*this);
      return a;
   }

   Arms& Arms::operator+=(int PE){
      force = force + PE;
      if (force < 1)
         force = 0;
      return *this;
   }
}