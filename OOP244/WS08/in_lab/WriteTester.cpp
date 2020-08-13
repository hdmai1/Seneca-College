/***********************************************************************
// OOP244 Workshop 8: Virtual Functions
// File WriteTester.cpp
// Version 1.0
// Date	2019/11/11
// Author	Hong Zhan (Michael) Huang
// Description
// Tests the WriteInstrument and its derived classes via virtual functions
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Michael
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include <iostream>
#include "Pen.h"
#include "Pen.h"
#include "Pencil.h"
#include "Pencil.h"

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

  cout << "Pencil & Pen default constr" << endl;
  line(64, '-') << endl;
  number(1) << endl;
  Pencil pe1;
  Pen pp1;
  pe1.display(cout) << endl;
  pp1.display(cout) << endl;
  
  cout << "Pencil & Pen 2 arg constr invalid" << endl;
  line(64, '-') << endl;
  number(2) << endl;
  Pencil pe2("HB", -15);
  Pen pp2("Fountain", -12);
  pe2.display(cout) << endl;
  pp2.display(cout) << endl;

  cout << "Use WriteInstrument pointers to hold Pencils and Pens" << endl;
  line(64, '-') << endl;
  number(3) << endl;
  WriteInstrument* writers[3];
  writers[0] = new Pencil("9A", 15);
  writers[1] = new Pen("Feather", 14);
  writers[2] = new Pencil("2B", 50);

  for (int i = 0; i < 3; ++i)
    writers[i]->display(cout) << endl;

  cout << "Use each Writing Instrument to write some text" << endl;
  line(64, '-') << endl;
  number(4) << endl;
  string strs[3] = { "Still my heart is blazing", "I am a cat", "A I U E O" };
  for (int i = 0; i < 3; ++i) {
    writers[i]->write(strs[i].c_str()); cout << endl;
    writers[i]->display(cout) << endl;
  }

  cout << "Write with an empty Pencil & Pen" << endl;
  line(64, '-') << endl;
  number(5) << endl;
  writers[0]->write("Get em to Rock, get em to Burst!"); cout << endl;
  writers[1]->write("Grasp the Truth! Hold it High!"); cout << endl;

  cout << "Refill an empty Pencil" << endl;
  line(64, '-') << endl;
  number(6) << endl;
  writers[0]->refill(150);
  writers[0]->display(cout);

  // Clean up memory
  for (int i = 0; i < 3; ++i)
    delete writers[i];
}