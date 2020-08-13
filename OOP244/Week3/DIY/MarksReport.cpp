#include "MarksReport.h"
#include "Mark.h"
#include "ReportUtils.h"
#include <iostream>
#include <cstring>

namespace sdds {
   using namespace std;
   
   MarksReport::MarksReport() {
     
   }
   MarksReport::~MarksReport() {

   }
   void MarksReport::initialize() {
      m_name = nullptr;
      m_NoOfMarks = 0;
      MarkSubjects = 0;
   }

   void MarksReport::getMarks() {
      char name[71];
      cout << "Enter the report Name: ";
      cin.get(name, 71);
      cin.ignore(1000, '\n');
      int size = strlen(name) + 1;
      m_name = new char[size];
      strcpy(m_name, name);

      
      cout << "Enter the number of marks: ";
      cin >> m_NoOfMarks;
      MarkSubjects = new Mark[m_NoOfMarks];

      cout << "Please enter " << m_NoOfMarks << " marks:" << endl;

      for (int i = 0; i < m_NoOfMarks; i++) {
         cout << i + 1 << ": ";
         MarkSubjects[i].setEmpty();
         MarkSubjects[i].set(DSP_LETTER);
         MarkSubjects[i].readName("Subject Name: ", 6);
         MarkSubjects[i].read("Mark (mark/outof): ");
         }
      
      cout << "Entry Completed!" << endl << endl;
   }

   void MarksReport::print() {
      double gpa = 0;
      int highest = MarkSubjects[0].percent() ;
      int lowest = MarkSubjects[0].percent();
      printchar(70, '-');
      cout << endl << m_name << endl;
      printchar(70, '-');
      cout << endl;
      cout << "Marks entered:" << endl;
      for (int i = 0; i < m_NoOfMarks; i++) {
         if (highest < MarkSubjects[i].percent()) {
            highest = MarkSubjects[i].percent();
         }
         if (lowest > MarkSubjects[i].percent()) {
            lowest = MarkSubjects[i].percent();
         }
         MarkSubjects[i].display(66);
         gpa += MarkSubjects[i].letterBasedGPA();
         cout << endl;
      }
      printchar(70, '-');
      cout << endl;
      printchar(30, ' ');

      align(36);
      cout << "Lowest Mark";
      cout << "%" << lowest << endl;

      printchar(30, ' ');
      align(36);
      cout << "Highest mark";
      cout << "%" << highest << endl;
      
      printchar(30, ' ');
      align(36);
      cout << "GPA";
      cout.precision(2);
      cout << gpa/m_NoOfMarks << endl;
      
   }

   void MarksReport::terminate() {
      delete[] m_name;
      m_name = nullptr;
      delete[] MarkSubjects;
      MarkSubjects = nullptr;
   }
   
   
}