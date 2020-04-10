// Contact.cpp includes all Contact related functions.
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Contact.h"
#include "Tools.h"

namespace sdds {
   long long getLongLong(long long min, long long max, const char* valueName) {
      long long val;
      bool done = false;
      while (!done) {
         cin >> val;
         if (cin.fail()) {
            cin.clear();
            cout << "Bad Number, try again: ";
         }
         else {
            if (!valid(min, max, val)) {
               cout << "Invalid " << valueName << "!" << endl
                  << "The " << valueName << " must be between " << min << " and " << max << ": ";
            }
            else {
               done = true;
            }
         }
         cin.ignore(1000, '\n');
      }
      return val;
   }

   long long getPhoneNumber() {
      return getLongLong(1000000000LL, 9999999999LL, "Phone Number");
   }

   void getContact(Contact* C) {
      cout << "Name: ";
      getName(C->name);
      cout << "Phone Number: ";
      C->phoneNumber = getPhoneNumber();
   }

   void printContact(const Contact* C) {
      cout << setw(35) << setfill('.') << setiosflags(ios::left) << C->name << C->phoneNumber << endl;
   }



   void getName(char* name) {
      getStr(name, 30);
   }

   bool nameInContact(const Contact* C, const char* nameSubStr) {
      char name[31];
      char subName[31];
      toLowerCase(name, C->name);
      toLowerCase(subName, nameSubStr);
      return strstr(name, subName) != nullptr;
   }

   int search(Contact* found, const Contact* C, const char* name, int noOfRecs) {
      int i;
      int noOfMatches = 0;
      for (i = 0; i < noOfRecs; i++) {
         if (nameInContact(&C[i], name)) {
            found[noOfMatches] = C[i];
            noOfMatches++;
         }
      }
      return noOfMatches;
   }

   void printContacts(const Contact* C, int num) {
      for (int i = 0; i < num; i++) {
         printContact(&C[i]);
      }
   }
}