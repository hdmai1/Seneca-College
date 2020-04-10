// Pencil.h
#ifndef SDDS_PENCIL_H
#define SDDS_PENCIL_H
#include "WriteInstrument.h"
namespace sdds {
#define HB_MAX 2
#define GRAPHITE_MAX 100
   class Pencil : public WriteInstrument {
      char HB_scale[HB_MAX + 1];
      int graphite;
   public:
      Pencil();
      Pencil(const char* newScale, int newGraphite);
      void write(const char*);
      void refill(int);
      bool filled() const;
      std::ostream& display(std::ostream& os) const;
   };
}
#endif // !SDDS_PENCIL_H
