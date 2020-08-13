/***********************************************************************
// OOP244 Workshop 4: Constructors, Destructors, Current Object AT HOME
// File Bouquet.cpp
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
#include <iostream>
#include <cstring>
#include "Bouquet.h"
#include "utils.h"

using namespace std;
namespace sdds {
   Bouquet::Bouquet() {
      b_price = 0;
      b_message = nullptr;
      b_flower = nullptr;
      b_flowerCount = -1;
   }
   Bouquet::Bouquet(const Flower* Flwr, int NoOfFlwrs,const char* MsgOfBouQ) {
      b_price = 0;
      if (Flwr != nullptr) {
         if (NoOfFlwrs <= MAX_FLOWERS) {
            b_flowerCount = NoOfFlwrs;
         }
         else if (NoOfFlwrs > MAX_FLOWERS)
            b_flowerCount = MAX_FLOWERS;

         b_flower = new Flower[b_flowerCount];
         for (int i = 0; i < b_flowerCount; i++) {
            b_flower[i].setName(Flwr[i].name(), NAME_MAX_LEN);
            b_flower[i].setColour(Flwr[i].colour(), COL_MAX_LEN); 
            b_flower[i].setPrice(Flwr[i].price());
            b_price = b_price + b_flower[i].price();
         }
      }
      else if (Flwr == nullptr) {
         setEmpty();
      }
      
      int size = strlen(MsgOfBouQ) + 1;
      b_message = new char[size];
      strcpy(b_message, MsgOfBouQ);
   }
   const char* Bouquet::message() const {
      return b_message;
   }

   double Bouquet::price()const {
      return b_price;
   }

   bool Bouquet::isEmpty()const {
      bool ok = false;
      if (b_flower == nullptr) {
         ok = true;
      }
      return ok;
   }

   void Bouquet::setEmpty() {
      b_price = 0;
      b_flowerCount = 0;
      b_message = nullptr;
      b_flower = nullptr;
   }
   void Bouquet::setMessage(const char* prompt) {
      cout << prompt;
      char msgs[MESS_MAX_LEN + 1];
      read(msgs, 30, "A bouquets's message (non-empty) is limited to 30 characters... Try again: ");
      int size = strlen(msgs) + 1;
      b_message = new char[size];
      strcpy(b_message, msgs);
   }
   void Bouquet::discardBouquet() {
      cout << "Discarding the current bouquet..." << endl;
      delete[] b_flower;
      delete[] b_message;
      setEmpty();
   }
   void Bouquet::arrangeBouquet() {
      char opt;
      cout << "Arranging a new bouquet..." << endl;
      if (!isEmpty()) {
         cout << "This bouquet has an arrangement currently, discard it? (Y/N): ";
         cin >> opt;
         while (opt != 'y' && opt != 'Y' && opt != 'n' && opt != 'N') {
            cout << "The decision is either Y or N... Try again: ";
            cin >> opt;
            cin.clear();
            cin.ignore(1000, '\n');
         }
         if (opt == 'Y' || opt == 'y') {
            discardBouquet();
         }
         else if (opt == 'N' || opt == 'n')
            cout << "No new arrangement performed..." << endl;
      }

      if (isEmpty() || opt == 'y' || opt == 'Y') {
         cout << "Enter the number of flowers in this bouquet (Valid: 1-3)... : ";
         read(b_flowerCount, 1, 3, "The valid range is 1-3... Try again: ");

         b_flower = new Flower[b_flowerCount];
         for (int i = 0; i < b_flowerCount; i++) {
            b_flower[i].setFlower();
            b_price += b_flower[i].price();
            cin.clear();
         }
         cout << "A bouquet has been arranged..." << endl;

         setMessage("Enter a message to send with the bouquet...: ");
      }
   }

   ostream& Bouquet::display() const {
      if (isEmpty()) {
         cout << "This is an empty bouquet..." << endl;
      }
      else {
         cout << "This bouquet worth ";
         cout.setf(ios::fixed);
         cout.precision(2);
         cout << b_price;
         cout << " has the following flowers..." << endl;
         for (int i = 0; i < b_flowerCount; i++) {
            b_flower[i].display();
         }
         cout << "with a message of: " << b_message << endl;
      }
      return cout;
   }
   Bouquet::~Bouquet() {
      if (isEmpty()) {
         cout << "An unknown bouquet has departed..." << endl;
      }
      else {
         cout << "A bouquet has departed with the following flowers..." << endl;
      }
      delete[] b_flower;
      delete[] b_message;
   }
}