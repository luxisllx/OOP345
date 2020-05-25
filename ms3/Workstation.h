
// Name: Luxi Liang
// Seneca Student ID: 165936188
// Seneca email: lliang44@myseneca.ca
// Date of completion: 
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_WORKSTATION_H
#define SDDS_WORKSTATION_H
#include <iostream>
#include <deque>
#include <string>
#include "Station.h"
#include "CustomerOrder.h"
class Workstation :
	public Station
{
	std::deque<CustomerOrder> m_orders;
	Workstation* m_pNextStation;

public:
	Workstation(const std::string&);
	Workstation(const Workstation& p2) = delete;
	Workstation& operator=(const Workstation& other) = delete;
	Workstation(Workstation&& a) noexcept = delete;
	Workstation& operator=(Workstation&& a) noexcept = delete;
	void runProcess(std::ostream&);
	bool moveOrder();
	void setNextStation(Workstation& station);
	const Workstation* getNextStation() const;
	bool getIfCompleted(CustomerOrder& order);
	void display(std::ostream&)const;
	Workstation& operator+=(CustomerOrder&&);

};

#endif


