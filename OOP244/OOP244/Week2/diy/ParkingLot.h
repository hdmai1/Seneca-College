/***********************************************************************
// OOP244 Workshop 2: SenePark application
// File	ParkingLot.h
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

#ifndef SDDS_PARKINGLOT_H
#define SDDS_PARKINGLOT_H
#include "ParkingSpot.h"
namespace sdds {
   struct ParkingLot {
      int NoOfPs;
      ParkingSpot* Pslot;
   };
   void setEmpty(ParkingLot& Pl);
   bool isEmpty(const ParkingLot& Pl);
   void openParking(ParkingLot& Pl, int noOfSpots);
   int parkCar(ParkingLot& Pl);
   bool returnCar(ParkingLot& Pl, int spotNo);
   void closeParking(ParkingLot& Pl);
}
#endif // !SDDS_PARKINGLOT_H
