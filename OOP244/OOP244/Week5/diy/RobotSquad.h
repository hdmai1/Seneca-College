///////////////////////////////////////////////////////////
// 
// Workshop 05 - DIY
//
// RobotSquad.h
//
// Name: Huu Duc Mai
// 
// ID: 121367189
//
// Email: hdmai1@myseneca.ca
//
///////////////////////////////////////////////////////////
#ifndef SDDS_ROBOTSQUAD_H
#define SDDS_ROBOTSQUAD_H
#define MAX_NAME_LENGTH 10
#include "Robot.h"
#include "Parts.h"
namespace sdds {
   class RobotSquad {
      char m_name[MAX_NAME_LENGTH + 1];
      Robot* m_Robots = nullptr;
      int m_NoOfRobots = 0;
   public:
      RobotSquad();
      RobotSquad(const char* new_Rb_name);
      int NoOfRbs() const;
      const char* getName() const;
      Robot* getRoster() const;
      ~RobotSquad();
      
      RobotSquad& operator+=(Robot);
      RobotSquad& operator--();
      std::ostream& display() const;
   };
}
#endif // !SDDS_ROBOTSQUAD_H
