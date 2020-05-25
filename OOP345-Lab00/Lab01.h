// Luxi Liang
// OOP345 Lab00
// #165936188

#ifndef SDDS_LAB01_H
#define SDDS_LAB01_H
#include <iostream>

namespace sdds {


	class EvenNumber {

		int value;

	public:
		EvenNumber();
		EvenNumber(int);
		int getValue();
		EvenNumber getNext();
		EvenNumber getPrevious();
	};

}


#endif 
