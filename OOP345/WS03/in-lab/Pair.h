
// Name: Huu Duc Mai
// Seneca Student ID: 121367189
// Seneca email: hdmai1@myseneca.ca
// Date of completion: 
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#ifndef SDDS_PAIR_H
#define SDDS_PAIR_H
#include <iostream>
namespace sdds {
   template<typename K, typename V>
   class Pair {
      K m_key;
      V m_val;
   public:
      Pair() {};
      Pair(const K& key, const V& value) {
         m_key = key;
         m_val = value;
      };
      const K& key() const {
         return m_key;
      };
      const V& value() const {
         return m_val;
      };
      void display(std::ostream& os) const {
         os << m_key << " : " << m_val << std::endl;
      };
   };
   template <typename K, typename V>
   std::ostream& operator<<(std::ostream& os, const Pair<K, V>& pair) {
      pair.display(os);
      return os;
   };
}

#endif // !SDDS_PAIR_H
