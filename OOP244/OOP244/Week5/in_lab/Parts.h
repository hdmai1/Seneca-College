// Parts.h
#ifndef SDDS_PARTS_H
#define SDDS_PARTS_H
#define MIN_FORCE 50
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
}

#endif // !SDDS_PARTS_H
