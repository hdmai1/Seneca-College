/***********************************************************************
// OOP244 Workshop 7: Dervied Classes & Custom I/O Operators
// File MetalTester.cpp
// Version 1.0
// Date	2019/10/23
// Author	Hong Zhan (Michael) Huang
// Description
// Tests the Metal class and its use of custom I/O operators
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Michael
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include <iostream>
#include "Metal.h"
#include "Metal.h"

using namespace std;
using namespace sdds;

ostream& line(int len, char ch) {
  for (int i = 0; i < len; i++, cout << ch);
  return cout;
}
ostream& number(int num) {
  cout << num;
  for (int i = 0; i < 9; i++) {
    cout << " - " << num;
  }
  return cout;
}

int main() {

  cout << "Metal default constr" << endl;
  line(64, '-') << endl;
  number(1) << endl;
  Metal m1;
  m1.display(cout) << endl;

  cout << "Metal 5 arg constr invalid args" << endl;
  line(64, '-') << endl;
  number(2) << endl;
  Metal m2(100, 200, "Stuff", nullptr, 0);
  Metal m3(100, 200, "Stuff", "", 0);
  m2.display(cout);
  m3.display(cout) << endl;

  cout << "Metal 5 arg constr valid args (default vals, vals as is)" << endl;
  line(64, '-') << endl;
  number(3) << endl;
  Metal m4(1300, 200, "Volcanic", "Gold", -1);
  Metal m5(1000, 10, "Magmatic", "Silver", 4.3);
  m4.display(cout) << endl;
  m5.display(cout) << endl;

  cout << "Metal refinement w/ custom output operator" << endl;
  line(64, '-') << endl;
  number(4) << endl;
  m5.refine();
  m5.refine();
  cout << m5 << endl;

  cout << "Metal empty -> custom input operator" << endl;
  line(64, '-') << endl;
  number(5) << endl;
  cin >> m1;
  cout << endl << m1 << endl;

  cout << "Metal non-empty -> custom input operator" << endl;
  line(64, '-') << endl;
  number(7) << endl;
  cin >> m4;
  cout << endl << m4 << endl;

  return 0;
}