#ifndef SDDS_SUBJECT_H
#define SDDS_SUBJECT_H
namespace sdds {
   struct Subject {
      int* m_noOfSections;
      int* m_noOfStdsInSecs;
      char* m_subjectName;
   };
   void read(char* subjectname);
   void read(int& NoOfSection);
   void read(int NoOfStudent[], int NoOfSection);

   void read(Subject& Sub);
   int report(const Subject& Sub);
   void freeMem(Subject& Sub);
}
#endif // !SDDS_SUBJECT_H
