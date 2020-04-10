// Name: Huu Duc Mai
// Seneca Student ID: 121367189
// Seneca email: hdmai1@myseneca.ca
// Date of completion: February 09, 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#include "Restaurant.h"
namespace sdds {
   Restaurant::Restaurant(Reservation* reservations[], size_t cnt) {
      res = reservations;
      count = cnt;
   }
   Restaurant::Restaurant(Restaurant& newRes) {
      res = newRes.res;
      count = newRes.count;
   }
   Restaurant::Restaurant(Restaurant&& newRes) {
      res = newRes.res;
      count = newRes.count;
      newRes.res = nullptr;
      newRes.count = 0;
   }
   size_t Restaurant::size()const {
      return count;
   }
   std::ostream& operator<<(std::ostream& os, Restaurant& RO) {
      os << "--------------------------\n";
      os << "Fancy Restaurant\n";
      os << "--------------------------\n";
      if (RO.count == 0) 
      os << "The object is empty!\n";
      else {
         for (size_t i = 0; i < RO.count; i++) {
            os << *RO.res[i];
         }
      }
      os << "--------------------------\n";
      return os;
   }

}