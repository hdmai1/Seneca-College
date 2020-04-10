#define _USE_CRT_SECURE_NO_WARNINGS
#include "Magazine.h"
#include "Utils.h"
#include <iomanip>
#include <iostream>
using namespace std;
namespace sdds {
   Magazine::Magazine() : PubRecord() {
      m_volume = -1;
      m_iNo = -1;
   };
   Magazine::Magazine(const Magazine& RO): PubRecord(RO), m_volume(RO.m_volume), m_iNo(RO.m_iNo) {
   };

   char Magazine::recID()const {
      return 'M';
   };
   void Magazine::checkIn() {
      cout << "Magazines cannot be checked in or out!" << endl;
   };
   void Magazine::checkOut() {
      cout << "Magazines cannot be checked in or out!" << endl;
   };

   //read and write func 
   istream& Magazine::read(istream& is) {
      if (mediaType() == SDDS_CONSOLE) {
         cout << "Magazine Name: ";
         char* newName = new char[41];
         sdds::read(newName, 40, "Magazine name too long, Enter again: ");
         name(newName);
         delete[] newName;

         cout << "Volume: ";
         int num = 0;
         sdds::read(num, 1, 99, "Invalid Volume number, Enter again: ");
         m_volume = num;

         cout << "Issue: ";
         int iss = 0;
         sdds::read(iss, 1, 99, "Invalid Issue number, Enter again: ");
         m_iNo = iss;

         cout << "Shelf Number: ";
         readShelfNo();
      }
      /// check this func
      else if (mediaType() == SDDS_FILE) {
         char tab, magazineName[41] = "";
         unsigned int ShelfNo;
         is.get(magazineName, 41, '\t');
         is >> noskipws >> tab >> m_volume >> tab >> m_iNo >> tab >> ShelfNo >> tab;
         if (is.fail()) {
            is.clear();
            is.ignore(cin.rdbuf()->in_avail());
            cout << "input invalid\n";
         }
         else {
            name(magazineName);
            shelfNo(ShelfNo);
         }
      }
      return is;
   }

   ostream& Magazine::write(ostream& os)const {
      if (mediaType() == SDDS_CONSOLE) {
         os << left;
         os.width(41);
         os << name() << "       " << right;
         os.width(2);
         os.fill('0');
         os << m_volume << "(";
         os.width(2);
         os.fill('0');
         os << m_iNo << ")  ";
         os.fill(' ');
         os << shelfNo();
      }
      else if (mediaType() == SDDS_FILE) {
         os << recID() << name() << '\t' << m_volume << '\t' << m_iNo << '\t' << shelfNo() << endl;
      }

      return os;
   }
}