#ifndef MENU_H
#define MENU_H

#include <map>

enum MenuChoice
{
    NewGame,
    Continue,
    Exit
};

class Menu {
    public:
        Menu();
        Menu(const Menu &source);
        Menu(Menu &&source);

        Menu& operator=(const Menu &source);
        Menu& operator=(Menu &&source);
        ~Menu();
        
        int numberOfItems;
        std::map<MenuChoice, std::string> labels;
};

#endif