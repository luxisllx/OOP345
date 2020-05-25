// Name: Luxi Liang
// Seneca Student ID: 165936188
// Seneca email: lliang44@myseneca.ca
// Date of completion: 03-11-2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_LAB07_H
#define SDDS_LAB07_H
#include <vector>
#include <list>


namespace sdds {

	struct Song {
		std::string artistz = "";
		std::string titlez = "";
		std::string albumz = "";
		double m_price { 0.0 };
		size_t yearz { 0 };
		size_t lengthz { 0 };

	};


	class SongCollection {

		std::vector<Song*> songCollect;
	public:
		SongCollection(const std::string);
		void trim(std::string&)const;
		void display(std::ostream& out) const;
		~SongCollection();
		void sort(const std::string);
		void cleanAlbum();
		bool inCollection(const std::string) const;
		std::list<Song> getSongsForArtist(const std::string ) const;
	};

	std::ostream& operator<<(std::ostream& out, const Song& theSong);
}

#endif