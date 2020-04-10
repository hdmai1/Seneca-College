/***********************************************************************
// OOP244 Workshop 3: Member functions and privacy
// File Mark.cpp
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
#include <iostream>
#include "Mark.h"

namespace sdds {
   using namespace std;
   void Mark::flushKeyboard()const {
         char ch;
         do {
            ch = cin.get();
         } while (ch != '\n');
      }
   void Mark::set(int displayMode) {
         m_displayMode = displayMode;
   }

   void Mark::set(double mark, int outOf) {
        m_mark = mark;
        m_outOf = outOf;
   }
      
   void Mark::setEmpty() {
        m_displayMode = DSP_UNDEFINED;
        m_mark = -1;
        m_outOf = 100;
   }

   bool Mark::isEmpty()const {
      return m_mark == -1;
   }

   int Mark::percent()const {
      double perc = (m_mark / m_outOf) * 100 + 0.5;
      return perc;
   }

   double Mark::rawValue()const {
      double rv = (m_mark / m_outOf);
      return rv;
   }

   bool Mark::read(const char* prompt) {
        bool success = true;
        cout << prompt;
        cin >> m_mark;
        cin.ignore();
        cin >> m_outOf;
        if (cin.fail()) {
           cin.clear();
           setEmpty();
           success = false;
        }
        flushKeyboard();
        return success;
   }

   ostream& Mark::display() const {
        if (Mark::isEmpty())
           cout << "Empty Mark object!";
        else {
           if (m_displayMode == DSP_RAW)
              cout << rawValue();
           else if (m_displayMode == DSP_PERCENT)
              cout << "%" << percent();
           else if (m_displayMode == DSP_ASIS)
              cout << m_mark << "/" << m_outOf;
           else if (m_displayMode == DSP_UNDEFINED)
              cout << "Display mode not set!";
           else
              cout << "Invalid Mark Display setting!";
        }
        return cout;
      }
}