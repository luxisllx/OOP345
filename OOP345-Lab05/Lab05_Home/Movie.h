// Name: Luxi Liang
// Seneca Student ID: 165936188
// Seneca email: lliang44@myseneca.ca
// Date of completion: 
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H
#include <iostream>
#include <string>
//#include "SpellChecker.h"

namespace sdds {

	class Movie {
		std::string m_title;
		size_t m_year = 0;
		std::string m_description;

	public:
		Movie();
		const std::string& title() const;
		Movie(const std::string& strMovie);

		template<class T>
		void fixSpelling(T spellChecker) {
			spellChecker(m_title);
			spellChecker(m_description);
		}

		friend std::ostream& operator<< (std::ostream& os, const Movie& movie);

	};

}

#endif

