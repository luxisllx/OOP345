// Name: Luxi Liang
// Seneca Student ID: 165936188
// Seneca email: lliang44@myseneca.ca
// Date of completion: 02/09/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include "Reservation.h"
#include "Restaurant.h"



using namespace std;

namespace sdds {

	Restaurant::Restaurant(Reservation* reservations[], size_t cnt) {

		reserve = new Reservation[cnt];
		for (size_t i = 0; i < cnt; i++) {
			// reservations is a pointer type 
			reserve[i] = *reservations[i];
		}
		tracker = cnt;

	}

	size_t Restaurant::size() const {
		return tracker;

	}

	Restaurant::~Restaurant() {
			delete[] reserve;
		
	}

	//copy 
	Restaurant::Restaurant(const Restaurant& copy) {
		reserve = new Reservation[copy.tracker];
		for (int i = 0; i < copy.tracker; i++) {
			// reservations is a pointer type 
			reserve[i] = copy.reserve[i];
		}
		tracker = copy.tracker;

	}

	std::ostream& operator<< (std::ostream& os, const Restaurant& event) {

		if (event.size() == 0) {
			os << "--------------------------" << endl;
			os << "Fancy Restaurant" << endl;
			os << "--------------------------" << endl;
			os << "The object is empty!" << endl;
			os << "--------------------------" << endl;
		}

		else {
			os << "--------------------------" << endl;
			os << "Fancy Restaurant" << endl;
			os << "--------------------------" << endl;
			for (size_t i = 0; i < event.size(); i++) {
				os << event.reserve[i];
			}
			os << "--------------------------" << endl;

		}
		return os;
	}

}