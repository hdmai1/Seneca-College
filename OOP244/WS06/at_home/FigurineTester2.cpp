/***********************************************************************
// OOP244 Workshop 6: Class with Resources - At Home
// File FigurineTester2.cpp
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

  cout << "Figurine copy empty object via CC" << endl;
  line(64, '-') << endl;
  number(2) << endl;
  Figurine f2 = f1;
  f2.display() << endl;

  cout << "Figurine copy empty object via CA" << endl;
  line(64, '-') << endl;
  number(3) << endl;
  f1 = f2;
  f1.display() << endl;

  cout << "Figurine 3-arg constr and copy via CC" << endl;
  line(64, '-') << endl;
  number(4) << endl;
  Figurine f3("Yuel", "Fox", 88.88);
  Figurine f4 = f3;
  f3.display() << endl;
  f4.display() << endl;

  cout << "Figurine copy non empty object via CA" << endl;
  line(64, '-') << endl;
  number(5) << endl;
  Figurine f5("Societte", "Ninetails", 99.99);
  f4 = f5;
  f4.display() << endl;
  f5.display() << endl;

  cout << "Figurine compare original and original" << endl;
  line(64, '-') << endl;
  number(6) << endl;
  if (f5 == f5)
    cout << "This is the real deal" << endl << endl;

  cout << "Figurine compare original and copy" << endl;
  line(64, '-') << endl;
  number(7) << endl;
  if (!(f4 == f5))
    cout << "This is very well made" << endl << endl;

  cout << "Figurine compare copy and copy" << endl;
  line(64, '-') << endl;
  number(8) << endl;
  Figurine f6 = f5;
  if (!(f5 == f6))
    cout << "It's like looking into a mirror" << endl << endl;
}
