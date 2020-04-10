// Metal.h
#ifndef SDDS_METAL_H
#define SDDS_METAL_H
#include <iostream>
#include "Ore.h"
#define DEFAULT_MOHS 2.5
#define NAME_LEN 10

namespace sdds {

   class Metal : public Ore {
      char* m_name;
      double m_mohs;
   public:
      Metal();
      Metal(double weight, int purity, const char* classification, const char* name, double mohs);
      ~Metal();
      void refine();
      std::ostream& display(std::ostream& os) const;
      std::istream& input(std::istream& is);
   };
   std::ostream& operator<<(std::ostream& os, const Metal& met);
   std::istream& operator>>(std::istream& is, Metal& met);
}

#endif