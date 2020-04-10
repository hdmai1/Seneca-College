// Name: Huu Duc Mai
// Seneca Student ID: 121367189
// Seneca email: hdmai1@myseneca.ca
// Date of completion: Feb 02, 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_SETSUMMABLE_H
#define SDDS_SETSUMMABLE_H
#include "Set.h"
namespace sdds {
	template<typename T, unsigned int N, typename K, typename V>
	class SetSummable: public Set<T,N> {
	public:
		SetSummable() :Set<T, N>() {};
		V accumulate(const K& key) {
			V acc;
			acc = this->operator[](0).getInitialValue();
			for (std::size_t i = 0; i < this->size(); i++) {
				acc = (this->operator[](i)).sum(key, acc);
			}
			return acc;
		}		
	};
}
#endif