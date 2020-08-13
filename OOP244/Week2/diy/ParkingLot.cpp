/***********************************************************************
// OOP244 Workshop 2: SenePark application
// File	ParkingLot.cpp
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
#include "ParkingLot.h"
#include <iostream>

namespace sdds {
   
   using namespace std;

   void setEmpty(ParkingLot& Pl) {
      Pl.NoOfPs = 0;
      Pl.Pslot = nullptr;
   }

   bool isEmpty(const ParkingLot& Pl) {
         return Pl.Pslot == nullptr;
   }

   void openParking(ParkingLot& Pl, int noOfSpots) {
      Pl.NoOfPs = noOfSpots;
      Pl.Pslot = new ParkingSpot[noOfSpots];
      for (int i = 0; i < noOfSpots; i++) {
         setEmpty(Pl.Pslot[i]);
      }
   }

   int parkCar(ParkingLot& Pl) {
      int a = 0;
      for (int i = 0; i < Pl.NoOfPs; i++) {
         if (isEmpty(Pl.Pslot[i])) {
            parkCar(Pl.Pslot[i]);
            a++;
            return i;
            break;
         }
      }
         return -1;
   }

   bool returnCar(ParkingLot& Pl, int spotNo) {
      if (spotNo >= 0 && !isEmpty(Pl.Pslot[spotNo])) {
         cout << "Returning ";
         print(Pl.Pslot[(spotNo)]);
         freeSpot(Pl.Pslot[(spotNo)]);
         return true;
         }
      else
         return false;
      
   }

   void closeParking(ParkingLot& Pl) {
      for (int i = 0; i < Pl.NoOfPs; i++) {
         if (!isEmpty(Pl.Pslot[i])) {
            returnCar(Pl, i);
            setEmpty(Pl.Pslot[i]);
         }
      }
   }
}