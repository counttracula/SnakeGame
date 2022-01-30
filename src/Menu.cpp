#include <SDL.h>
#include <iostream>
#include "Menu.h"

constexpr int numberOfMenuItems = 3;

Menu::Menu() {
    numberOfItems = numberOfMenuItems;

    labels[MenuChoice::NewGame] = "New Game";
    labels[MenuChoice::Continue] = "Continue";
    labels[MenuChoice::Exit] = "Exit";
}

Menu::~Menu() {
    numberOfItems = 0;
    labels.clear();    
}

Menu::Menu(const Menu &source) {
    // deep copy
    numberOfItems = source.numberOfItems;
    for (auto &menuItem :source.labels) {
        labels[menuItem.first] = menuItem.second;
    }
}

Menu::Menu(Menu &&source):
    numberOfItems(std::move(source.numberOfItems)),
    labels(std::move(source.labels)) {}

Menu& Menu::operator=(const Menu &source) {
    numberOfItems = source.numberOfItems;
    for (auto &menuItem : source.labels) {
        labels[menuItem.first] = menuItem.second;
    }

    return *this;
}

Menu& Menu::operator=(Menu &&source) {
    if (this == &source)
        return *this;

    numberOfItems = std::move(source.numberOfItems);
    labels = std::move(source.labels);
    return *this;
}