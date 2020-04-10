#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;
#include "Utils.h"
namespace sdds {
   // reads an integer from console the integer referenced by "val"
   // argument.
   // if the user enters an invalid integer or values outside of the 
   // boundries set by "min" or "max" , this function flushes the 
   //keyboard, prints the "errorMessage and reads again
   // untill user enters an acceptable integer
   int read(int min, int max, const char* ErrorMess) {
      bool ok;
      int val;
      char newline;
      do {
         cin >> val;
         newline = cin.get();
         if (cin.fail() || newline != '\n') {
            ok = false;
            cin.clear();
            cin.ignore(1000, '\n');
         }
         else {
            ok = val <= max && val >= min;
         }
      } while (!ok && cout << ErrorMess);
      return val;
   }

}