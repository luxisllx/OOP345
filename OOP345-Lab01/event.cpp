
// Name: Luxi Liang
// Seneca Student ID: 165936188
// Seneca email: lliang44@myseneca.ca
// Date of completion: January 19, 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iomanip>
#include <iostream>
#include "event.h"

using namespace std;
unsigned int g_sysClock;
namespace sdds {

	Event::Event() {
		//value[0] = '\0';
		value = nullptr;
		time = 0;
	}

	//copy constructor
	// copying source object into new object of same type
	Event::Event(const Event& cpycon) {
		time = cpycon.time;
		if (cpycon.value == nullptr || cpycon.value[0] == '\0') {
			value = nullptr;
		}
		else {
			value = new char[strlen(cpycon.value) + 1];
			strcpy(value, cpycon.value);
		}
	
	}

	//copy assignment 
	Event& Event::operator =(const Event& cpyassign) {
		// if address of parameter is same as the current object, return current object
		if (&cpyassign == this) {
			return *this;
		}

		else {
			delete[] value;
			value = nullptr;
			time = cpyassign.time;
			if (cpyassign.value != nullptr && cpyassign.value[0] != '\0') {
				value = new char[strlen(cpyassign.value) + 1];
				strcpy(value, cpyassign.value);
			}
	
			return *this;

		}
	}

	void Event::display() {

		static unsigned COUNTER = 0;
		COUNTER++;
		if (value!= nullptr) {
			std::cout << std::setfill(' ') << std::setw(3) << COUNTER << ". "<< std::setfill('0')<< std::setw(2) << time / 3600 << ":" << std::setfill('0') << std::setw(2) << (time - (time / 3600) * 3600) / 60 << ":" <<std::setfill('0') << std::setw(2) << time % 60 << " -> " << value <<endl;
		}
		else {
			std::cout << std::setfill(' ') << std::setw(3)<< COUNTER << ". [ No Event ]" <<endl;
		}
	}
	void Event::setDescription(const char* param) {
		if (param != nullptr && param[0] != '\0') {
			value = new char[strlen(param) + 1];
			strcpy(value, param);
			time = g_sysClock;
			
		}
		else {
			value = nullptr;
			time = 0;
		}
	}

	// deconstructor to avoid memory leak
	Event::~Event() {
		delete[] value;
	}

}