#ifndef SDDS_PUBRECORD_H
#define SDDS_PUBRECORD_H
#include "ReadWriteable.h"
#include "Date.h"
namespace sdds {
#define SDDS_CONSOLE 0
#define SDDS_FILE 1
   class PubRecord : public ReadWriteable {
      char* m_name;
      int m_shelfno;
      int m_type;
   protected:
      void name(const char* newName);
      const char* name()const;
      void shelfNo(int value);
   public:
      virtual char recID()const = 0;
      PubRecord();
      PubRecord(const PubRecord& newPR);
      PubRecord& operator=(const PubRecord& newPR);
      PubRecord& mediaType(int newType);
      int mediaType()const;
      int shelfNo()const;
      void readShelfNo();
      bool operator==(char A)const;
      bool operator==(const char* aString)const;
      operator bool() const;
      virtual ~PubRecord();
      //ms4 additional functions:
      virtual void checkIn() = 0;
      virtual void checkOut() = 0;
   };
}
#endif // !SDDS_PUBRECORD_H
