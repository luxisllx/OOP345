// Name: Luxi Liang
// Seneca Student ID: 165936188
// Seneca email: lliang44@myseneca.ca
// Date of completion: Jan 20, 2020
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include <string>
#include <chrono>
#include <iomanip>
#include "TimedEvents.h"

using namespace std;

namespace sdds {

	//static int recording = 0;

	TimedEvents::TimedEvents() {
		curRecord = 0;
		
	}

	// begins the clock
	void TimedEvents::startClock() {

		start = chrono::steady_clock::now();
	}

	//stops the clock
	void TimedEvents::stopClock() {

		end = chrono::steady_clock::now();
	}

	// set values of number of records created
	void TimedEvents::recordEvent(const char* rec) {

		const char* timez = "nanoseconds";

		if (curRecord < MAX_RECORD) {
			record[curRecord].name = rec;
			record[curRecord].time = timez;
			auto storeTime = record[curRecord].timeDuration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
			curRecord++;
			

		}

	}

	std::ostream& operator<< (std::ostream& os, const TimedEvents& event) {

		os << "--------------------------\n";
		os << "Execution Times:\n";
		os << "--------------------------\n";
		for (auto i = 0; i < event.curRecord; i++)
			os << std::setw(20) << std::left
			<< event.record[i].name << ' ' << std::setw(12) << std::right
			<< event.record[i].timeDuration.count() << ' '
			<< event.record[i].time << '\n';
		os << "--------------------------\n";
		return os;
	 }



}

