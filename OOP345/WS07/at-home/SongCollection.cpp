// Name: Huu Duc Mai
// Seneca Student ID: 121367189	
// Seneca email: hdmai1@myseneca.ca
// Date of completion: March 20, 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#include <fstream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <numeric>

#include "SongCollection.h"
namespace sdds {
   const std::string spaces = " \n\r\t\f\v";
   std::string removeRSpaces(const std::string& str) {
      size_t index = str.find_last_not_of(spaces);
      return (index == std::string::npos) ? "" : str.substr(0, index + 1);
   };

   std::string removeLSpaces(const std::string& str) {
      size_t index = str.find_first_not_of(spaces);
      return (index == std::string::npos) ? "" : str.substr(index);
   }
   std::string removeSpaces(const std::string& str) {
      return removeRSpaces(removeLSpaces(str));
   }
   SongCollection::SongCollection(const char* filename) {
      std::ifstream file(filename);
      bool flag = true;
      if (file.fail() || std::string(filename) != "songs.txt")
         throw std::string("Invalid file name");
      else {
         while (file && flag) {
            std::string temp;
            std::getline(file, temp);
            if (temp.length() == 0) {
               flag = false;
               break;
            }
            Song newSong;

            newSong.title = removeSpaces(temp.substr(0,25));
            temp.erase(0, 25);

            newSong.artist = removeSpaces(temp.substr(0,25));
            temp.erase(0, 25);
            
            newSong.album = removeSpaces(temp.substr(0,25));
            temp.erase(0, 25);

            newSong.year = removeSpaces(temp.substr(0,5));
            temp.erase(0, 5);
            
            newSong.length = std::stoi(temp.substr(0, 5));
            temp.erase(0, 5);

            newSong.m_price = std::stod(temp.substr(0, 5));

            m_data.push_back(newSong);
         }
      }

   }
   void SongCollection::display(std::ostream& out) const {
      //for_each(m_data.begin(), m_data.end(), [&](const Song song) {out << song; });
      std::for_each(m_data.begin(), m_data.end(), [&](const Song song) {out << song << std::endl; });

      out << "----------------------------------------------------------------------------------------" << std::endl;
      out << "|";
      out.width(78);
      out << "Total Listening Time: ";

      auto formatTime = [](int seconds) {
         int mins = seconds / 60;
         int hours = mins/60;
         std::string time;
         time = std::to_string(hours);
         time += ":";
         time += int(mins % 60) < 10 ? std::string("0") + std::to_string(int(mins % 60)) : std::to_string(int(mins % 60));
         time += ":";
         time += int(seconds % 60) < 10 ? std::string("0") + std::to_string(int(seconds % 60)) : std::to_string(int(seconds % 60));
         return time;
      };

      out << formatTime(std::accumulate(m_data.begin(), m_data.end(), (int)0, [](int sum, const Song song) { return sum + song.length; }));

      out << " |" << std::endl;
   }
   void SongCollection::sort(const char* para) {
      std::sort(m_data.begin(), m_data.end(), [=](Song SongA, Song SongB) {
         if (std::string(para) == "title")
            return SongA.title < SongB.title;
         else if (std::string(para) == "album")
            return SongA.album < SongB.album;
         else if (std::string(para) == "length")
            return SongA.length < SongB.length;
         else {
            std::cout << "invalid sort's parameter" << std::endl;
            return false;
         }
         });
   }
   void SongCollection::cleanAlbum() { 
      std::for_each(m_data.begin(), m_data.end(), [](Song& SongA) {
         if (SongA.album == "[None]")
            SongA.album.clear();
         });
   };
   bool SongCollection::inCollection(const char* Artist) const {
      return std::any_of(m_data.begin(), m_data.end(), [=](const Song& SongA) {return SongA.artist == std::string(Artist); });
   };
   std::list<Song> SongCollection::getSongsForArtist(const char* Artist) const {
      auto count = std::count_if(m_data.begin(), m_data.end(), [=](Song SongA) {return SongA.artist == std::string(Artist); });
      std::list<Song> newList(count);
      std::copy_if(m_data.begin(), m_data.end(), newList.begin(), [=](Song SongA) {return SongA.artist == std::string(Artist); });
      return newList;
   }



   std::ostream& operator<<(std::ostream& out, const Song& newSong) {

      auto duration = [](int seconds) {
         std::string time;
         int minutes = seconds/60;
         time = std::to_string(int(minutes % 60));
         time += ":";
         time += int(seconds % 60) < 10 ? "0" + std::to_string(int(seconds % 60)) : std::to_string(int(seconds % 60));
         return time;
      };
       
      out << "| " << std::left << std::setw(20) << newSong.title << " | " << std::left << std::setw(15) << newSong.artist;
      out << " | " << std::left << std::setw(20) << newSong.album << " | " << std::right << std::setw(6) << newSong.year;
      out << " | " << duration(newSong.length) << " | " << std::setprecision(2) << std::fixed << newSong.m_price << " |" ;

      return out;
   }
}