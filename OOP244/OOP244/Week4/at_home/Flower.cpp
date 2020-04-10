/***********************************************************************
// OOP244 Workshop 4: Constructors, Destructors, Current Object AT HOME
// File Flower.cpp
// Version 1.0
// Date	2019/09/29
// Author	Hong Zhan (Michael) Huang
// Description
// Tests the creation, usage and destruction of the Bouquet class
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Duc Mai         October 7, 2019
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <string.h>
#include <iostream>
#include <cstring>
#include "Flower.h"

using namespace std;

namespace sdds {
   Flower::Flower() { // constructor
      f_name = nullptr;
      f_colour = nullptr;
      f_price = -1;
   }
   
   //2nd constructor:
   Flower::Flower(const char* name, const char* colour, double value) {
      if ((name[0] != 0 && name != nullptr) && (colour[0] != 0 && colour != nullptr) && value > 0) {
         int sizeN = strlen(name) + 1;
         int sizeC = strlen(colour) + 1;
         f_name = new char[sizeN];
         f_colour = new char[sizeC];
         f_price = value;
         strcpy(f_name, name);
         strcpy(f_colour, colour);

      }
      else {
         Flower();
      }
   }
   Flower::~Flower() { // destructor
      if (isEmpty())
         cout << "An unknown flower has departed..." << endl;
      else {
         cout << f_colour << " " << f_name << " has departed..." << endl;
         delete[] f_name;
         f_name = nullptr;
         delete[] f_colour;
         f_colour = nullptr;
      }
   };
//function 2:
   const char* Flower::name() const{
      return Flower::f_name;
   }
   const char* Flower::colour() const {
      return Flower::f_colour;
   }
   double Flower::price() const {
      return Flower::f_price;
   }
   bool Flower::isEmpty()const {
      bool success = false;
      if (f_name == nullptr || f_colour == nullptr || f_price == -1)
         success = true;
      return success;
   }
   void Flower::setEmpty() {
      f_name = nullptr;
      f_colour = nullptr;
      f_price = -1;
   }
   
   void Flower::setName(const char* prompt) {
      delete[] f_name;
      cout << prompt;
      char name[NAME_MAX_LEN];
   sdds::read(name, NAME_MAX_LEN, "A flower's name is limited to 25 characters... Try again: ");
      int size = strlen(name) + 1;
      f_name = new char[size];
      strcpy(f_name, name);
   }
   void Flower::setName(const char* name, int len) {
      f_name = new char[strlen(name) + 1]; 
      strcpy(f_name, name);
   }
   void Flower::setColour(const char* prompt) {
      delete[] f_colour;
      cout << prompt;
      char clr[COL_MAX_LEN + 1];
      sdds::read(clr, COL_MAX_LEN, "A flower's colour is limited to 15 characters... Try again: ");
      int size = strlen(clr) + 1;
      f_colour = new char[size];
      strcpy(f_colour, clr);
      
   }
   void Flower::setColour(const char* colour, int len) {
      f_colour = new char[strlen(colour) + 1]; 
      strcpy(f_colour, colour);
   }
   void Flower::setPrice(const char* prompt) {
      cout << prompt;
      read(f_price, 0, 100000, "A flower's price is a non-negative number... Try again: ");
   }
   void Flower::setPrice(double price) {
      if (price < 0) {
         f_price = 1;
      }
      else {
         f_price = price;
      }
   }
   void Flower::setFlower() {
      cout << "Beginning the birth of a new flower..." << endl;
      setEmpty();
      setName("Enter the flower's name... : ");
      setColour("Enter the flower's colour... : ");
      setPrice("Enter the flower's price... : ");
      cout << "The flower's current details..." << endl;
      display();
   }
   ostream& Flower::display() const {
      if (isEmpty()) {
         cout << "This is an empty flower..." << endl;
      }
      else {
         cout << "Flower: " << f_colour << " " << f_name << " Price: " << f_price << endl;
      }
      return cout;
   }
}