#include <string.h>
#include <iostream>
#include <cstring>
#include "Flower.h"
#include "utils.h"

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
         f_price = -1;
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
      return (f_price < 0);
   }
   void Flower::setEmpty() {
      Flower();
   }
   
   void Flower::setName(const char* prompt) {
      delete[] f_name;
      cout << prompt;
      char name[NAME_MAX_LEN+1];
   sdds::read(name, NAME_MAX_LEN, "A flower's name is limited to 25 characters... Try again: ");
      int size = strlen(name) + 1;
      f_name = new char[size];
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
   void Flower::setPrice(const char* prompt) {
      cout << prompt;
      cin >> f_price;
      while (f_price < 0) {
         cout << "A flower's price is a non-negative number... Try again: ";
         cin >> f_price;
      }
      
   }
    void Flower::setFlower() {
      cout << "Beginning the birth of a new flower..." << endl;
      setName("Enter the flower's name... : ");
      setColour("Enter the flower's colour... : ");
      setPrice("Enter the flower's price... : ");
      cout << "The flower's current details..." << endl;
      cout << "Flower: " << f_colour << " " << f_name << " Price: " << f_price << endl;
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