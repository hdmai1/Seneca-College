// Metal.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Metal.h"
#include <cstring>
using namespace std;
namespace sdds {
   Metal::Metal() {
      m_name = nullptr;
      m_mohs = 0;
   };

   Metal::Metal(double newWeight, int newPurity, const char* newClassification, const char* name, double mohs): Ore(newWeight, newPurity, newClassification){
      if (name == nullptr || name[0] == '\0') {
         m_name = nullptr;
         m_mohs = 0;
      }
      else {
         m_name = new char[NAME_LEN];
         strncpy(m_name, name, NAME_LEN);
         if (mohs > 0)
            m_mohs = mohs;
         else
            m_mohs = DEFAULT_MOHS;
      }
   };

   Metal::~Metal() {
      delete[] m_name;
   };
   
   void Metal::refine() {
      if (Ore::refine())
         m_mohs++;
   };
   
   std::ostream& Metal::display(std::ostream& os) const {
      if (m_name == nullptr && m_mohs == 0) {
         os << "This metal is imaginary" << endl;
      }
      else {
         os << "Name: " << m_name << endl;
         Ore::display(os);
         os << "Mohs: " << m_mohs << endl;
      }
      return os;
   };
   
   std::istream& Metal::input(std::istream& is) {
      char temp[NAME_LEN];
      cout << "Enter a value for this metal's name: ";
      is.getline(temp, NAME_LEN, '\n');
      delete[] m_name;
      m_name = new char[strlen(temp) + 1];
      strcpy(m_name, temp);

      double temp_mohs;
      cout << "Enter a value for this metal's mohs: ";
      is >> temp_mohs;
      if (temp_mohs > 0)
         m_mohs = temp_mohs;
      else
         m_mohs = DEFAULT_MOHS;
      Ore::input(is);

      return is;
   };
   
   std::ostream& operator<<(std::ostream& os, const Metal& met) {
      os << "Metal" << endl;
      met.display(os);
      return os;
   };
   
   std::istream& operator>>(std::istream& is, Metal& met) {
      met.input(is);
      return is;
   };
}
