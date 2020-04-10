// Name: Huu Duc Mai
// Seneca Student ID: 121367189
// Seneca email: hdmai1@myseneca.ca
// Date of completion: February 09, 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#include "ConfirmationSender.h"
namespace sdds {
   ConfirmationSender::ConfirmationSender(ConfirmationSender& newCS) {
      m_res = newCS.m_res;
      m_count = newCS.m_count;
   }
   ConfirmationSender::ConfirmationSender(ConfirmationSender&& newCS) {
      m_res = newCS.m_res;
      m_count = newCS.m_count;
      newCS.m_res = nullptr;
      newCS.m_count = 0;
   }
   ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res) {
      int flag = -1;
      for (size_t i = 0; i < m_count && flag < 0; i++) {
         if (&res == m_res[i]) {
            flag = (int)i;
         }
      }
      if (flag < 0) {
         const Reservation** temp = new const Reservation * [m_count + 1];
         for (size_t i = 0; i < m_count; i++) {
            temp[i] = m_res[i];
         }
         temp[m_count] = &res;
         m_count++;
         delete[] m_res;
         m_res = temp;
      }
      return *this;

   }

   ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res) {
      int flag = -1;
      for (size_t i = 0; i < m_count && flag < 0; i++) {
         if (&res == m_res[i]) {
            flag = (int)i;
         }
      }
      size_t newFlag = (size_t)flag;
      if (flag != -1) {
         m_res[flag] = nullptr;
         const Reservation** temp = new const Reservation * [m_count - 1];
         for (size_t i = 0; i < newFlag; i++) {
            temp[i] = m_res[i];
         }
         for (size_t i = newFlag; i < m_count - 1; i++) {
            temp[i] = m_res[i + 1];
         }
         m_count--;
         delete[] m_res;
         m_res = temp;
      }
      
      return *this;
   }

   std::ostream& operator<<(std::ostream& os, const ConfirmationSender& RO) {
      os << "--------------------------\n";
      os << "Confirmations to Send\n";
      os << "--------------------------\n";
      if (RO.m_count == 0) {
         os << "The object is empty!\n";
      }
      else {
         for (size_t i = 0; i < RO.m_count; i++) {
            os << *RO.m_res[i];
         }

      }
      os << "--------------------------\n";
      return os;
   }
}