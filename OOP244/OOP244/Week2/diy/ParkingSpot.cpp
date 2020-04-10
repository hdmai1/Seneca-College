/***********************************************************************
// OOP244 Workshop 2: SenePark application
// File	ParkingSpot.cpp
// Version 1.0
// Date	2019/09/15
// Author	Fardad Soleimanloo
// Description
// This is a parking application using the ParkingLot and
// ParkingSpot modules of DIY section of the workshop.
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Huu Duc Mai     Sept 23, 2019
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include <cstring>
#include "utils.h"
#include "ParkingSpot.h"

namespace sdds {
   using namespace std;
   
   
   void setEmpty(ParkingSpot& Ps) {
      Ps.license[0] = { '\0' };
      Ps.m_model = nullptr;
   }

   bool isEmpty(const ParkingSpot& Ps) {
         return Ps.m_model == nullptr;
   }

   void freeSpot(ParkingSpot& Ps) {
      delete[] Ps.m_model;
      setEmpty(Ps);
   }

   void print(const ParkingSpot& Ps) {
      cout << Ps.m_model << ", plate number: " << Ps.license << endl;
   }

   void parkCar(ParkingSpot& Ps) {
      cout << "Make and Model: ";
      char mmodel[61];
      read(mmodel, 60, "Too long, Make and model must be shorter than 60 characters\nRedo Entry: ");
      int size = strlen(mmodel) + 1;
      Ps.m_model = new char[size];
      strcpy(Ps.m_model, mmodel);

      cout << "License Plate: ";
      read(Ps.license, 8, "Too long, License plate must be shorter than 8 characters\nRedo Entry: ");
   }
}