// Name: Huu Duc Mai
// Seneca Student ID: 121367189
// Seneca email: hdmai1@matrix.senecac.on.ca
// Date of completion: January 23rd, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_RECORDSET_H
#define SDDS_RECORDSET_H
#include <string>
namespace sdds {
	class RecordSet {
		std::string* str;
		std::size_t NoOfStrs;
	public:
		RecordSet();
		RecordSet(const char* newName);
		RecordSet(const RecordSet& RO);
		RecordSet& operator=(const RecordSet& RO);
		~RecordSet();
		size_t size()const;
		std::string getRecord(size_t)const;
		RecordSet(RecordSet&& N); //move constructor;
		RecordSet& operator=(RecordSet&& N); //move assignment operator
		RecordSet& AllocateAndCopy(const RecordSet& RO);
	};
}
#endif // !SDDS_RECORDSET_H
