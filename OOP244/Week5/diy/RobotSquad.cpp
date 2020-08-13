///////////////////////////////////////////////////////////
// 
// Workshop 05 - DIY
//
// RobotSquad.cpp
//
// Name: Huu Duc Mai
// 
// ID: 121367189
//
// Email: hdmai1@myseneca.ca
//
///////////////////////////////////////////////////////////
#include "RobotSquad.h"
#include <cstring>
#include <string.h>
#include <iostream>
using namespace std;
namespace sdds {
   // constructor
   RobotSquad::RobotSquad(){
      strcpy(m_name, "No Name");
      m_Robots = nullptr;
      m_NoOfRobots = 0;
   }
   //constructor to set name for the squad.
   RobotSquad::RobotSquad(const char* new_Rb_name) {
      if (new_Rb_name[0] != '\0' && new_Rb_name != nullptr) {
         strcpy(m_name, new_Rb_name);
      }
   }
   //get number of robots
   int RobotSquad::NoOfRbs() const{
      return m_NoOfRobots;
   }
   const char* RobotSquad::getName() const {
      return m_name;
   }
   //get roster
   Robot* RobotSquad::getRoster() const {
       return m_Robots;
   }
   //deconstructor
   RobotSquad::~RobotSquad() {
      delete[] m_Robots;
   }

   //add robots:
   RobotSquad& RobotSquad::operator+=(Robot new_robot) {
      if (m_NoOfRobots == 0) {
         delete[] m_Robots;
         // if there is no robot, new_robot will be the first one.
         m_Robots = new Robot[m_NoOfRobots+1];
         m_Robots[m_NoOfRobots].setRobot(new_robot.getname(), new_robot.getDur(), new_robot.getArms().getForce(), new_robot.getLegs().getSpeed());
         m_NoOfRobots++;
      }
      else {
         // create temporary Robots that hold all of the current Robots' infos
         Robot hold[m_NoOfRobots];
         for (int i = 0; i < m_NoOfRobots; i++) {
            hold[i].setRobot(m_Robots[i].getname(), m_Robots[i].getDur(), m_Robots[i].getArms().getForce(), m_Robots[i].getLegs().getSpeed());
         }
         //deallocate current robots
         delete[] m_Robots;
         //allocate new m_robot with 1 extra robot.
         m_Robots = new Robot[m_NoOfRobots + 1];

         //retrieve data from temporary Robots
         for (int i = 0; i < m_NoOfRobots; i++) {
            m_Robots[i].setRobot(hold[i].getname(), hold[i].getDur(), hold[i].getArms().getForce(), hold[i].getLegs().getSpeed());
         }
         //update the newest robot + update number of robot in roster.
         m_Robots[m_NoOfRobots].setRobot(new_robot.getname(), new_robot.getDur(), new_robot.getArms().getForce(), new_robot.getLegs().getSpeed());
         m_NoOfRobots++;
         
      }
      return *this;
   }
   RobotSquad& RobotSquad::operator--() {
      // check if the squad has any roster.
      if (m_NoOfRobots == 0) 
         cout << "This squad **" << m_name << "** has no members or is uninitialized. Can't do --." << endl;
      // if a squad member reduced to 0, put the roster in safe empty state.
      else if (m_NoOfRobots == 1) {
         m_name[0] = '\0';
         strcpy(m_name, "No Name");
         m_Robots = nullptr;
         m_NoOfRobots = 0;
      }
      //remove the newest robot.
      else {
         //decrease the number of robots in roster by 1.
         m_NoOfRobots--;
         //create temporary array that holds all of the current robots' infos.
         // the newest one not included.
         Robot hold[m_NoOfRobots];
         for (int i = 0; i < m_NoOfRobots; i++) {
            hold[i].setRobot(m_Robots[i].getname(), m_Robots[i].getDur(), m_Robots[i].getArms().getForce(), m_Robots[i].getLegs().getSpeed());
         }
         //deallocate + allocate new robots array.
         delete[] m_Robots;
         m_Robots = new Robot[m_NoOfRobots];
         //retrieve data from temporary array.
         for (int i = 0; i < m_NoOfRobots; i++) {
            m_Robots[i].setRobot(hold[i].getname(), hold[i].getDur(), hold[i].getArms().getForce(), hold[i].getLegs().getSpeed());
         }
      }
      return *this;
   }
   ostream& RobotSquad::display() const {
      if (m_NoOfRobots == 0) {
         cout << "Squad **" << m_name << "** has no members" << endl;
      }
      else {
         cout << "***Squad Summary***" << endl;
         cout << "Name: "<< m_name << endl;
         cout << "Roster Count: " << m_NoOfRobots << endl;
         cout << "Roster:" << endl;
         for (int i = 0; i < m_NoOfRobots; i++) {
            m_Robots[i].display();
         }
      }
      return cout;
   }

}