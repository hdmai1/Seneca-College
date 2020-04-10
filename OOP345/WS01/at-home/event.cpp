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
		des = nullptr;
	}
	
	
	void Event::display() const {
		cout.width(3);
		cout.fill(' ');
		cout << a++ << ". ";
		if (strcmp(des, "[ No Event ]")) {
			cout.fill('0');
			cout.width(2);
			cout << start / 3600;
			cout << ":";
			cout.width(2);
			cout << (start % 3600) / 60;
			cout << ":";
			cout.width(2);
			cout << start % 60 << " -> ";
			
		}
		cout << des << endl;
	}

	void Event::setDescription(char* newDes) {
		if (newDes != nullptr && newDes[0] != '\0') {
			des = new char[strlen(newDes) + 1];
			strcpy(des, newDes);
		}
		else {
			delete[] des;
			des = new char[strlen("[ No Name ]") + 1];
			strcpy(des, "[ No Event ]");
		}

		start = g_sysClock;
	}

	Event::~Event() {
		delete[] des;
	}
	Event& Event::operator=(const Event& newE)
	{
		if (this != &newE) {
			delete[] des;
			des = new char[strlen(newE.des) + 1];
			strcpy(des, newE.des);
			start = newE.start;
		}
		return *this;
	}

	Event::Event(const Event& newE)
	{
		if (newE.des != nullptr && newE.des[0] != '\0') {
			des = new char[strlen(newE.des) + 1];
			strcpy(des, newE.des);
			start = newE.start;
		}
		else {
			des = nullptr;
		}
	}
}

