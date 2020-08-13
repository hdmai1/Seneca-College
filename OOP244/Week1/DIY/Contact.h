//Contact.h contains Contact struct and prototypes of Contact related functions.
#ifndef SDDS_CONTACT_H
#define SDDS_CONTACT_H
namespace sdds {
   using namespace std;


   #define MAX_REC_NO 100

   struct Contact {
      char name[31];
      long long phoneNumber;
   };


   long long getLongLong(long long min, long long max, const char* valueName);

   long long getPhoneNumber();
   void getContact(Contact* C);
   void printContact(const Contact* C);
   void getName(char* name);
   bool nameInContact(const Contact* C, const char* nameSubStr);
   int search(Contact* found, const Contact* C, const char* name, int noOfRecs);
   void printContacts(const Contact* C, int num);
}
#endif