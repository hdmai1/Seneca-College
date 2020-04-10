/***********************************************************************
// OOP244 Workshop 4: Constructors, Destructors, Current Object AT HOME
// File Flower.h
// Version 1.0
// Date	2019/09/29
// Author	Hong Zhan (Michael) Huang
// Description
// Tests the creation, usage and destruction of the Bouquet class
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Duc Mai         October 7, 2019
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SDDS_FLOWER_H
#define SDDS_FLOWER_H
#include <iostream>
#include <cstring>
#include "utils.h"
namespace sdds {
#define NAME_MAX_LEN 25
#define COL_MAX_LEN 15
   class Flower {
      char* f_name;
      char* f_colour;
      double f_price;
   public:
      Flower();
      Flower(const char* name, const char* colour, double value);
      const char* name() const;
      const char* colour() const;
      double price() const;
      bool isEmpty()const;
      void setEmpty();
      void setName(const char* prompt);
      void setName(const char* name, int len);
      void setColour(const char* prompt);
      void setColour(const char* colour, int len);
      void setPrice(const char* prompt);
      void setPrice(double price);
      void setFlower();
      std::ostream& display() const;
      ~Flower();
   };
}
#endif // !SDDS_FLOWER_H
