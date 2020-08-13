// Figurine.h
#ifndef SDDS_FIGURINE_H
#define SDDS_FIGURINE_H
#include <iostream>
namespace sdds {
#define MAX_NAME_LEN 20
#define DEFAULT_PRICE 25.25
   class Figurine {
      char name[MAX_NAME_LEN + 1];
      char* pose;
      double price;
   public:
      Figurine();
      Figurine(const char* newName, const char* newPose, double value);
      Figurine(const Figurine& RO);
      ~Figurine();
      void setName(const char*);
      void setPose(const char*);
      void setPrice(double);
      std::ostream& display() const;
      operator bool() const;
   };
}
#endif // !SDDS_FIGURINE_H

