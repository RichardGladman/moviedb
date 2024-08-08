#ifndef MENU_H
#define MENU_H

#include <vector>

class Menu
{
public:
    Menu();

    void display_main() const;
    char get_selection();

private:
    std::vector<char> options;
};

#endif // MENU_H
