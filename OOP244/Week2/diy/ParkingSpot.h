/***********************************************************************
// OOP244 Workshop 2: SenePark application
// File	ParkingSpot.h
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
#ifndef SDDS_PARKINGSPOT_H
#define SDDS_PARKINGSPOT_H
namespace sdds {
   struct ParkingSpot {
      char license[8];
      char* m_model;
   };
   void setEmpty(ParkingSpot& Ps);
   bool isEmpty(const ParkingSpot& Ps);
   void freeSpot(ParkingSpot& Ps);
   void print(const ParkingSpot& Ps);
   void parkCar(ParkingSpot& Ps);
}
#endif // !SDDS_PARKINGSPOT_H
