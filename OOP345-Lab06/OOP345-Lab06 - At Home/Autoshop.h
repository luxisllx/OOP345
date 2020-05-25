// Name: Luxi Liang
// Seneca Student ID: 165936188
// Seneca email: lliang44@myseneca.ca
// Date of completion: 03-04-2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H
#include <iostream>
#include <vector>
#include <functional>
#include "Vehicle.h"
#include <list>

namespace sdds {

	class Autoshop {
		std::vector<Vehicle*> m_vehicles;
	public:
		Autoshop& operator +=(Vehicle* theVehicle);
		void display(std::ostream& out) const;
		~Autoshop();
		template <class T>
		void select(T test, std::list<const Vehicle*>& vehicles) {
			//auto ptr = m_vehicles.begin();
			for (auto ptr = m_vehicles.begin(); ptr < m_vehicles.end(); ptr++) {
				if (test(*ptr)) {
					vehicles.push_back(*ptr);
				}
			}

		}
		
	};

}

#endif

