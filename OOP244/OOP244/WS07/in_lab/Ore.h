// Ore.h
#ifndef SDDS_ORE_H
#define SDDS_ORE_H
#include <iostream>
namespace sdds {

   class Ore {
#define DEFAULT_WEIGHT 300.50
#define DEFAULT_PURITY 20
#define CLASS_LEN 30
      double weight;
      int purity;
      char classification[CLASS_LEN + 1];
   public:
      Ore();
      Ore(double new_Weight, int new_Purity, const char* new_classification = "Unknown");
      bool refine();
      std::ostream& display(std::ostream& os)const;
      std::istream& input(std::istream& is);
   };
   std::ostream& operator<<(std::ostream& os, const Ore& ore);
   std::istream& operator>>(std::istream& os, Ore& ore);
}
#endif
