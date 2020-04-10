#include "Book.h"

namespace sdds {

/* 1. remove left spaces;
   2.find  ' , ' ;
   3. trim string to ',' => assign to a temp.
   */
   const std::string spaces = " \n\r\t\f\v";
   Book::Book(const std::string& strBook) {
      std::string temp = strBook;
      m_author = removeRSpaces(removeAll(m_author,temp));
      m_title = removeRSpaces(removeAll(m_title, temp));
      m_country = removeRSpaces(removeAll(m_country, temp));
      m_price = removeAll(m_price, temp);
      m_year = removeAll(m_year, temp);
      m_desc = removeRSpaces(removeLSpaces(temp));
   }
   std::string Book::removeRSpaces(const std::string& str) {
      size_t index = str.find_last_not_of(spaces);
      return (index == std::string::npos) ? "" : str.substr(0, index + 1);
   }
   std::string Book::removeLSpaces(const std::string& str){
      size_t index = str.find_first_not_of(spaces);
      return (index == std::string::npos) ? "" : str.substr(index);
   }
   std::string Book::removeAll(std::string str1, std::string& str2) {
      size_t index = str2.find(',');
      str1 = str2.substr(0, index);
      str2.erase(0, index + 1);
      str2 = removeLSpaces(str2);
      return str1;
   }
   double Book::removeAll(double pr, std::string& str) {
      size_t index = str.find(',');
      pr = std::stod(str.substr(0, index));
      str.erase(0, index + 1);
      str = removeLSpaces(str);
      return pr;
   }

   int Book::removeAll(int yr, std::string& str) {
      size_t index = str.find(',');
      yr = std::stoi(str.substr(0, index));
      str.erase(0, index + 1);
      str = removeLSpaces(str);
      return yr;
   };
   std::ostream& operator<<(std::ostream& os, const Book& newBook){
      /* os.width(20);
       os << newBook.m_author;
       os << "|" << os.width(22) << newBook.m_title;
       os << "|" << os.width(5) << newBook.m_country;
       os << "|" << os.width(4) << newBook.m_year;
       os << "|" << os.width(6);
       os << std::setprecision(2);
       os << std::fixed << newBook.m_price;
       os << "|" << newBook.m_desc; */
      os << std::setw(20) << newBook.m_author << " | "
         << std::setw(22) << newBook.m_title << " | "
         << std::setw(5) << newBook.m_country << " | "
         << std::setw(4) << newBook.m_year << " | "
         << std::setw(6) << std::fixed << std::setprecision(2) << newBook.m_price << " | "
         << newBook.m_desc << std::endl;
      return os;
   }
}