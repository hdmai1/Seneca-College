// Figurine.cpp
#define _CRT_SECURE_NO_WARNINGS
#include "Figurine.h"
#include <iostream>
#include <string>
#include <string.h>
using namespace std;
namespace sdds {
   Figurine::Figurine(){
      name[0] = '\0';
      pose = nullptr;
      price = 0;
      copy = false;
   };
   Figurine::Figurine(const char* newName, const char* newPose,
      double value){
      copy = false;
      if (newName == nullptr || newName[0] == '\0' || newPose == nullptr || newPose[0] == '\0') {
         name[0] = '\0';
         pose = nullptr;
         price = 0;
      }
      else {
         strncpy(name, newName, MAX_NAME_LEN);
         pose = new char[strlen(newPose) + 1];
         strcpy(pose, newPose);
         if (value < 1) {
            price = DEFAULT_PRICE;
         }
         else
            price = value;
      }
   }
   Figurine::Figurine(const Figurine& RO) {
      copy = true;
      strncpy(name, RO.name, MAX_NAME_LEN);
      price = RO.price;
      if (RO.pose == nullptr) {
         pose = nullptr;
      }
      else {
         pose = new char[strlen(RO.pose) + 1];
         strcpy(pose, RO.pose);
      }
   }
   Figurine::~Figurine() {
      delete[] pose;
   }
   void Figurine::setName(const char* newName) {
      strncpy(name, newName, MAX_NAME_LEN);
   };
   void Figurine::setPose(const char* newPose) {
      delete[] pose;
      pose = new char[strlen(newPose) + 1];
      strcpy(pose, newPose);
   };
   void Figurine::setPrice(double newPrice) {
      if (newPrice < 1) {
         price = DEFAULT_PRICE;
      }
      else {
         price = newPrice;
      }
   };
   std::ostream& Figurine::display() const {
      if (name[0] == '\0' ||
         pose == nullptr ||
         price == 0) {
         cout << "This Figurine has not yet been sculpted" << endl;
         if (copy) {
            cout << "This is a replica of emptiness" << endl;
         }
      }
      else {
         cout << "Figurine Details" << endl;
         cout << "Name: " << name << endl;
         cout << "Pose: " << pose << endl;
         cout << "Price: ";
         cout.setf(ios::fixed);
         cout.precision(2);
         cout << price << endl;
         if (copy) {
            cout << "This is a replica" << endl;
         }
      }
      return cout;
   };
   Figurine::operator bool() const {
      bool ok;
      if (name[0] == '\0') {
         ok = true;
      }
      else {
         ok = false;
      }
      return ok;
   };
   Figurine& Figurine::operator=(const Figurine& RO) {
      copy = true;
      if (this != &RO && RO.pose != nullptr) {
         delete[] pose;
         pose = new char[strlen(RO.pose) + 1];
         strcpy(pose, RO.pose);
         strncpy(name, RO.name, MAX_NAME_LEN);
         price = RO.price;
      }
      return *this;
   };
   bool Figurine::isCopy() const {
      return copy;
   };
   const char* Figurine::getName()const {
      return name;
   };
   const char* Figurine::getPose()const {
      return pose;
   };
   double Figurine::getPrice()const {
      return price;
   };
   bool operator==(const Figurine& LO, const Figurine& RO) {
      bool ok = false;
      if (LO.getName() == RO.getName() && LO.getPose() == RO.getPose() && LO.getPrice() == RO.getPrice() && LO.isCopy() == false && RO.isCopy() == false) {
         ok = true;
      }
      return ok;
   };

}