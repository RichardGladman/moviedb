#include <iostream>
#include <memory>

#include "menu.h"

using namespace std;

int main()
{
    char selection {};
    std::unique_ptr<Menu> menu = std::make_unique<Menu>();

    do {
        menu->display_main();
        selection = menu->get_selection();

    } while (selection != 'Q');
    return 0;
}
