#include "Subject.h"
#include "utils.h"
#include <iostream>
#include <cstring>
namespace sdds {
   using namespace std;
   void read(char* subj_name) {
      cout << "Enter subject name: ";
      read(subj_name, 70, "Name is too long, only 70 characters allowed!\nRedo Entry: ");
   }
   void read(int& noOfSec) {
      cout << "Enter number of sections: ";
      read(noOfSec, 1, 10, "Invalid Number of sections, 1<=ENTRY<=10\nRedo Entry: ");
   }
   void read(int noOfStu[], int noOfSec) {
      cout << "Enter the number of students in each one of the " << noOfSec << " sections:" << endl;
      for (int i = 0; i < noOfSec; i++) {
         cout << i + 1 << ": ";
         read(noOfStu[i], 5, 35, "Invalid Number of students, 5<=ENTRY<=35\nRedo Entry: ");
      }
   }

  void read(Subject& Sub) {
      char name[71];
      read(name); 
      int size = strlen(name) + 1;
      Sub.m_subjectName = new char[size];
      strcpy(Sub.m_subjectName, name);


      Sub.m_noOfSections = new int;
      read(*Sub.m_noOfSections);

      Sub.m_noOfStdsInSecs = new int[*Sub.m_noOfSections];
      read(Sub.m_noOfStdsInSecs, *Sub.m_noOfSections);
   }

  int report(const Subject& Sub) {
      int i, totalstds = 0;
      for (i = 0; i < *Sub.m_noOfSections ; i++) {
         totalstds += Sub.m_noOfStdsInSecs[i];
         cout << Sub.m_noOfStdsInSecs[i];
         if (i != (*Sub.m_noOfSections - 1)) {
            cout << ",";
         }
      }
      cout << endl << Sub.m_subjectName << ": " << totalstds << endl;
      return 0;
   }
   
   void freeMem(Subject& Sub) {
      delete[] Sub.m_subjectName;
      Sub.m_subjectName = nullptr;
 
      delete Sub.m_noOfSections;
      Sub.m_noOfSections = nullptr;
      
      delete[] Sub.m_noOfStdsInSecs;
      Sub.m_noOfStdsInSecs = nullptr;

   } 
}