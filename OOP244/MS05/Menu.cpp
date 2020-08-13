/***********************************************************************/
// Date:	November 14, 2019
// Author:	Nima Shahi
// Student #: 106129190
// Purpose: Final Project: Milestone 1
//***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include "Menu.h"
#include <cstring>
using namespace std;
namespace sdds {

	MenuItem::MenuItem() {
		m_description = nullptr;
	}

	MenuItem::MenuItem(const char* selection) {
		m_description = new char[strlen(selection) + 1];
		strcpy(m_description, selection);
	}

	MenuItem::~MenuItem() {
		delete[] m_description;
	}

	MenuItem::operator bool const() {
		return(m_description != nullptr && m_description[0] != '\0');
	}

	MenuItem::operator const char*() const{
		return m_description;
	}


	ostream& MenuItem::display(ostream & os)const {
		os << m_description << endl;
		return os;
	}

	Menu::Menu() :title(), item{ nullptr } {
		num_pointers = 0;
	}

	Menu::Menu(const char* menu) : title(menu), item{ nullptr }{
		num_pointers = 0;
	}

	Menu::~Menu() {
		for (int i = 0; i < num_pointers; i++) {
			delete item[i];
		}
	}

	Menu::operator bool const() {
		return(item[0] != nullptr);
	}

	Menu::operator unsigned int() {
		return num_pointers;
	}

	int Menu::operator~() {
		return getSelection();
	}

	const char* Menu::operator[](int number)const {
		while (number > num_pointers) {
			number -= num_pointers;
		}
		return item[number]->m_description;
	}


	Menu& Menu::operator<<(const char* number) {
		if ((unsigned)num_pointers < MAX_MENU_ITEMS) {
			num_pointers++;
			item[num_pointers - 1] = new MenuItem(number);
		}

		return *this;
	}


	unsigned int Menu::getSelection() {
		int number;
		int flag = 0;
		menuItems();

		do {
			cin >> number;
			if (cin.fail() || number > num_pointers || number < 0) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Invalid Selection, try again: ";
			}
			else {
				flag = 1;
				cin.ignore(1000, '\n');
			}
		} while (flag == 0);

		return number;
	}

	ostream& Menu::menuTitle(ostream & os)const {
		if (title.m_description != nullptr) {
			os << title.m_description;
		}
		return os;
	}


	ostream& Menu::menuItems(ostream & os)const {
		if (title.m_description != nullptr) {
			os << title.m_description << ':' << endl;
		}
		os.setf(ios::right);
		for (int i = 0; i < num_pointers; i++) {
			os.width(1);
			os << " " << i + 1 << "- "; item[i]->display();
		}
		os << " 0- Exit" << endl << "> ";

		return os;
	}


	ostream& operator<<(ostream & os, const Menu & menu) {
		menu.menuTitle(os);
		return os;
	}
}
