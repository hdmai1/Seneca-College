//Tools.cpp includes helper functions which can be used as ultilities only.
#include "Contact.h"
#include <cstring>
#include <iostream>

namespace sdds {
   bool valid(long long min, long long max, long long val) {
      return min <= val && val <= max;
   }

   void getStr(char* str, int len) {
      cin.getline(str, len, '\n');
   }


   int compare(const Contact* A, const Contact* B) {
      return strcmp(A->name, B->name);
   }

   void sort(Contact c[], int n) {
      Contact temp;
      for (int i = n - 1; i > 0; i--) {
         for (int j = 0; j < i; j++) {
            if (compare(&c[j], &c[j + 1]) > 0) {
               temp = c[j];
               c[j] = c[j + 1];
               c[j + 1] = temp;
            }
         }
      }
   }


   void toLowerCase(char* lowerCase, const char* str) {
      int i;
      for (i = 0; str[i] && i < 30; i++) {
         lowerCase[i] = str[i] | 0x20;
      }
      lowerCase[i] = 0;
   }

   bool yes() {
      char ch;
      ch = cin.get();
      cin.ignore(1000, '\n');
      return ch == 'y' || ch == 'Y';
   }
}