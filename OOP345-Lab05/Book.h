// Name: Luxi Liang
// Seneca Student ID: 165936188
// Seneca email: lliang44@myseneca.ca
// Date of completion: 02-23-2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include <iostream>
#include <string>

namespace sdds {

	class Book {
		std::string mauthor;
		std::string mtitle;
		std::string mcountry;
		size_t myear = 0;
		double mprice;
		std::string msummary;

	public:
		Book();
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();
		void setPrice(double);
		Book(const std::string& strBook);

		friend std::ostream& operator<< (std::ostream& os, const Book& book);

	};

}

#endif

