// Name: Luxi Liang
// Seneca Student ID: 165936188
// Seneca email: lliang44@myseneca.ca
// Date of completion:02/09/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.


#ifndef SDDS_REST_H
#define SDDS_REST_H
#include <iostream>
#include "Reservation.h"

namespace sdds {

	class Reservation;
	

	class Restaurant {
		//array of object
		Reservation* reserve = nullptr;
		//this member is to keep track of array size
		int tracker=0;

	public:
		Restaurant(Reservation* reservations[], size_t cnt);
		size_t size() const;
		
		~Restaurant();
		
		//move constructor
		Restaurant(Restaurant&& src) { *this = std::move(src); };
		Restaurant& operator=(Restaurant&& src) {
			if (this != &src) {
				delete[] reserve;
				reserve = src.reserve;
				tracker = src.tracker;
				src.reserve = nullptr;
				src.tracker = 0u;
			}
			return *this;
		};

		//deep copy constructor
		Restaurant(const Restaurant&);

		friend std::ostream& operator<< (std::ostream& os, const Restaurant& event);
	};

}

#endif
