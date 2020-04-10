// Name: Huu Duc Mai
// Seneca Student ID: 121367189
// Seneca email: hdmai1@myseneca.ca
// Date of completion: February 09, 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#ifndef SDDS_RESTAURANT_H
#define SDDS_RESTAURANT_H
#include "Reservation.h"
namespace sdds {
	class Restaurant {
		size_t count = 0;
		Reservation** res{};
	public:
		Restaurant() {};
		Restaurant(Restaurant& newRes);
		Restaurant(Restaurant&& newRes);
		Restaurant(Reservation* reservations[], size_t cnt);
		size_t size() const;
		friend std::ostream& operator<<(std::ostream& os, Restaurant& RO);
		~Restaurant() {};
	};
}
#endif