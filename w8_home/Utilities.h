#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H
// Name: Luxi Liang
// Seneca Student ID: 165936188
// Seneca email: lliang44@myseneca.ca
// Date of completion: 03-25-2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
// Workshop 8 - Smart Pointers
// 2019/11 - Cornel


#include "List.h"
#include "Element.h"

namespace sdds {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price);
	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price);
}

#endif