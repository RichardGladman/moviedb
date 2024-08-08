#include "menu.h"

#include <iostream>
#include <cctype>
#include <algorithm>
#include <ansicodes.h>

Menu::Menu(): options {'A', 'E', 'D', 'L', 'V', 'Q'}
{

}

void Menu::display_main() const
{
    std::cout << "Welcome to the MovieDb\n";
    std::cout << "----------------------\n\n";
    std::cout << "Main Menu\n";
    std::cout << "A - Add a new Movie\n";
    std::cout << "E - Edit an existing movie\n";
    std::cout << "D - Delete an existing movie\n";
    std::cout << "L - List all movies\n";
    std::cout << "V - View an existing movie\n";
    std::cout << "Q - Quit";
}

char Menu::get_selection()
{
    char sel {};

    do {
        std::cout << "\nEnter your selection: ";
        std::cin >> sel;

        sel = std::toupper(sel);

        if (std::find(options.begin(), options.end(), sel) == options.end()) {
            std::cout << ANSICodes::RED << "Invalid selection. Please try again." << ANSICodes::RESET;
        }

    } while (std::find(options.begin(), options.end(), sel) == options.end());

    return sel;
}
