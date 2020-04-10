#define _CRT_SECURE_NO_WARNINGS
#include "event.h"
#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;
unsigned int g_sysClock = 0;
namespace sdds {
	static int a = 1;
	Event::Event() {
		des[0] = '\0';
		start = 0;
	}

	void Event::display() const {
		cout.width(3);
		cout.fill(' ');
		cout << a++ << ". ";
		if (des[0] == '\0' || des == nullptr) {
			cout << "[ No Event ]" << endl;
		}
		else {
			cout.fill('0');
			cout.width(2);
			cout << start / 3600;
			cout << ":";
			cout.width(2);
			cout << (start % 3600) / 60;
			cout << ":";
			cout.width(2);
			cout << start % 60 << " -> ";
			cout << des << endl;
		}
		
	}


	void Event::setDescription(char* newDes){
		if (newDes != nullptr && newDes[0] != '\0' ) {
			strcpy(des, newDes);
		}
		else {
			des[0] = '\0';
		}

		start = g_sysClock;
	}
}


