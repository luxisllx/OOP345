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
#include "Autoshop.h"
#include "Vehicle.h"

using namespace std;

namespace sdds {

	Autoshop& Autoshop::operator +=(Vehicle* theVehicle) {
		m_vehicles.push_back(theVehicle);
		return *this;
	}

	void Autoshop::display(std::ostream& out) const {

		auto ptr = m_vehicles.begin();
		out << "--------------------------------" << endl;
		out << "| Cars in the autoshop!        |" << endl;
		out << "--------------------------------" << endl;
		for (ptr = m_vehicles.begin(); ptr < m_vehicles.end(); ptr++)
			(*ptr)->display(out);
		out << "--------------------------------" << endl;

	}

	Autoshop::~Autoshop(){
		auto ptr = m_vehicles.begin();
		for (ptr = m_vehicles.begin(); ptr < m_vehicles.end(); ptr++)
			delete* ptr;
	}
}