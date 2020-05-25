// Name: Luxi Liang
// Seneca Student ID: 165936188
// Seneca email: lliang44@myseneca.ca
// Date of completion: 02/09/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.


#ifndef SDDS_CONF_H
#define SDDS_CONF_H
#include <iostream>
#include "ConfirmationSender.h"
#include "Reservation.h"

namespace sdds {

	class Reservation;

	class ConfirmationSender {

		// array of pointers
		const sdds::Reservation** confirm = nullptr;
		int tracker = 0;

	public:
		ConfirmationSender() { confirm = nullptr; tracker = 0; };
		ConfirmationSender& operator+=(const Reservation& res);
		ConfirmationSender& operator-=(const Reservation& res);
		friend std::ostream& operator<< (std::ostream& os, const ConfirmationSender& event);
		//copy
		ConfirmationSender(const ConfirmationSender&);
		~ConfirmationSender();
		
		ConfirmationSender(ConfirmationSender&& src) { *this = std::move(src); };
		ConfirmationSender& operator=(ConfirmationSender&& src) {
			if (this != &src) {
				delete[] confirm;
				confirm = src.confirm;
				tracker = src.tracker;
				src.confirm = nullptr;
				src.tracker = 0u;
			}
			return *this;
		};
		
	};
	
}

#endif
