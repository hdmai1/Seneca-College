#ifndef SDDS_MAGAZINE_H
#define SDDS_MAGAZINE_H
#include "PubRecord.h"
namespace sdds {
   class Magazine : public PubRecord {
      int m_volume;
      int m_iNo;
   public:
      Magazine();
      Magazine(const Magazine& RO);
      char recID()const;
      void checkIn();
      void checkOut();
      std::istream& read(std::istream& is = std::cin);
      std::ostream& write(std::ostream& os = std::cout)const;
   };
}
#endif // !SDDS_MAGAZINE_H
