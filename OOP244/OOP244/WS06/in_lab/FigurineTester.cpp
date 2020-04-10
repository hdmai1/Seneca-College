/***********************************************************************
// OOP244 Workshop 6: Class with Resources
// File FigurineTester.cpp
// Version 1.0
// Date	2019/10/22
// Author	Hong Zhan (Michael) Huang
// Description
// Tests the Figurine class and the ability to create new objects by
// copying
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Michael
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include <iostream>
#include "Figurine.h"
#include "Figurine.h"

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

  cout << "Figurine default constr" << endl;
  line(64, '-') << endl;
  number(1) << endl;
  Figurine f1;
  f1.display() << endl;

  cout << "Figurine 3 arg constr (invalid)" << endl;
  line(64, '-') << endl;
  number(2) << endl;
  Figurine f2("nullptr", nullptr, 12);
  Figurine f3(nullptr, "nullptr", 12);
  f2.display();
  f3.display() << endl;

  cout << "Figurine 3 arg constr (valid)" << endl;
  line(64, '-') << endl;
  number(3) << endl;
  Figurine f4("Shiva", "Lotus", 50.50);
  Figurine f5("Grimnir", "Child", -99);
  f4.display() << endl;
  f5.display() << endl;

  cout << "Figurine copy constructor (empty)" << endl;
  line(64, '-') << endl;
  number(4) << endl;
  Figurine f6 = f2;
  f6.display() << endl;

  cout << "Figurine copy constructor (non-empty)" << endl;
  line(64, '-') << endl;
  number(5) << endl;
  Figurine f7("Europa", "Crane", 90.90);
  Figurine f8 = f7;
  f7.display() << endl;
  f8.display() << endl;

  cout << "Figurine change values of copy" << endl;
  line(64, '-') << endl;
  number(5) << endl;
  f8.setName("Alexiel");
  f8.setPose("Triangle");
  f8.setPrice(200.202);
  f7.display() << endl;
  f8.display() << endl;
}
