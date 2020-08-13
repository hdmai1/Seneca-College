//File.h includes prototypes for those functions related to FILE MANAGEMENT.
#ifndef SDDS_FILE_H
#define SDDS_FILE_H
namespace sdds {
   using namespace std;
   bool readContact(Contact* C, FILE* fptr);
   void writeContact(FILE* fptr, const Contact* C);

   int readContacts(Contact* contacts, const char* filename);

   void writeContacts(Contact* contacts, int cntno, const char* filename);
}
#endif // !SDDS_FILE_H
