/***********************************************************************
// OOP244 Workshop 9: Templates
// File CalculatorTester.cpp
// Version 1.0
// Date	2019/11/24
// Author	Hong Zhan (Michael) Huang
// Description
// Tests the Calculator template and its functions
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Michael
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include <iostream>
#include <iomanip>
#include "Calculator.h"
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

  cout << "Create an int and double calculator" << endl;
  line(64, '-') << endl;
  number(1) << endl;
  Calculator<int, 5> ical;
  Calculator<double, 5> dcal;
  ical.display(cout);
  dcal.display(cout) << endl;

  cout << "Perform add function on each calculator" << endl;
  line(64, '-') << endl;
  number(2) << endl;
  int arr1[5] = { 1, 2, 3, 4, 5 };
  ical.add(arr1, arr1);
  double arr2[5] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
  dcal.add(arr2, arr2);
  ical.display(cout);
  dcal.display(cout) << endl;

  cout << "Perform subtract function on each calculator" << endl;
  line(64, '-') << endl;
  number(3) << endl;
  int arr3[5] = { 5, 4, 3, 2, 1 };
  double arr4[5] = { 5.5, 4.4, 3.3, 2.2, 1.1 };
  ical.subtract(arr3, arr1);
  dcal.subtract(arr4, arr2);
  ical.display(cout);
  dcal.display(cout) << endl;

  cout << "Perform multiply function on each calculator" << endl;
  line(64, '-') << endl;
  number(4) << endl;
  ical.multiply(arr1, arr1);
  dcal.multiply(arr2, arr2);
  ical.display(cout);
  dcal.display(cout) << endl;

  cout << "Perform divide function on each calculator" << endl;
  line(64, '-') << endl;
  number(5) << endl;
  ical.divide(arr1, arr1);
  dcal.divide(arr2, arr2);
  ical.display(cout);
  dcal.display(cout) << endl;

  cout << "Perform operators +=, -=, *=, /= on each calculator" << endl;
  line(64, '-') << endl;
  number(6) << endl;
  cout << "ical's initial state: "; ical.display(cout);
  cout << "ical += 1,2,3,4,5: ";
  ical += arr1;
  ical.display(cout);
  cout << "ical -= 1,2,3,4,5: ";
  ical -= arr1;
  ical.display(cout);
  cout << "ical *= 1,2,3,4,5: ";
  ical *= arr1;
  ical.display(cout);
  cout << "ical /= 1,2,3,4,5: ";
  ical /= arr1;
  ical.display(cout) << endl;

  cout << "dcal's initial state: "; dcal.display(cout);
  cout << "dcal += 1.1,2.2,3.3,4.4,5.5: ";
  cout << fixed << setprecision(2); 
  dcal += arr2;
  dcal.display(cout);
  cout << "dcal -= 5.5,4.4,3.3,2.2,1.1: ";
  dcal -= arr4;
  dcal.display(cout);
  cout << "dcal *= 1.1,2.2,3.3,4.4,5.5: ";
  dcal *= arr2;
  dcal.display(cout);
  cout << "dcal /= 5.5,4.4,3.3,2.2,1.1: ";
  dcal /= arr4;
  dcal.display(cout);
  return 0;
}
