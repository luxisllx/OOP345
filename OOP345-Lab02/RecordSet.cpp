// Name: Luxi Liang
// Seneca Student ID: 165936188
// Seneca email: lliang44@myseneca.ca
// Date of completion: Jan 20, 2020
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "RecordSet.h"

using namespace std;

namespace sdds {

	//default constructor
	RecordSet::RecordSet() {

		str = nullptr;
		currentStr = 0;
	}

	//1-argument constructor
	RecordSet::RecordSet(const char* receive) {
		currentStr = 0;
		str = nullptr;
		std::ifstream myfile(receive);
		int numstr = 0;
		std::string tempstr;
		if (myfile) {
			while (!myfile.eof()) {
				std::getline(myfile, tempstr, ' ');
				numstr++;
			}
			str = new std::string[numstr];
			myfile.clear();
			myfile.seekg(0, ios::beg);
			numstr = 0;
			while (!myfile.eof()) {
				std::getline(myfile, str[numstr], ' ');
				numstr++;
			}
			currentStr = numstr;
		}
		
	}

	// Copy constructor
	RecordSet::RecordSet(const RecordSet& cpy) {

		//delete[] str;
		currentStr = cpy.currentStr;

		str = new std::string[cpy.currentStr];
		for (int i = 0; i < cpy.currentStr; i++) {
			str[i].assign(cpy.str[i]);
		}


	}

	// copy assignment operator
	RecordSet& RecordSet:: operator=(const RecordSet& assign) {

		if (&assign == this) {
			return *this;
		}

		else {
			delete[] str;
			str = new std::string[assign.currentStr];
			for (size_t i = 0; i < (size_t)assign.currentStr; i++)
				str[i] = assign.str[i];
			currentStr = assign.currentStr;
		}

		return *this;
	}

	//Move constructor
	RecordSet::RecordSet(RecordSet&& move): str(nullptr), currentStr(0) {
		delete[] str;
		str = move.str;
		currentStr = move.currentStr;

		move.str = nullptr;
		move.currentStr = 0;

	}

	// Move assignment operator 
	RecordSet& RecordSet::operator = (RecordSet&& moveAs) {
		
		if (this != &moveAs) {
			delete[] str;

			str = moveAs.str;
			currentStr = moveAs.currentStr;

			moveAs.str = nullptr;
			moveAs.currentStr = 0;

		}
		return *this;
	}

	

	RecordSet::~RecordSet() {
		delete[] str;
		str = nullptr;
	}

	size_t RecordSet::size() const {

		return currentStr;
	}

	std::string RecordSet::getRecord(size_t getz ) const{

		if (getz < size() && getz >= 0) {
			return str[getz];
		}

		else
			return "";




	}




}
