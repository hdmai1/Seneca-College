/***********************************************************************
// OOP244 Workshop 7: Dervied Classes & Custom I/O Operators
// File OreTester.cpp
// Version 1.0
// Date	2019/10/23
// Author	Hong Zhan (Michael) Huang
// Description
// Tests the Ore class and its use of custom I/O operators
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Michael
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include <iostream>
#include "Ore.h"
#include "Ore.h"

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

  cout << "Ore default constr" << endl;
  line(64, '-') << endl;
  number(1) << endl;
  Ore o1;
  o1.display(cout) << endl;

  cout << "Ore 3 arg constr invalid args" << endl;
  line(64, '-') << endl;
  number(2) << endl;
  Ore o2(100, -100);
  Ore o3(10, 600);
  Ore o4(-100, 60);
  o2.display(cout) << endl;
  o3.display(cout) << endl;
  o4.display(cout) << endl;

  cout << "Ore 3 arg constr valid" << endl;
  line(64, '-') << endl;
  number(3) << endl;
  Ore o5(3000, 10, "Sedimentary");
  o5.display(cout) << endl;

  cout << "Ore refinement w/ custom output operator" << endl;
  line(64, '-') << endl;
  number(4) << endl;
  o5.refine();
  cout << o5 << endl;

  cout << "Ore maxed refinement w/ custom output operator" << endl;
  line(64, '-') << endl;
  number(5) << endl;
  Ore o6(600, 89, "Volcanic");
  o6.refine();
  o6.refine();
  o6.refine();
  cout << o6 << endl;

  cout << "Ore empty -> custom input operator" << endl;
  line(64, '-') << endl;
  number(6) << endl;
  Ore o7;
  cin >> o7;
  cout << endl << o7 << endl;

  cout << "Ore non-empty -> custom input operator" << endl;
  line(64, '-') << endl;
  number(7) << endl;
  cin >> o7;
  cout << endl << o7;

  return 0;
}