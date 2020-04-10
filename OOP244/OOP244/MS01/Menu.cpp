// Final Project Milestone 1 
// Date Module
// File	Menu.cpp
// Version 1.0
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Fardad             2019/11/11		       Preliminary release
/////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string.h>
#include "Menu.h"
#include "Utils.h"

using namespace std;
namespace sdds {
   //MenuItem class's functions
   MenuItem::MenuItem() {
      m_desc = nullptr;
   }
   MenuItem::MenuItem(const char* newItem) {
      m_desc = new char[strlen(newItem) + 1];
      strcpy(m_desc, newItem);
      m_desc[strlen(newItem)] = '\0';
   }
   MenuItem::operator bool() const {
      bool rt = true;
      if (m_desc[0] == '\0' || m_desc == nullptr)
         rt = false;
      return rt;
   };
   MenuItem::operator const char* () const {
      return m_desc;
   };
   ostream& MenuItem::display(ostream& os)const {
     // if (m_desc[0] != '\0' || m_desc != nullptr)
         os << m_desc;
      /*else
         os << "";*/
      return os;
   };
   MenuItem::~MenuItem() {
      delete[] m_desc;
   }

   // FUNCTIONS BELONG TO MENU CLASS START FROM HERE
   Menu::Menu() : m_MenuItem{ nullptr } {
      //m_title = MenuItem();
      m_MIquantity = 0;
   };
   Menu::Menu(const char* MenuTitle) : m_MenuItem{ nullptr } {
      m_title = MenuTitle;
      m_MIquantity = 0;
   }
   ostream& Menu::getTitle(ostream& os)const {
      m_title.display(os);
      return os;
   }
   ostream& Menu::displayMenu(ostream& os)const {
      if (m_title) {
         m_title.display();
         os << ":" << endl;
      }
      for (int i = 1; i <= m_MIquantity; i++) {
         os << " " << i << "- ";
         m_MenuItem[i]->display(os);
         os << endl;
      }
      os << "0- Exit" << endl;
      os << "> ";
      return os;
   }
   Menu& Menu::operator<<(const char* newItem) {
      int a = 0;
      for (int i = 0; i < MAX_MENU_ITEMS && a == 0; i++) {
         if (m_MenuItem[i]->m_desc == nullptr) {
            m_MenuItem[i] = new MenuItem(newItem);
            m_MIquantity++;
            a++;
         }
      }
      return *this;
   };
   int Menu::getSelection() {
      int opt;
      displayMenu();
      opt = read(0, m_MIquantity, "Invalid Selection, try again: ");
      return opt;
   }
   int Menu::operator~() {
      return getSelection();
   }
   Menu::operator int() {
      return m_MIquantity;
   }
   Menu::operator bool() const {
      bool checkMenu = true;
      if (m_MIquantity == 0)
         checkMenu = false;
      return checkMenu;
   };
   const char* Menu::operator[](int newIndex)const {
      if (newIndex % m_MIquantity == 0)
         newIndex = newIndex - m_MIquantity;
      return m_MenuItem[newIndex]->m_desc;
   }
   ostream& operator<<(ostream& os, const Menu& menu) {
      menu.getTitle(os);
      return os;
   }
   Menu::~Menu() {
      for (int i = 0; i < m_MIquantity; i++) {
         delete[] m_MenuItem[i];
      }
   };
}