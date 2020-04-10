// Pen.h
#ifndef SDDS_PEN_H
#define SDDS_PEN_H
#include "WriteInstrument.h"
namespace sdds {
#define INK_MAX 50
   class Pen : public WriteInstrument {
      char* style;
      int ink;
   public:
      Pen();
      Pen(const char* newStyle, int newInk);
      ~Pen();
      void write(const char*);
      void refill(int);
      bool filled() const;
      std::ostream& display(std::ostream& os) const;

   };
}
#endif // !SDDS_PEN_H
