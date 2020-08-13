/***********************************************************************
// OOP244 Workshop 3: Member functions and privacy
// File Mark.h
// Version 1.0
// Date	2019/09/26
// Author	Fardad Soleimanloo
// Description
// tests Mark data entry
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Huu Duc Mai     Sept.24
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SDDS_MARK_H
#define SDDS_MARK_H
#include <iostream>
namespace sdds {
#define DSP_RAW 1
#define DSP_PERCENT 2
#define DSP_ASIS 3
#define DSP_UNDEFINED -1
#define DSP_GPA 4
#define DSP_LETTER 5
   class Mark {
      int m_displayMode;
      double m_mark;
      int m_outOf;
      char m_name[51];
   private:
      void flushKeyboard()const;
      void prnLetter()const;
   public:
      Mark();
      ~Mark();
      void set(int displayMode);
      void set(double mark, int outOf=1);
      void setEmpty();
      bool isEmpty()const;
      int percent()const;
      double rawValue()const;
      bool read(const char* prompt);
      std::ostream& display(int width = 55)const ;
      void set(const char* name);
      void set(const char* name, double rawMark, int outof = 1);
      bool readName(const char* prompt, int maxLen = 50);
      void changeOutOf(int value);
      double GPA()const;
      double letterBasedGPA()const;
   };
}
#endif // !SDDS_MARK_H
