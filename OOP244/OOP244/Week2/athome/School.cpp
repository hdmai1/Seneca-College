/***********************************************************************
// OOP244 Workshop 2: DMA and overloading
// File School.cpp
// Version 1.0
// Date	2019/09/15
// Author	Fardad Soleimanloo
// Description
// tests school data entry and report
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Huu Duc Mai     Sept. 19- 2019
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include "School.h"
#include "utils.h"
#include "Subject.h"
#include <iostream>
#include <cstring>

namespace sdds {
   using namespace std;
   void read(School& Sch) {
      // Enter School's name:
      char Sch_name[61];
      cout << "Please enter the name of the school:\n> ";
      read(Sch_name, 60, "Name is too long, only 60 characters allowed!\nRedo Entry: ");
      int size = strlen(Sch_name) + 1;
      Sch.m_name = new char[size];
      strcpy(Sch.m_name, Sch_name);
      
      // Enter No. of Subjects:
      cout << "Please enter the number of subjects offered by " << Sch.m_name << ": "; 
      read(Sch.m_noOfSubjects, 2, 50, "Invalid Number of subjects, 2<=ENTRY<=50\nRedo Entry: ");
      // Enter Subjects' details:
      Sch.m_subjects = new Subject[Sch.m_noOfSubjects];
      for (int i = 0; i < Sch.m_noOfSubjects; i++) {
         cout << i + 1 << ") ------------------------------" << endl;
         read(Sch.m_subjects[i]); 
      }
   }


   int report(const School& Sch) {
      int tt_stu, total = 0;
      cout << Sch.m_name << endl;
      cout << "Subject Enrollments" << endl;
      //loop through the Subjects
      for (int i = 0; i < Sch.m_noOfSubjects; i++) {
         tt_stu = 0;
         for (int a = 0; a < *Sch.m_subjects[i].m_noOfSections; a++) { //loop through the number of sections in a Subject struct.
            cout << Sch.m_subjects[i].m_noOfStdsInSecs[a]; // print the number of students in sections.
            tt_stu += Sch.m_subjects[i].m_noOfStdsInSecs[a];  // local variable that counts the number of students in sections.          
            if (a != (*Sch.m_subjects[i].m_noOfSections - 1)) {
               cout << ",";                                
            }
         }
         cout << endl << Sch.m_subjects[i].m_subjectName << ": " << tt_stu << endl; //print the subjects' name.
         total += tt_stu;                                            //local variable that holds the number of students in ALL sections.
      } 
      cout << "Total enrollment: " << total << endl;
      return total;
   } 
   // free memory
   void freeMem(School& Sch) {
      delete[] Sch.m_name;     
      Sch.m_name = nullptr;

      for (int i = 0; i < Sch.m_noOfSubjects; i++) {
         freeMem(Sch.m_subjects[i]);
      }

      delete[] Sch.m_subjects;
      Sch.m_subjects = nullptr;
   }
}