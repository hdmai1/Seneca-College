// Name: Huu Duc Mai
// Seneca Student ID: 121367189
// Seneca email: hdmai1@matrix.senecac.on.ca
// Date of completion: January 23rd, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include "TimedEvents.h"
#include <iostream>

using namespace std;
namespace sdds {
	TimedEvents::TimedEvents() {
	}

	void TimedEvents::startClock() {
		start = std::chrono::steady_clock::now();
	}
	void TimedEvents::stopClock(){
		end = std::chrono::steady_clock::now();
	}

	void TimedEvents::recordEvent(const char* newName) {
		if (NoOfRecs < MAX_REC) {
			obj[NoOfRecs].ev_name = newName;
			obj[NoOfRecs].UofTime = "nanoseconds";
			obj[NoOfRecs].dur = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
			NoOfRecs++;
		}
	}

	ostream& operator<<(ostream& os, const TimedEvents& TE) {
		os << "--------------------------\n";
		os << "Execution Times:\n";
		os << "--------------------------\n";
		for (int i = 0; i < TE.NoOfRecs; i++) {
			os.width(20);
			os << std::left;
			os << TE.obj[i].ev_name << " ";
			os.width(12);
			os << std::right;
			os << TE.obj[i].dur.count() << " ";
			os << TE.obj[i].UofTime << "\n";
		}
		os << "--------------------------\n";
		return os;
	}
}