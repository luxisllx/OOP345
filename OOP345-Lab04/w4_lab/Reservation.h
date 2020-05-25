// Name: Luxi Liang
// Seneca Student ID: 165936188
// Seneca email: lliang44@myseneca.ca
// Date of completion: 
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_RESERVE_H
#define SDDS_RESERVE_H
#include <iostream>
#include <cstring>
#include <string>

namespace sdds {

	class Reservation {

		std::string id;
		std::string name;
		std::string email;
		int people;
		int day;
		int hour;

	public:
		Reservation();
		Reservation(const std::string& m_res);
		friend std::ostream& operator<< (std::ostream& os, const Reservation& event);

	};

}

#endif