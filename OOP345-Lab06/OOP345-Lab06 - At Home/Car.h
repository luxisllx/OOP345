// Name: Luxi Liang
// Seneca Student ID: 165936188
// Seneca email: lliang44@myseneca.ca
// Date of completion: 03-04-2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_CAR_H
#define SDDS_CAR_H
#include <iostream>
#include "Vehicle.h"
using namespace std;
namespace sdds {


	class Car : public Vehicle {
		std::string maker;
		std::string cond;
		double tSpeed;
	public:
		Car(std::istream&);
		Car();
		std::string condition() const;
		double topSpeed() const;
		void display(std::ostream& out) const;
		void trim(std::string& str) const;
	};

}

#endif


