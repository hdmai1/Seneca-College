// Name: Huu Duc Mai
// Seneca Student ID: 121367189
// Seneca email: hdmai1@matrix.senecac.on.ca
// Date of completion: January 23rd, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_TIMEDEVENTS_H
#define SDDS_TIMEDEVENTS_H
#include <chrono>
#include <string>
#define MAX_REC 7
namespace sdds {
	class TimedEvents {
		int NoOfRecs = 0;
		std::chrono::steady_clock::time_point start;
		std::chrono::steady_clock::time_point end;
		struct {
			std::string ev_name{};
			std::string UofTime{};
			std::chrono::steady_clock::duration dur{};
		} obj[MAX_REC];
	public:
		TimedEvents();
		void startClock();
		void stopClock();
		void recordEvent(const char* newName);
		friend std::ostream& operator<<(std::ostream& os, const TimedEvents& TE);
	};
}

#endif