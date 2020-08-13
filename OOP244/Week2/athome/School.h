/***********************************************************************
// OOP244 Workshop 2: DMA and overloading
// File School.h
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
#ifndef SDDS_SCHOOL_H
#define SDDS_SCHOOL_H
#include "Subject.h"
namespace sdds {
   struct School {
      int m_noOfSubjects;  // int variable that holds the number of subjects
      Subject* m_subjects;  // pointer to Subject struct.
      char* m_name; // pointer that holds the name of the school
   };
   void read(School& School_name_and_subjects_details); //input school's name and Number Of. Subjects + subjects' details
   int report(const School& School_name_and_subjects_details_and_print_the_total_enrollment); //print School name, and details about Subject + total enrollment
   void freeMem(School& Sch); //deallocation => free memory
}
#endif


