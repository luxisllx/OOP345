// Name: Luxi Liang
// Seneca Student ID: 165936188
// Seneca email: lliang44@myseneca.ca
// Date of completion: 01-19-2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_LAB01_H
#define SDDS_LAB01_H
#include <iostream>

//global variable 
extern unsigned int g_sysClock;

namespace sdds {

	class Event{
	
		//char value[128];
		char* value;
		size_t time;
	
	public:
		Event();
		Event(const Event&); //copy constructor
		Event& operator =(const Event&); //copy assignment 
		void display();
		void setDescription(const char*);
		~Event();


	};
}

#endif
