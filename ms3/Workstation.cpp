
// Name: Luxi Liang
// Seneca Student ID: 165936188
// Seneca email: lliang44@myseneca.ca
// Date of completion:
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include "Utilities.h"
#include "Station.h"
#include "Workstation.h"

using namespace std;


Workstation::Workstation(const std::string& str):Station(str) {
	//cout << "set " << getItemName() << " to nullptr" << endl;
	m_pNextStation = nullptr;
}

void Workstation::runProcess(std::ostream& os) {
	if (m_orders.empty()) {
		return;
	}

	m_orders.front().fillItem(*this, os);
}

bool Workstation::moveOrder() {

	if (m_orders.empty()) {
		return false;
	}

	if (m_orders.front().isItemFilled(getItemName()) == true) {
		*m_pNextStation += std::move(m_orders.front());

		m_orders.pop_front();
		return true;
	}
	else {
		return false;
	}
}

void Workstation::setNextStation(Workstation& station) {

	//cout << "set " << getItemName() << " to new value" << endl;
	m_pNextStation = &station;
}

const Workstation* Workstation::getNextStation() const {
	return m_pNextStation;
}

bool Workstation::getIfCompleted(CustomerOrder& order) {
	if (m_orders.empty()) {
		return false;
	}
	if (m_orders.front().isOrderFilled()) {
		order = move(m_orders.front());

		m_orders.pop_front();
		return true;
	}
	else {
		return false;
	}

}

void Workstation::display(std::ostream& os) const{

	if (m_pNextStation == nullptr)
		os << getItemName() << " --> END OF LINE" << endl;
	else
		os << getItemName() << " --> " << m_pNextStation->getItemName() <<endl;
}


Workstation& Workstation::operator+=(CustomerOrder&& aa) {

	m_orders.push_back(std::move(aa));

	return *this;
}
