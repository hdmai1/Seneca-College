#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "PubRecord.h"
#include "Utils.h"
using namespace std;
namespace sdds {
   void PubRecord::name(const char* newName)
   {
      if (newName != nullptr) {
         if (m_name != nullptr)
            delete[] m_name;
         m_name = new char[strlen(newName) + 1];
         strcpy(m_name, newName);
      }
      else {
         m_name = nullptr;
         m_shelfno = 0;
         m_type = -1;
      }
   }
   const char* PubRecord::name()const {
      return m_name;
   }

   void PubRecord::shelfNo(int value)
   {
      m_shelfno = value;
   }

   PubRecord::PubRecord() : m_name(nullptr), m_shelfno(0), m_type(SDDS_CONSOLE)
   {

   }
   PubRecord::PubRecord(const PubRecord& newPR) : m_name(nullptr), m_shelfno(0), m_type(SDDS_CONSOLE)
   {
      if (newPR.m_name != nullptr) {
         m_shelfno = newPR.m_shelfno;
         m_type = newPR.m_type;
         if (m_name != nullptr)
            delete[] m_name;
         m_name = new char[strlen(newPR.m_name) + 1];
         strcpy(m_name, newPR.m_name);
      }
      else {
         m_name = nullptr;
         m_shelfno = 0;
         m_type = 0;
      }
   }
   PubRecord& PubRecord::operator=(const PubRecord& newPR)
   {
      if (*this != newPR) {
         m_shelfno = newPR.m_shelfno;
         m_type = newPR.m_type;
         if (m_name != nullptr) {
            delete[] m_name;
         }
         m_name = new char[strlen(newPR.m_name) + 1];
         strcpy(m_name, newPR.m_name);
      }
      return *this;
   }
   PubRecord& PubRecord::mediaType(int newType)
   {
      m_type = newType;
      return *this;
   }
   int PubRecord::mediaType()const
   {
      return m_type;
   }
   int PubRecord::shelfNo() const
   {
      return m_shelfno;
   }
   void PubRecord::readShelfNo()
   {
      sdds::read(m_shelfno, 99, 1000, "Invalid Shelf Number, Enter again: ");
   }
   bool PubRecord::operator==(char A)const
   {
      bool ok = true;
      if (A != recID())
         ok = false;
      return ok;
   }
   bool PubRecord::operator==(const char* aString) const
   {
      bool ok = true;
      if (strstr(aString, m_name) != nullptr)
         ok = false;
      return ok;
   }
   PubRecord::operator bool() const
   {
      bool ok;
      if (m_name != nullptr)
         ok = true;
      else ok = false;
      return ok;
   }
   PubRecord::~PubRecord()
   {
      delete[] m_name;
   }
}
