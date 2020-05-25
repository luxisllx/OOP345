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
#include <sstream>
#include "Utilities.h"
#include "Car.h"
#include "Vehicle.h"
#include "Racecar.h"


using namespace std;

namespace sdds {

	Vehicle* createInstance(std::istream& in) {
		char ch = '\0';
		char ch2 = '\0';

		std::string substr = "";
		getline(in, substr);
		std::stringstream ss(substr);
		ss >> ch >> ch2;
		if (ss) {
			if (ch == 'c' || ch == 'C') {
				return new Car(ss);
			}
			else if (ch == 'r' || ch == 'R') {
				return new Racecar(ss);
			}
			else
				throw ch;
		}
		else
			return nullptr;
	} 

		/*char buffer = in.get();
		while (buffer == ' ') {
			buffer = in.get();
		}
		if (in.eof()) {
			return nullptr;
		}

		in.putback(buffer);
		//cout<<buffer<<endl;
		if (buffer == 'c' || buffer == 'C') {
			Car* temp2 = new Car(in);
			return temp2;

		}
		else if (buffer == 'r' || buffer == 'R') {
			Racecar* temp3 = new Racecar(in);
			return temp3;
		}
		else if (in.eof()){
			throw buffer;
		}
		else {
			return nullptr;
		}*/
		
}

