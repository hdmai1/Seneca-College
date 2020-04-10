// WriteInstrument.h
#ifndef SDDS_WRITEINSTRUMENT_H
#define SDDS_WRITEINSTRUMENT_H
#include <iostream>
namespace sdds {
   class WriteInstrument {
   public:
      virtual ~WriteInstrument() {};
      //pure virtual members:
      virtual void write(const char*) = 0;
      virtual void refill(int) = 0;
      virtual bool filled()const = 0;
      virtual std::ostream& display(std::ostream& os) const = 0;
   };
}

#endif