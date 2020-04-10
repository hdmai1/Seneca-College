// Ore.cpp
#define _CRT_SECURE_NO_WARNINGS
#include "Ore.h"
#include <iostream>
#include <cstring>
using namespace std;
namespace sdds {
   Ore::Ore() {
      weight = 0.0f;
      purity = 0;
      classification[0] = '\0';
   };
   
   Ore::Ore(double new_Weight, int new_Purity, const char* new_classification ) {
      if (new_Weight < 1) {
         weight = DEFAULT_WEIGHT;
      }
      else weight = new_Weight;
      if (new_Purity < 1 || new_Purity > 100) {
         purity = DEFAULT_PURITY;
      }
      else purity = new_Purity;
      strncpy(classification, new_classification, CLASS_LEN);
   };

   bool Ore::refine() {
      bool ok;
      if (purity == 100) {
         cout << "Can no longer be refined" << endl;
         ok = false;
      }
      else {
         ok = true;
         weight -= 20;
         purity += 10;
         if (purity > 100)
            purity = 100;
      }
      return ok;
   };
   
   ostream& Ore::display(ostream& os)const {
      if (weight == 0.0f &&
         purity == 0 &&
         classification[0] == '\0') {
         os << "This ore is imaginary" << endl;
      }
      else {
         os << "Weight: ";
         os.setf(ios::fixed);
         os.precision(2);
         os << weight << endl;
         os << "Purity: " << purity << endl;
         os << "Classification: " << classification << endl;
      }
      return os;
   };
   
   istream& Ore::input(istream& is) {
      double temp_W;
      cout << "Enter a value for this ore's weight: ";
      is >> temp_W;

      int temp_P;
      cout << "Enter a value for this ore's purity: ";
      is >> temp_P;
      
      char temp_C[CLASS_LEN + 1];
      is.ignore(2000, '\n');
      cout << "Enter a classification for the ore (MAX 30 chars): ";
      is.getline(temp_C, CLASS_LEN, '\n');
      
      Ore temp(temp_W, temp_P, temp_C);

      *this = temp;
      return is;
   };
   
   ostream& operator<<(ostream& os, const Ore& ore) {
      os << "Ore" << endl;
      ore.display(os);
      return os;
   };
   
   istream& operator>>(istream& os, Ore& ore) {
      ore.input(os);
      return os;
   };
}