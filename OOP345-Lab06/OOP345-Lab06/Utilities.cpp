// Name: Luxi Liang
// Seneca Student ID: 165936188
// Seneca email: lliang44@myseneca.ca
// Date of completion: 03-04-2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include <iomanip>
#include "Utilities.h"


using namespace std;

namespace sdds {

	Vehicle* createInstance(std::istream& in) {
		char buffer= in.get();
		while (buffer == ' ') {
			buffer=in.get();
		}

		in.putback(buffer);

		if (buffer == 'c' || buffer == 'C') {
			Car* temp2 = new Car(in);
			return temp2;
		}
		else {
			return nullptr;
		}
	}
}