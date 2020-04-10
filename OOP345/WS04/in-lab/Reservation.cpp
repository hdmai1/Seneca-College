#include "Reservation.h"
#include <string>
#include <algorithm>
#include <iomanip>
namespace sdds {
   Reservation::Reservation() {
      m_id = "";
      m_name = "";
      m_email = "";
      m_NoOfPpl = -1;
      m_date = -1;
      m_hour = -1;
   }
   Reservation::Reservation(const std::string& res) {
      //remove all spaces and assign parameter to a temporary string
      std::string temp = res;
      temp.erase(std::remove(temp.begin(), temp.end(), ' '), temp.end());

      //extract string to variables

      //get id
      std::size_t n;
      n = temp.find(":");
      m_id = temp.substr(0, n);
      temp.erase(0, n + 1);

      //get name
      n = temp.find(",");
      m_name = temp.substr(0, n);
      temp.erase(0, n + 1);

      //get email:
      n = temp.find(",");
      m_email = temp.substr(0, n);
      temp.erase(0, n + 1);

      //get NoOfPpl:
      n = temp.find(",");
      m_NoOfPpl = std::stoi(temp.substr(0, n));
      temp.erase(0, n + 1);

      //get day:
      n = temp.find(",");
      m_date = std::stoi(temp.substr(0, n));
      temp.erase(0, n + 1);

      //get hour:
      n = temp.find(",");
      m_hour = std::stoi(temp.substr(0, n));
      temp.erase(0, n + 1);
   }

   std::string Reservation::getID()const {
      return m_id;
   }
   std::string Reservation::getName()const {
      return m_name;
   };
   std::string Reservation::getEmail()const {
      return m_email;
   };
   int Reservation::getPpl()const {
      return m_NoOfPpl;
   };
   int Reservation::getDate()const {
      return m_date;
   };
   int Reservation::getHour()const {
      return m_hour;
   }
   std::ostream& display(std::ostream& os, Reservation& RO) {
       os << "Reservation " << RO.getID() << ": ";
       os.width(10);
       os << std::right;
       os << RO.getName();
       std::string temp = "  <" + RO.getEmail() + ">";
       os << std::setw(26) << std::left << temp;
       return os;
   }
   std::ostream& operator<<(std::ostream& os, Reservation& RO) {
      if (RO.getHour() >= 6 && RO.getHour() <= 9) {
         display(os, RO);
         os << "Breakfast on day " << RO.getDate() << " @ " << RO.getHour() << ":00 for " << RO.getPpl() << " people.";
         os << std::endl;
      }
      else if (RO.getHour() >= 11 && RO.getHour() <= 15) {
          display(os, RO);
         os << "Lunch on day " << RO.getDate() << " @ " << RO.getHour() << ":00 for " << RO.getPpl() << " people.";
         os << std::endl;
      }
      else if (RO.getHour() >= 17 && RO.getHour() <= 21) {
          display(os, RO);
         os << "Dinner on day " << RO.getDate() << " @ " << RO.getHour() << ":00 for " << RO.getPpl() << " people.";
         os << std::endl;
      }
      else {
          display(os, RO);
         os << "Drinks on day " << RO.getDate() << " @ " << RO.getHour() << ":00 for " << RO.getPpl() << " people.";
         os << std::endl;
      }
      return os;
   }
}