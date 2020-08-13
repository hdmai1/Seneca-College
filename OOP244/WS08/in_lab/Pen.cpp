// Pen.cpp
#define _CRT_SECURE_NO_WARNINGS
#include "Pen.h"
#include <string.h>
using namespace std;
namespace sdds {
   Pen::Pen() {
      style = nullptr;
      ink = 0;
   };
   Pen::Pen(const char* newStyle, int newInk) {
      if (newStyle == nullptr || newStyle[0] == '\0') {
         style = nullptr;
         ink = 0;
      }
      else {
         style = new char[strlen(newStyle) + 1];
         strcpy(style, newStyle);
         
         if (newInk < 1 || newInk > 50) {
            ink = INK_MAX;
         }
         else ink = newInk;
      }
   };
   Pen::~Pen() {
      delete[] style;
   };
   void Pen::write(const char* Something) {
      if (ink > 0) {
         cout << "Writing out the following: " << Something << " with a Pen!" << endl;
         int NoOfNonSpcs = 0;
         int len = strlen(Something);
         for (int i = 0; i < len; i++) {
            if (Something[i] != ' ') {
               NoOfNonSpcs = NoOfNonSpcs + 1;
            }
         }
         ink = ink - (NoOfNonSpcs * 2);
         if (ink < 0)
            ink = 0;
      }
      else  if (ink == 0) {
         cout << "We can't write without ink!" << endl;
      }
   };
   void Pen::refill(int newInk) {
      cout << "Refilling the pen with ink" << endl;
      ink += newInk;
      if (ink > INK_MAX)
         ink = INK_MAX;
   };
   bool Pen::filled() const {
      return (ink > 0);
   };
   ostream& Pen::display(ostream& os) const {
      if (style == nullptr && ink == 0)
         os << "This is an empty Pen" << endl;
      else {
         os << "Pen Details" << endl;
         os << "Style: " << style << endl;
         os << "Ink Remaining: " << ink << endl;
      }
      return os;
   };
}