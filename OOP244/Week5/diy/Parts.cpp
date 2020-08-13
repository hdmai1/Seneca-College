///////////////////////////////////////////////////////////
// 
// Workshop 05 - DIY
//
// Parts.cpp
//
// Name: Huu Duc Mai
// 
// ID: 121367189
//
// Email: hdmai1@myseneca.ca
//
///////////////////////////////////////////////////////////
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
// --------------------------------------
// Operator Overload Members (Legs):
   Legs::Legs() {
      speed = 0;
   }
   
   Legs::Legs(int new_speed) {
      if (new_speed < 1)
         speed = MIN_SPEED;
      else
         speed = new_speed;
   }

   int Legs::getSpeed() const {
      return speed;
   }
   
   Legs& Legs::operator-=(int dec) {
      speed = speed - dec;
      if (speed < 1)
         speed = 0;
      return *this;
   }

   // set new force
   void Arms::setforce(int new_force) {
      force = new_force;
   }
   

   //set new speed
   void Legs::setspeed(int new_speed) {
      speed = new_speed;
   }

// --------------------------------------
// Global Helper Operators (Arms, Legs)
   bool operator>(const Legs& a, const Legs& b) {
      bool ok = false;
      if (a.getSpeed() > b.getSpeed())
         ok = true;
      return ok;
   }

   bool operator<(const Legs& a, const Legs& b) {
      return (!operator>(a, b));
   }

   bool operator>(const Arms& a, const Arms& b) {
      bool ok = false;
      if (a.getForce() > b.getForce())
         ok = true;
      return ok;
   }

   bool operator<(const Arms& a, const Arms& b) {
      return (!operator>(a, b));
   }
}