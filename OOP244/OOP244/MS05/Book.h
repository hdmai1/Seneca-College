#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include "PubRecord.h"
#include <iostream>
namespace sdds {
   class Book : public PubRecord {
      long long int m_ISBN{};
      int m_B_ID{};
      Date m_due{};
   public:
      Book() : m_ISBN(0), m_B_ID(0), m_due() {};
      Book(const Book& nBook);
      Book& operator=(const Book& nBook);
      //member func:
      char recID()const;
      int memberID()const;
      void checkIn();
      void checkOut();
      std::istream& read(std::istream& is = std::cin);
      std::ostream& write(std::ostream& os = std::cout)const;
   };
}
#endif // !SDDS_BOOK_H
