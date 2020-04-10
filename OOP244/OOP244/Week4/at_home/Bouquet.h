/***********************************************************************
// OOP244 Workshop 4: Constructors, Destructors, Current Object AT HOME
// File Bouquet.h
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
#ifndef SDDS_BOUQUET_H
#define SDDS_BOUQUET_H

#include <iostream>
#include "Flower.h"
#include "utils.h"
namespace sdds {
#define MESS_MAX_LEN 25
#define MAX_FLOWERS 3
   class Bouquet {
      double b_price;
      char* b_message;
      Flower* b_flower;
      int b_flowerCount;
   public:
      Bouquet();
      Bouquet(const Flower* Flwr, int NoOfFls,const char* MsgOfBouQ = "Congratulations");
      const char* message() const;
      double price() const;
      bool isEmpty()const;
      void setEmpty();
      void setMessage(const char* prompt);
      void discardBouquet();
      void arrangeBouquet();  
      std::ostream& display() const;
      ~Bouquet(); 
   };
}
#endif // !SDDS_BOUQUET_H
