// Luxi Liang
// OOP345 Lab00
// #165936188

#include <iostream>
#include "Lab01.h"
using namespace std;
using namespace sdds;
int main()
{
	// TESTING DEFAULT CONSTRUCTOR & GETVALUE()

	// declaring a variable
	int value;
	// creating an object to test my value
	//calling the default constructor
	EvenNumber testing;
	// setting value to equal the return value of the getValue() of the object
	value = testing.getValue(); 
	cout << value;

	// Creating a new object to hold the original value = 0
	EvenNumber testingOriginal; 
	// Creating a new object to hold the next value. value is still 0 
	EvenNumber testingNext;	
	// calling getNext(). value is now 2
	testingNext = testingOriginal.getNext();
	// printing out value 
	cout << testingNext.getValue();

	// calling getPrevious(). value is now -2 because original value is 0
	// the previous value "2" is stored in testingNext
	testingOriginal = testingOriginal.getPrevious();
	cout << testingOriginal.getValue();
	





	return 0;

}

