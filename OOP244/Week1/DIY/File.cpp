//File.cpp contains functions related to FILE management.
#include <cstdio>
#include "Contact.h"
namespace sdds {
   bool readContact(Contact* C, FILE* fptr) {
      return fscanf(fptr, "%[^,],%lld", C->name, &C->phoneNumber) == 2;
   }

   void writeContact(FILE* fptr, const Contact* C) {
      fprintf(fptr, "%s,%lld", C->name, C->phoneNumber);
   }

   int readContacts(Contact* contacts, const char* filename) {
      FILE* fptr = fopen(filename, "r");
      Contact C;
      int num;
      for (num = 0; fptr && num < MAX_REC_NO && readContact(&C, fptr); num++) {
         contacts[num] = C;
      }
      return num;
   }

   void writeContacts(Contact* contacts, int cntno, const char* filename) {
      FILE* fptr = fopen(filename, "w");
      int num;
      for (num = 0; num < cntno; num++) {
         writeContact(fptr, &contacts[num]);
      }
      fclose(fptr);
   }
}