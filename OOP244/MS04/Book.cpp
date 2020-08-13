#include "Book.h"
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Utils.h"
using namespace std;
namespace sdds {
   Book::Book(const Book& nBook) : PubRecord(nBook), m_ISBN(nBook.m_ISBN), m_B_ID(0), m_due(nBook.m_due){
   }
   Book& Book::operator=(const Book& nBook){
      if (*this != nBook) {
         m_ISBN = nBook.m_ISBN;
         m_B_ID = 0;
         m_due = nBook.m_due;
         PubRecord::operator=(nBook);
      }
      return *this;
   }
   char Book::recID()const {
      return 'B';
   }

   int Book::memberID()const {
      return m_B_ID;
   }

   void Book::checkIn() {
      m_B_ID = 0;
      cout << " check in!" << endl;
   };

   void Book::checkOut() {
      cout << "Enter Member id: ";
      sdds::read(m_B_ID, 9999, 100000, "Invalid member ID, Enter again: ");
      cout << "Enter return date: ";
      bool isValidDate;
      do {
         isValidDate = 1;
         cin >> m_due;
         if (m_due.errCode() != NO_ERROR) {
            cout << m_due.errCode() << "." << endl;;
            isValidDate = 0;
         }
         else {
            Date currDate;
            if (m_due < currDate) {
               cout << "Please enter a future date.";
               isValidDate = 1;
            }
            else if (m_due - currDate > 30) {
               cout << "The return date must be earlier than 30 days away from today.\n";
               isValidDate = 0;
            }
         }
      } while (!isValidDate);
   };
   std::istream& Book::read(std::istream& is) { 
      if (mediaType() == SDDS_CONSOLE) {
         m_B_ID = 0;
         cout << "Book Name: ";
         char* a = new char[40];
         sdds::read(a, 40, "Book name too long, Enter Again: ");
         name(a);
         delete[] a;

         cout << "ISBN: ";
         sdds::read(m_ISBN, 999999999999, 10000000000000, "Invalid ISBN, enter again: ");

         cout << "Shelf Number: ";
         readShelfNo();
      }
      else if (mediaType() == SDDS_FILE) {
         char tab;
         int year, month, day;
         char bName[41] = "";
         unsigned int ShelfNo;
         is.get(bName, 41, '\t');
         is >> noskipws >> tab >> m_ISBN >> tab >> ShelfNo >> tab >> m_B_ID;
         if (m_B_ID != 0) {
            is.ignore(1);
            is >> year;
            is.ignore(1);
            is >> month;
            is.ignore(1);
            is >> day;
         }
         is.ignore(1000, '\n');
         if (is.fail()) {
            is.clear();
            is.ignore(cin.rdbuf()->in_avail());
         }
         else {
            name(bName);
            shelfNo(ShelfNo);
            if (m_B_ID != 0)
               m_due = Date(year, month, day);
         }
      }
      return is;
   };
   std::ostream& Book::write(std::ostream& os)const {
      if (mediaType() == SDDS_CONSOLE) {
         os << left;
         os.fill(' ');
         os.width(41);
         os << name() << m_ISBN << "  " << shelfNo();
         if (m_B_ID != 0)
            os << " " << m_B_ID << "   " << m_due;
      }
      else if (mediaType() == SDDS_FILE) {
         os << recID() << name() << "\t" << m_ISBN << "\t" << shelfNo() << "\t" << m_B_ID;
         if (m_B_ID != 0)
            os << "\t" << m_due << endl;
         else os << endl;
      }
      return os;
   };
}