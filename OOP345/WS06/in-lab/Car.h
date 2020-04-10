// Name: Huu Duc Mai
// Seneca Student ID: 121367189
// Seneca email: hdmai1@myseneca.ca
// Date of completion: March 11, 2019.
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_CAR_H
#define SDDS_CAR_H
#include "Vehicle.h"
#include <iostream>
#include <iomanip>
namespace sdds {
   std::string removeRSpaces(const std::string& str);
   std::string removeLSpaces(const std::string& str);
   std::string removeAll(std::string str1, std::string& str2);
   class Car : public Vehicle {
      std::string maker{};
      std::string cond{};
      double top_speed{};

   public:
      Car(std::istream& is);
      std::string condition() const { return cond; };
      double topSpeed()const { return top_speed; };
      void display(std::ostream& out) const;
   };
}


#endif