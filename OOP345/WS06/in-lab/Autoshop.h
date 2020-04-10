// Name: Huu Duc Mai
// Seneca Student ID: 121367189
// Seneca email: hdmai1@myseneca.ca
// Date of completion: March 11, 2019.
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H
#include "Vehicle.h"
#include <vector>
#include <iterator>
namespace sdds {
   class Autoshop {
      std::vector<Vehicle*> m_vehicles{};
   public:
      Autoshop& operator+=(Vehicle* theVehicle);
      void display(std::ostream& out)const;
   };
}


#endif