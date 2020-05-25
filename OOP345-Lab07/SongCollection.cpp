
// Name: Luxi Liang
// Seneca Student ID: 165936188
// Seneca email: lliang44@myseneca.ca
// Date of completion: 03-11-2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <iomanip> //for cout
#include <fstream> //for ifstream
#include <vector> //for vector
#include <algorithm> // for for_each
#include "SongCollection.h"

using namespace std;

namespace sdds {
	SongCollection::SongCollection(const string fileName) {


		ifstream inFile;
		inFile.open(fileName);
		if (!inFile) {
			throw  "Unable to open file";
			return;
		}
		string str;
		while (std::getline(inFile, str)) {
			Song* song = new Song;
			//song = new Song();

			song->titlez = str.substr(0, 25);
			trim(song->titlez);

			song->artistz = str.substr(25, 25);
			trim(song->artistz);

			song->albumz = str.substr(50, 25);
			trim(song->albumz);



			try
			{
				song->yearz = std::stoi(str.substr(75, 5));
			}
			catch (...) {
				song->yearz = 0;
			}


			song->lengthz = std::stoi(str.substr(80, 5));

			song->m_price = std::stod(str.substr(85, 5));

			songCollect.push_back(song);
		}

	}

	void SongCollection::trim(string& info)const {
		const std::string WHITESPACE = " \n\r\t\f\v";

		size_t start = info.find_first_not_of(WHITESPACE);
		info = (start == std::string::npos) ? "" : info.substr(start);

		size_t end = info.find_last_not_of(WHITESPACE);
		info = (end == std::string::npos) ? "" : info.substr(0, end + 1);

	}

	void SongCollection::display(std::ostream& out) const {

		size_t totalPlay = 0;

		for_each(songCollect.begin(), songCollect.end(), [&out, &totalPlay](const Song* i) {
			out << *i << endl;
			totalPlay += i->lengthz;
			});

		out << "----------------------------------------------------------------------------------------" << endl;
		out << "|";
		out.width(76);
		out << setfill(' ') << std::right << "Total Listening Time" << ": " << totalPlay / 3600 << ":" << (totalPlay - (totalPlay / 3600 * 3600)) / 60 << ":" << (totalPlay - (totalPlay / 3600 * 3600)) % 60;
		out << " |" << endl;

	}

	std::ostream& operator<<(std::ostream& out, const Song& setView) {
		size_t minz = setView.lengthz / 60;
		size_t secz = setView.lengthz % 60;

		out << "| ";
		out.width(20);
		out << setfill(' ');
		out << std::left << setView.titlez;

		out << " | ";
		out.width(15);
		out << std::left << setView.artistz;

		out << " | ";
		out.width(20);
		out << std::left << setView.albumz;

		out << " | ";
		out.width(6);
		out << std::left;
		out << setfill(' ');
		if (setView.yearz == 0)
			out << "";
		else
			out << std::right << setView.yearz;


		out << " | ";
		out << std::right << minz << ":" << setw(2) << setfill('0') << secz;

		out << " | ";
		out << std::fixed;
		out << setprecision(2) << setView.m_price;
		out << " |";

		return out;

	}

	bool compareSongTitle(Song* x, Song* y) {
		return (x->titlez < y->titlez);
	}

	bool compareSongLength(Song* x, Song* y) {
		return (x->lengthz < y->lengthz);
	}

	bool compareSongAlbum(Song* x, Song* y) {
		return (x->albumz < y->albumz);
	}


	void SongCollection::sort(const string sortCollection) {

		if (sortCollection == "title") {
			std::sort(songCollect.begin(), songCollect.end(), compareSongTitle);
		}
		else if (sortCollection == "length") {
			std::sort(songCollect.begin(), songCollect.end(), compareSongLength);
		}
		else if (sortCollection == "album") {
			std::sort(songCollect.begin(), songCollect.end(), compareSongAlbum);
		}
	}
	
	void SongCollection::cleanAlbum() {
		for_each(songCollect.begin(), songCollect.end(), [&](Song* i)
			{
				if (i->albumz == "[None]")
					i->albumz = "";
			});
	}
	
	bool SongCollection::inCollection(const string artist) const {
		
		bool sia = false;
		for_each(songCollect.begin(), songCollect.end(), [&](const Song* i) {
			if (i->artistz == artist)
				sia = true;
			});
		return sia;

	}

	std::list<Song> SongCollection::getSongsForArtist(const string artist2) const {

		list<Song> available;

		for_each(songCollect.begin(), songCollect.end(), [&](const Song* i) {
			if (i->artistz == artist2)
				available.push_back(*i);
			});
		return available;


			}
	
	SongCollection::~SongCollection() {
		for (auto i = songCollect.begin(); i != songCollect.end(); i++)
		{
			delete* i;
		}
	}

}