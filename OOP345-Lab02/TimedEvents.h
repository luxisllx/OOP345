// Name: Luxi Liang
// Seneca Student ID: 165936188
// Seneca email: lliang44@myseneca.ca
// Date of completion: Jan 20, 2020
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_LAB2_H
#define SDDS_LAB2_H
#include <iostream>
#include <chrono>
#include <string>



namespace sdds {

	const int MAX_RECORD = 7;

	class TimedEvents {

		int curRecord{};
		std::chrono::steady_clock::time_point start;
		std::chrono::steady_clock::time_point end;

		struct {
			std::string name{};
			std::string time{};
			std::chrono::steady_clock::duration timeDuration{};
		}record[MAX_RECORD];

	public:
		TimedEvents();
		void startClock();
		void stopClock();
		void recordEvent(const char* rec);
		friend std::ostream& operator<< (std::ostream& os, const TimedEvents& event);


	};

}

#endif



