// Menu.h
/***********************************************************************/
// Date:	November 14, 2019
// Author:	Nima Shahi
// Student #: 106129190
// Purpose: Final Project: Milestone 1
//***********************************************************************/

#ifndef SDDS_MENU_H__
#define SDDS_MENU_H__
#include <iostream>


using namespace std;

namespace sdds {


	const unsigned int MAX_MENU_ITEMS = 20;


	class MenuItem {

		char* m_description;
		friend class Menu;
		MenuItem();
		MenuItem(const char* selection);
		MenuItem(const MenuItem& a) = delete;
		MenuItem& operator=(const MenuItem& source) = delete;
		~MenuItem();
		operator bool const();
		operator const char* () const;
		std::ostream& display(std::ostream& os = std::cout)const;
	};

	class Menu {

		MenuItem title;
		MenuItem* item[MAX_MENU_ITEMS];
		int num_pointers;
	public:
		Menu();
		Menu(const char* menu);
		~Menu();
		operator bool const();
		std::ostream& menuTitle(std::ostream& os = std::cout)const;
		std::ostream& menuItems(std::ostream& os = std::cout)const;
		const char* operator[] (int index)const;
		Menu& operator<<(const char* is);
		unsigned int getSelection();
		int operator~();
		operator unsigned int();
	};
	//helper functions
	std::ostream& operator<<(std::ostream& os, const Menu& menu);


}

#endif
