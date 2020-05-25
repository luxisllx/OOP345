// Name: Luxi Liang
// Seneca Student ID: 165936188
// Seneca email: lliang44@myseneca.ca
// Date of completion: 01/28/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_SET_H
#define SDDS_SET_H
#include <iostream>

namespace sdds {

	template < class T, unsigned int N>
	class Set {
		T result[N];
		unsigned elements = 0;

	public:
		//Set() {
		//for (int i = 0; i < N; i++) {
		//result[i] = 0;
		//}
		//};

		size_t size() const {
			return elements;
		};

		const T& operator[] (size_t idx) const {

			return result[idx];
		};

		void operator+=(const T& item) {

			if (elements < N) {
				result[elements] = item;
				elements++;
			}
		};



	};



}

#endif
