/***********************************************************************
// OOP244 Workshop 3: Member functions and privacy
// File Mark.h
// Version 1.0
// Date	2019/09/19
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
   class Mark {
      int m_displayMode;
      double m_mark;
      int m_outOf;
   private:
      void flushKeyboard()const;
   public:
      void set(int displayMode);
      void set(double mark, int outOf=1);
      void setEmpty();
      bool isEmpty()const;
      int percent()const;
      double rawValue()const;
      bool read(const char* prompt);
      std::ostream& display()const ;
   };
}
#endif // !SDDS_MARK_H
