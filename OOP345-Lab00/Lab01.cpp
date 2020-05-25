// Luxi Liang
// OOP345 Lab00
// #165936188

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include "Lab01.h"

using namespace std;

namespace sdds {

	EvenNumber::EvenNumber() {
		value = 0;
	}
	EvenNumber::EvenNumber(int num) {
		value = num;
	}

	int EvenNumber::getValue() {
		return value;
	}
	// First I create an object to store my next even number value
	// Return the object by value
	EvenNumber EvenNumber::getNext() {
		EvenNumber nextEven(value + 2);
		return nextEven;
	}

	EvenNumber EvenNumber::getPrevious() {
		EvenNumber prevEven(value - 2);
		return prevEven;
	}


}
