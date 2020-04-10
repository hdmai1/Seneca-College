// Name: Huu Duc Mai
// Seneca Student ID: 121367189
// Seneca email: hdmai1@matrix.senecac.on.ca
// Date of completion: January 23rd, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.


#include "RecordSet.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <utility>

namespace sdds {
	RecordSet::RecordSet(){
		str = nullptr;
		NoOfStrs = 0;
	}

	RecordSet::~RecordSet() {
		delete[] str;
	}

	RecordSet::RecordSet(const char* fileName){
		std::ifstream file(fileName);
		std::string temp;
		NoOfStrs = 0;
		while (!file.eof()) {
			std::getline(file, temp, ' '); 
			NoOfStrs++; 
		}
		str = new std::string[NoOfStrs];
		
		file.seekg(0);
		for (size_t i = 0; i < NoOfStrs && !file.eof(); i++) {
			std::getline(file, str[i], ' ');
		}
		file.close();
	}

	RecordSet::RecordSet(const RecordSet& RO) {
		NoOfStrs = RO.NoOfStrs;
		if (RO.str != nullptr) {
			str = new std::string[RO.NoOfStrs];
			for (size_t i = 0; i < RO.NoOfStrs; i++) {
				str[i] = RO.str[i];
			}
		}
		else {
			str = nullptr;
			NoOfStrs = 0;
		}
	}
	RecordSet& RecordSet::operator=(const RecordSet& RO) {
		if (this != &RO) {
			delete[] str;
			str = new std::string[RO.NoOfStrs];
			NoOfStrs = RO.NoOfStrs;
			for (size_t i = 0; i < RO.NoOfStrs; i++) {
				str[i] = RO.str[i];
			}
		}
		return *this; 
	}

	size_t RecordSet::size()const {
		return NoOfStrs;
	}

	std::string RecordSet::getRecord(size_t index)const {
		std::string temp;
		if (index <= NoOfStrs && index >= 0) {
			if (str == nullptr) {
				temp = "";
			}
			else {

				temp = str[index];
			}
		}
		else {
			temp = "";
		}
		return temp;
	}
}






