// Name: Luxi Liang
// Seneca Student ID: 165936188
// Seneca email: lliang44@myseneca.ca
// Date of completion: 01/28/2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_PAIR_H
#define SDDS_PAIR_H
#include <iostream>

namespace sdds {

	template <class K, class V>
	class Pair {

		K keyz;
		V valuez;

	public:
		//default constructor
		Pair() : keyz{ 0 }, valuez{ 0 } {

		};
		// copies parameter values into instance variables
		Pair(const K& key, const V& value) {

			keyz = key;
			valuez = value;
		};
		// return key
		const K& key() const {

			return keyz;
		};
		//return value
		const V& value() const {
			return valuez;
		};
		virtual void display(std::ostream& os) const {
			
			os << keyz << " : " << valuez << std::endl;
		};

		friend std::ostream& operator<<(std::ostream& os, const Pair<K, V>& pair) {
			pair.display(os);
			return os;

		};
	};




}
#endif

