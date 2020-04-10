// Name: Huu Duc Mai
// Seneca Student ID: 121367189
// Seneca email: hdmai1@myseneca.ca
// Date of completion: Feb 02, 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#ifndef SDDS_PAIRSUMMABLE_H
#define SDDS_PAIRSUMMABLE_H
#include "Pair.h"
#include <string>
#include <iostream>
namespace sdds {
	template<typename K, typename V>
	class PairSummable :public Pair<K, V> {
		static V m_sum;
		static size_t m_field;
	public:
		static const V& getInitialValue() {
			return m_sum;
		}
		PairSummable() :Pair<K, V>() {};
		PairSummable(const K& key, const V& value) :Pair<K, V>(key, value) {
			if (m_field < key.length()) {
				m_field = key.length();
			}
		}
		V sum(const K& key, const V& val) const {
			int temp;
			if (this->key() == key) {
				temp = this->value() + val;
			}
			else
				temp = val;
			return temp;
		}

		void display(std::ostream& os) const {
			os << std::left << std::setw(m_field);
			Pair<K, V>::display(os);
			os << std::right;
		}
	};


	template<>
	std::string PairSummable<std::string, std::string>::m_sum = "";

	template<>
	int PairSummable<std::string, int>::m_sum = 0u;

	template<>
	std::string PairSummable<std::string, std::string>::sum(const std::string& key, const std::string& value) const {
		std::string temp = "";
		if (PairSummable<std::string, std::string>::key() == key) {
			if (value != "") {
				temp = value + ", " + this->value();

			}
			else {
				temp = this->value();
			}
		}
		else {
			temp = value;
		}
		return temp;
	}
	template<typename K, typename V>
	std::size_t PairSummable<K, V>::m_field = 0u;
}
#endif