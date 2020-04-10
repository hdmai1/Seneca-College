/***********************************************************************
// OOP244 Workshop 1 DIY: Compiling modular source code
// File	PhoneApp.cpp
// Version 1.1
// Date	2019/09/02
// Author	Fardad Soleimanloo
// Description
// This provides some source code in a single file to break
// into modules and compile together
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Huu Duc Mai     2019/09/16     DIY submission.
//                             
/////////////////////////////////////////////////////////////////
***********************************************************************/

//PhoneApp.cpp contains the main function.
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include "Contact.h"
#include "Tools.h"
#include "PhoneDir.h"
using namespace sdds;
using namespace std;


int main() {
   phoneDir("SDDS Phone Directory", "phones.txt");
   return 0;
}
