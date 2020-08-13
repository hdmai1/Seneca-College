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
// Huu Duc Mai     Sept.26
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include <string>
#include <cstring>
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
      m_name[0] = '\0';
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

   ostream& Mark::display(int width) const {
      if (Mark::isEmpty())
         cout << "Empty Mark object!";
      if (!Mark::isEmpty()) {
         if (m_name[0] != '\0'){
            cout.width(width);
            cout.setf(ios::left);
            cout.fill('.');
            cout << m_name;
            
         }
         
         if (m_displayMode == DSP_RAW) {
            cout.setf(ios::fixed);
            cout.precision(2);
            cout << rawValue();
         }
         else if (m_displayMode == DSP_PERCENT)
            cout << "%" << percent();
         else if (m_displayMode == DSP_ASIS) {
            cout.setf(ios::fixed);
            cout.precision(1);
            cout << m_mark;
            cout << "/" << m_outOf;
         }
         else if (m_displayMode == DSP_UNDEFINED)
            cout << "Display mode not set!";
         else if (m_displayMode == DSP_LETTER)
            prnLetter();
         else if (m_displayMode == DSP_GPA) {
            cout.setf(ios::fixed);
            cout.precision(1);
            cout << Mark::GPA();
         }
         else
            cout << "Invalid Mark Display setting!";
      }
      return cout;
   }
  
   // Private member function PrintLetter
   void Mark::prnLetter()const {
      if (!Mark::isEmpty()) {
         if (percent() >= 0 && percent() <= 49)
            cout << "F";
         else if (percent() > 49 && percent() <= 54)
            cout << "D";
         else if (percent() > 54 && percent() <= 59)
            cout << "D+";
         else if (percent() > 59 && percent() <= 64)
            cout << "C";
         else if (percent() > 64 && percent() <= 69)
            cout << "C+";
         else if (percent() > 69 && percent() <= 74)
            cout << "B";
         else if (percent() > 74 && percent() <= 79)
            cout << "B+";
         else if (percent() > 79 && percent() <= 89)
            cout << "A";
         else if (percent() > 89 && percent() <= 100)
            cout << "A+";
         else if (percent() > 100)
            cout << "?";
      }
   }
 
   void Mark::set(const char* name) {
      strcpy(m_name, name);
   }

   void Mark::set(const char* name, double rawMark, int outof) {
      set(name);
      set(rawMark, outof);
   }

   bool Mark::readName(const char* prompt, int maxLen) {
      bool success = true;
      if (maxLen > 50)
          maxLen = 50;
      cout << prompt;
      cin >> m_name;
      if (signed(strlen(m_name)) > maxLen) {
         cin.clear();
         flushKeyboard();
         m_name[0] = '\0';
         success = false;
      }
      return success;
   }
   
   void Mark::changeOutOf(int value) {
      double a = m_mark * ((double)value / m_outOf);
      m_outOf = (double)value;
      if ((double)value < 1) {
         m_mark = 0;
      }
      else
         m_mark = a;
   }

   double Mark::GPA()const {
      return (rawValue() * 4);
   }

   double Mark::letterBasedGPA()const {
      double a;
      if (percent() >= 0 && percent() <= 49)
         a = 0.0;
      else if (percent() > 49 && percent() <= 54)
         a = 1.0;
      else if (percent() > 54 && percent() <= 59)
         a = 1.5;
      else if (percent() > 59 && percent() <= 64)
         a = 2.0;
      else if (percent() > 64 && percent() <= 69)
         a = 2.5;
      else if (percent() > 69 && percent() <= 74)
         a = 3.0;
      else if (percent() > 74 && percent() <= 79)
         a = 3.5;
      else if (percent() > 79)
         a = 4.0;
      return a;
   }
}