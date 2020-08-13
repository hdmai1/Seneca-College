// Pencil.cpp
#define _CRT_SECURE_NO_WARNINGS
#include "Pencil.h"
#include <string.h>
using namespace std;
namespace sdds {
   Pencil::Pencil() {
      HB_scale[0] = '\0';
      graphite = 0;
   }
   Pencil::Pencil(const char* newScale, int newGraphite) {
      if (newScale == nullptr || newScale[0] == '\0') {
         HB_scale[0] = '\0';
         graphite = 0;
      }
      else {
         strncpy(HB_scale, newScale, HB_MAX);
         HB_scale[HB_MAX] = '\0';
         if (newGraphite < 1 || newGraphite > 100)
            graphite = GRAPHITE_MAX;
         else
            graphite = newGraphite;
      }
   }
   void Pencil::write(const char* Something) {
      if (graphite > 0) {
         cout << "Writing out the following: " << Something << " with a Pencil!" << endl;
         int NoOfSpcs = 0;
         int len = strlen(Something);
         for (int i = 0; i < len; i++) {
            if (Something[i] == ' ') {
               NoOfSpcs = NoOfSpcs + 1;
            }
         }
         graphite = graphite - (NoOfSpcs * 5);
         if (graphite < 0)
            graphite = 0;
      }
      else {
         cout << "We can't write without graphite!" << endl;
      }
   }

   void Pencil::refill(int newGraphite) {
      cout << "Refilling the pencil with graphite" << endl;
      graphite += newGraphite;
      if (graphite > GRAPHITE_MAX)
         graphite = GRAPHITE_MAX;
   }
   bool Pencil::filled() const {
      return (graphite > 0);
   }

   ostream& Pencil::display(ostream& os) const {
      if (HB_scale[0] == '\0' && graphite == 0) {
         os << "This is an empty Pencil" << endl;
      }
      else {
         os << "Pencil Details" << endl;
         os << "HB Value: " << HB_scale << endl;
         os << "Graphite Remaining: " << graphite << endl;
      }
      return os;
   }
}