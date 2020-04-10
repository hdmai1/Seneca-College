
#include "ReadWriteable.h"
using namespace std;
namespace sdds {
   istream& read(istream& is) {
      return is;
   };
   ostream& write(ostream& os) {
      return os;
   };
   istream& operator>>(std::istream& is, ReadWriteable& RO) {
      return RO.read(is);
   };
   ostream& operator<<(std::ostream& os, const ReadWriteable& RO) {
      return RO.write(os);
   };
}