
// Name: Luxi Liang
// Seneca Student ID: 165936188
// Seneca email: lliang44@myseneca.ca
// Date of completion: 01/28/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_SETSUM_H
#define SDDS_SETSUM_H
#include <iostream>
#include "Set.h"

namespace sdds {

	template <class T, unsigned int N, class K, class V >
	class SetSummable : public Set<T, N> {
	public:
		V accumulate(const K& key) const {
			V accumulator;
			accumulator = T::getInitialValue();
			for (unsigned int i = 0; i < this->size(); i++) {
				accumulator = (*this)[i].sum(key, accumulator);
			}
			return accumulator;

		};

	};
}
#endif
