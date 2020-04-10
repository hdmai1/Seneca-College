// Name: Huu Duc Mai
// Seneca Student ID: 121367189
// Seneca email: hdmai1@myseneca.ca
// Date of completion: March 11, 2019.
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#include "Autoshop.h"
namespace sdds {
   Autoshop& Autoshop::operator+=(Vehicle* theVehicle) {
      m_vehicles.push_back(theVehicle);
      return *this;
   };

   void Autoshop::display(std::ostream& out)const {
      out << "--------------------------------\n";
      out << "| Cars in the autoshop!        |\n";
      out << "--------------------------------\n";

      for (auto it = m_vehicles.begin(); it < m_vehicles.end(); it++)
         (*it)->display(out);
      out << "--------------------------------\n";
   };
}