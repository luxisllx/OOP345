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
#include "ConfirmationSender.h"
#include "Reservation.h"


using namespace std;

namespace sdds {

	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res) {
		int check = 0;
		for (int i = 0; i < tracker; i++) {
			//if the address of res equal to confirm[i]. checks to see if res is in the array
			if (&res == confirm[i]) {
				check = 1;
			}
		}

		if (check != 1) {

			const sdds::Reservation** test = new const Reservation* [tracker + 1];
			for (int i = 0; i < tracker; i++) {
				test[i]=confirm[i] ;
			}
			test[tracker] = &res;
			delete[] confirm;
			confirm = test;
			tracker++;
		}
		return *this;
	}

	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res) {

		for (int i = 0; i < tracker; i++) {

			if (&res == confirm[i]) {
				confirm[i] = nullptr;
			}
		}
		return *this;
	}
	
	ConfirmationSender::~ConfirmationSender() {
		delete[] confirm;

	}

	ConfirmationSender::ConfirmationSender(const ConfirmationSender& copy) {
		confirm = new const Reservation * [copy.tracker];
		for (int i = 0; i < copy.tracker; i++) {
			confirm[i] = copy.confirm[i];
		}
		tracker = copy.tracker;
	}

	std::ostream& operator<< (std::ostream& os, const ConfirmationSender& event) {


		if (event.tracker == 0) {
			os << "--------------------------" << endl;
			os << "Confirmations to Send" << endl;
			os << "--------------------------" << endl;
			os << "The object is empty!" << endl;
			os << "--------------------------" << endl;
		}

		else {
			os << "--------------------------" << endl;
			os << "Confirmations to Send" << endl;
			os << "--------------------------" << endl;
			for (int i = 0; i < event.tracker; i ++) {
				if (event.confirm[i] == nullptr) {

				}
				else {
					os << *event.confirm[i];
				}
				
			}
			os << "--------------------------" << endl;
		}
		return os;
	}

}