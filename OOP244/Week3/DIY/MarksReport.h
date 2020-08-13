#ifndef SDDS_MARKSREPORT_H
#define SDDS_MARKSREPORT_H
#include "Mark.h"
namespace sdds {
   class MarksReport {
      char* m_name;
      int m_NoOfMarks;
      Mark *MarkSubjects;

      public:
         MarksReport();
         ~MarksReport();
         void initialize();
         void getMarks();
         void print();
         void terminate();
   };
}

#endif // 
 