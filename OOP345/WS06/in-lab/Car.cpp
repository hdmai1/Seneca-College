// Name: Huu Duc Mai
// Seneca Student ID: 121367189
// Seneca email: hdmai1@myseneca.ca
// Date of completion: March 11, 2019.
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#include "Car.h"
namespace sdds {
   const std::string spaces = " \n\r\t\f\v";
   std::string removeRSpaces(const std::string& str) {
      size_t index = str.find_last_not_of(spaces);
      return (index == std::string::npos) ? "" : str.substr(0, index + 1);
   };

   std::string removeLSpaces(const std::string& str) {
      size_t index = str.find_first_not_of(spaces);
      return (index == std::string::npos) ? "" : str.substr(index);
   }

   std::string removeAll(std::string str1, std::string& str2) {
      size_t index = str2.find(',');
      str1 = str2.substr(0, index);
      str2.erase(0, index + 1);
      str2 = removeLSpaces(str2);
      return str1;
   }
   Car::Car(std::istream& is) {
      std::string temp{};
      std::getline(is, temp);
      std::string tag;
      tag = removeAll(tag, temp);
      maker = removeRSpaces(removeAll(maker, temp));
      cond = removeAll(cond, temp);
      if (cond == "u")
         cond = "used";
      else if (cond == "b")
         cond = "broken";
      else if (cond == "n")
         cond = "new";
      else
         cond = "Invalid Condition";
      top_speed = std::atoi(temp.c_str());

   };
   void Car::display(std::ostream& out) const {
      out << "| ";
      out << std::right;
      out.width(10);
      out << maker << " | ";
      out << std::left;
      out.width(6);
      out << cond;
      out << " | ";
      out << std::left;
      out.width(6);
      out << std::fixed;
      out << std::setprecision(2);
      out << top_speed;
      out << " |" << std::endl;
   };

}