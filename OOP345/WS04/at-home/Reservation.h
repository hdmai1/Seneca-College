// Name: Huu Duc Mai
// Seneca Student ID: 121367189
// Seneca email: hdmai1@myseneca.ca
// Date of completion: February 09, 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H
#include <iostream>
namespace sdds {
	class Reservation {
		std::string m_id;
		std::string m_name;
		std::string m_email;
		int m_NoOfPpl;
		int m_date;
		int m_hour;

	public:
		Reservation();
		Reservation(const std::string& res);
		std::string getID()const;
		std::string getName()const;
		std::string getEmail()const;
		int getPpl()const;
		int getDate()const;
		int getHour()const;
		friend std::ostream& operator<<(std::ostream& os, const Reservation& RO);
		Reservation& operator=(const Reservation& RO);
		
	};
	std::ostream& display(std::ostream& os, const Reservation& RO);
}
#endif