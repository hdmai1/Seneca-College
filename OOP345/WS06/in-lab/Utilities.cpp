// Name: Huu Duc Mai
// Seneca Student ID: 121367189
// Seneca email: hdmai1@myseneca.ca
// Date of completion: March 11, 2019.
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#include "Utilities.h"
namespace sdds {
   Vehicle* createInstance(std::istream& in) {
      std::string temp;
      getline(in, temp, '\n');
      std::stringstream ss(temp);
      if (temp[0] == 'c' || temp[0] == 'C')
         return new Car(ss);
      else
         return nullptr;
   };
}