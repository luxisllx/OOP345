// Name: Luxi Liang
// Seneca Student ID: 165936188
// Seneca email: lliang44@myseneca.ca
// Date of completion:02/09/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <string>
#include <iostream>
#include "Reservation.h"

using namespace std;

namespace sdds {

	Reservation::Reservation() {
		id= "";
		name = "";
		email = "";
		people = 0;
		day = 0;
		hour = 0;

	}

	Reservation::Reservation(const std::string& m_res) {

		// the length of id is from first position to position before the semi-colon
		// use find function

		int beginIndex = 0;
		int endIndex =0;
		const std::string WHITESPACE = " \n\r\t\f\v";
		
		endIndex = m_res.find(":", beginIndex);
		id = m_res.substr(beginIndex, endIndex);

		size_t start = id.find_first_not_of(WHITESPACE);
		id = (start == std::string::npos) ? "" : id.substr(start);

		size_t end = id.find_last_not_of(WHITESPACE);
		id = (end == std::string::npos) ? "" : id.substr(0, end + 1);


		// the length of name is from : to first comma

		beginIndex = endIndex;
		endIndex = m_res.find(",", endIndex);
		name = m_res.substr(beginIndex+1, endIndex - beginIndex-1);

		start = name.find_first_not_of(WHITESPACE);
		name = (start == std::string::npos) ? "" : name.substr(start);

		end = name.find_last_not_of(WHITESPACE);
		name = (end == std::string::npos) ? "" : name.substr(0, end + 1);

		// the length of email is from first , to second ,

		beginIndex = endIndex;
		endIndex = m_res.find(",", endIndex+1);
		email = m_res.substr(beginIndex+1, endIndex - beginIndex-1);

		start = email.find_first_not_of(WHITESPACE);
		email = (start == std::string::npos) ? "" : email.substr(start);

		end = email.find_last_not_of(WHITESPACE);
		email = (end == std::string::npos) ? "" : email.substr(0, end + 1);

		// the length of party size is from second , to third , 

		beginIndex = endIndex;
		endIndex = m_res.find(",", endIndex + 1);
		people = std::stoi(m_res.substr(beginIndex + 1, endIndex - beginIndex - 1));

		//the length of day 

		beginIndex = endIndex;
		endIndex = m_res.find(",", endIndex + 1);
		day = std::stoi(m_res.substr(beginIndex + 1, endIndex - beginIndex - 1));

		//length of hour 

		beginIndex = endIndex;
		hour = std::stoi(m_res.substr(beginIndex + 1));
	}

	std::ostream& operator<< (std::ostream& os, const Reservation& event) {
		
		string email = "<" + event.email + ">";
		if (event.hour >= 6 && event.hour <= 9) {
			os << "Reservation " << event.id << ": ";
			os.width(10);
			os << std::right;
			os << event.name;
			os << "  ";
			os.width(20);
			os << std::left;
			os << email;
			os << "    ";
			os << "Breakfast on day " << event.day << " @ " << event.hour << ":00 for " << event.people << " people." << endl;
		}

		else if (event.hour >= 11 && event.hour <= 15) {
			os << "Reservation " << event.id << ": ";
			os.width(10);
			os << std::right;
			os << event.name;
			os << "  ";
			os.width(20);
			os << std::left;
			os << email;
			os << "    ";
			os << "Lunch on day " << event.day << " @ " << event.hour << ":00 for " << event.people << " people." << endl;
		}

		else if (event.hour >= 17 && event.hour <= 21) {
			os << "Reservation " << event.id << ": ";
			os.width(10);
			os << std::right;
			os << event.name;
			os << "  ";
			os.width(20);
			os << std::left;
			os << email;
			os << "    "; 
			os << "Dinner on day " << event.day << " @ " << event.hour << ":00 for " << event.people << " people." << endl;
		}

		else  {
			os << "Reservation " << event.id << ": ";
			os.width(10);
			os << std::right;
			os << event.name;
			os << "  ";
			os.width(20);
			os << std::left;
			os << email;
			os << "    ";
			os << "Drinks on day " << event.day << " @ " << event.hour << ":00 for " << event.people << " people." << endl;
		}
		return os;
	}

	
}