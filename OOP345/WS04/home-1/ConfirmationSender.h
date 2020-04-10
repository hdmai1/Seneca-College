// Name: Huu Duc Mai
// Seneca Student ID: 121367189
// Seneca email: hdmai1@myseneca.ca
// Date of completion: February 09, 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#ifndef SDDS_CONFIRMATIONSENDER_H
#define SDDS_CONFIRMATIONSENDER_H
#include "Reservation.h"
namespace sdds {
	class ConfirmationSender {
		const Reservation** m_res{};
		size_t m_count{};
	public:
		ConfirmationSender() {};
		ConfirmationSender(ConfirmationSender& newcs);
		ConfirmationSender(ConfirmationSender&& newcs);
		ConfirmationSender& operator+=(const Reservation& res);
		ConfirmationSender& operator-=(const Reservation& res);
		friend std::ostream& operator<<(std::ostream& os, const ConfirmationSender& RO);
		~ConfirmationSender() {};
	};
}
#endif
