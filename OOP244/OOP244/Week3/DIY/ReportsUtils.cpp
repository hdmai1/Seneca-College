#include <iostream>
#include "ReportUtils.h"
namespace sdds {
   using namespace std;
   ostream& printchar(int no, char ch) {
      for (int i = 0; i < no; i++, cout << ch);
      return cout;
   }
   
   ostream& align(int n) {
      cout.width(n);
      cout.setf(ios::left);
      cout.fill('.');
      return cout;
   } 
}


