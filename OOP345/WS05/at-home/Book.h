// Name: Huu Duc Mai
// Seneca Student ID: 121367189
// Seneca email: hdmai1@myseneca.ca
// Date of completion: Feb 18, 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include <iostream>
#include <string>
#include <iomanip>
namespace sdds {
   class Book {
      std::string m_author{};
      std::string m_title{};
      std::string m_country{};
      int m_year{};
      double m_price{};
      std::string m_desc{};
   public:
      Book() { m_price = 0; };
      const std::string& title()const {return m_title;}
      const std::string& country()const { return m_country; }
      const int& year() const { return m_year; }
      double& price() { return m_price; }
      Book(const std::string& strBook);
      friend std::ostream& operator<<(std::ostream& os, const Book& newBook);
      template<typename T>
      void fixSpelling(T spellChecker) {
         spellChecker(m_author);
         spellChecker(m_title);
         spellChecker(m_country);
         spellChecker(m_desc);
      }
   };
   //helper functions
   std::string removeLSpaces(const std::string& str);
   std::string removeRSpaces(const std::string& str);
   std::string removeAll(std::string str1, std::string& str2);
   double removeAll(double pr, std::string& str);
   int removeAll(int yr, std::string& str);
}
#endif