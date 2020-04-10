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
		friend std::ostream& operator<<(std::ostream& os, Reservation& RO);
	};
	std::ostream& display(std::ostream& os, Reservation& RO);
}
#endif