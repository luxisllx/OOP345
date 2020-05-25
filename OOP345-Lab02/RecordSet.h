// Name: Luxi Liang
// Seneca Student ID: 165936188
// Seneca email: lliang44@myseneca.ca
// Date of completion: Jan 20, 2020
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_LAB02_H
#define SDDS_LAB02_H
#include <iostream>
#include <string>

namespace sdds {

	class RecordSet {

		std::string* str;
		int currentStr;

	public:
		RecordSet();
		RecordSet(const char*);
		RecordSet(const RecordSet&);
		RecordSet& operator=(const RecordSet&);
		// Move constructor
		RecordSet(RecordSet&&);
		// Move assignment Operator
		RecordSet& operator = (RecordSet&&);
		~RecordSet();
		size_t size() const;
		std::string getRecord(size_t) const;


	};

}

#endif


