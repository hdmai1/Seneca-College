// Name: Huu Duc Mai
// Seneca Student ID: 121367189
// Seneca email: hdmai1@myseneca.ca
// Date of completion: 
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#ifndef SDDS_SET_H
#define SDDS_SET_H
namespace sdds {
   template<typename T, unsigned int N>
   class Set {
      T element[N];
      std::size_t counter = 0;  
   public:
      std::size_t size()const {
         return counter;
      };
      const T& operator[](std::size_t idx)const {
         return element[idx];
      };
      void operator+=(const T& item) {
         if (counter < N) {
            element[counter] = item;
            counter++;
         }
      };
   
   };
}
#endif