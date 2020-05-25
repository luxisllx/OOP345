
// Name: Luxi Liang
// Seneca Student ID: 165936188
// Seneca email: lliang44@myseneca.ca
// Date of completion: 
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_STATION_H
#define SDDS_STATION_H
#include <iostream>



	class Station {
		int m_id;
		std::string m_name;
		std::string m_desc;
		int m_serial;
		int m_current;
		static size_t m_widthField;
		static int id_generator;
	public:
		Station(const std::string&);
		const std::string& getItemName() const;
		unsigned int getNextSerialNumber();
		unsigned int getQuantity() const;
		void updateQuantity();
		void display(std::ostream& os, bool full) const;


	};






#endif