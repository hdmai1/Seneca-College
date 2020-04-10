// Name: Huu Duc Mai
// Seneca Student ID: 121367189	
// Seneca email: hdmai1@myseneca.ca
// Date of completion: March 20, 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#ifndef SDDS_SONGCOLLECTION_H
#define SDDS_SONGCOLLECTION_H
#include <iostream>
#include <vector>
#include <list>
namespace sdds {
   struct Song {
      std::string artist{};
      std::string title{};
      std::string album{};
      double m_price{};
      std::string year{};
      int length{};
   };

   class SongCollection {
      std::vector<Song> m_data{};
   public:
      SongCollection(const char* name);
      void display(std::ostream& out) const;
      void sort(const char* abc);
      void cleanAlbum();
      bool inCollection(const char* Artist) const;
      std::list<Song> getSongsForArtist(const char* Artist) const;
   };
   //helper functions:
   std::string removeRSpaces(const std::string& str);
   std::string removeLSpaces(const std::string& str);
   std::ostream& operator<<(std::ostream& out, const Song& newSong);
}
#endif