/***********************************************************************
// OOP244 Workshop 1: Compiling modular source code
// File	tools.h
// Version 1.0
// Date	2019/09/02
// Author	Fardad Soleimanloo
// Description
// This provides some source code in a single file to break
// into modules and compile together
//
// Revision History
// -----------------------------------------------------------
// Name   Huu Duc Mai         Date  September 09-2019          Reason
// Fardad
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SDDS_TOOLS_H__
#define SDDS_TOOLS_H__
#include <iostream>

namespace sdds {
   // Draws a line and adds a label if provided
   void line(int n, const char* label = nullptr);
   // Performs a fool-proof integer entry
   int getInt(int min, int max);
   // moves the cursor backwards
   void goBack(int n);
   // displays the user interface menu
   int menu(int noOfSamples);
}
#endif