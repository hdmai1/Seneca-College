///////////////////////////////////////////////////////////
// 
// Workshop 05 - At-home
//
// Parts.h
//
// Name: Huu Duc Mai
// 
// ID: 121367189
//
// Email: hdmai1@myseneca.ca
//
///////////////////////////////////////////////////////////
#ifndef SDDS_PARTS_H
#define SDDS_PARTS_H
#define MIN_FORCE 50
#define MIN_SPEED 25
namespace sdds {
   class Arms {
      int force;
   public:
      Arms();
      Arms(int m_force);
      int getForce() const;
      Arms& operator++();
      Arms operator++(int);
      Arms& operator+=(int);
      
   };
   class Legs {
      int speed;
   public:
      Legs();
      Legs(int new_speed);
      int getSpeed() const;
      Legs& operator-=(int);
   };
   bool operator>(const Legs&, const Legs&);
   bool operator<(const Legs&, const Legs&);
   bool operator>(const Arms&, const Arms&);
   bool operator<(const Arms&, const Arms&);
}

#endif // !SDDS_PARTS_H
