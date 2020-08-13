// Final Project Milestone 1 
// Date Module
// File	Menu.h
// Version 1.0
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Fardad             2019/11/11		       Preliminary release
/////////////////////////////////////////////////////////////////

#ifndef SDDS_MENU_H
#define SDDS_MENU_H
#include <iostream>
namespace sdds {
#define MAX_MENU_ITEMS 20
   class Menu;
   class MenuItem {
      friend Menu;
      char* m_desc = nullptr;
      MenuItem();
      MenuItem(const char* newItem);
      operator bool() const;
      operator const char* () const;
      std::ostream& display(std::ostream& os = std::cout)const;
      ~MenuItem();
   };
   class Menu {
      MenuItem m_title;
      MenuItem* m_MenuItem[MAX_MENU_ITEMS];
      int m_MIquantity;
   public:
      Menu();
      Menu(const char* MenuTitle);
      std::ostream& getTitle(std::ostream& os = std::cout)const;
      std::ostream& displayMenu(std::ostream& os = std::cout)const;
      Menu& operator<<(const char* newItem);
      int getSelection();
      int operator~();
      operator int();
      operator bool() const;
      const char* operator[](int index)const;
      ~Menu();
   };
   std::ostream& operator<<(std::ostream& os, const Menu& menu);
}

#endif // !SDDS_MENU_H
