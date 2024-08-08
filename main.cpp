#include <iostream>
#include <memory>

#include "menu.h"

void handle_add_movie();
void handle_edit_movie();
void handle_delete_movie();
void handle_list_movies();
void handle_view_movie();

int main()
{
    char selection {};
    std::unique_ptr<Menu> menu = std::make_unique<Menu>();

    do {
        menu->display_main();
        selection = menu->get_selection();

        switch (selection) {
        case 'A':
            handle_add_movie();
            break;
        case 'E':
            handle_edit_movie();
            break;
        case 'D':
            handle_delete_movie();
            break;
        case 'L':
            handle_list_movies();
            break;
        case 'V':
            handle_view_movie();
            break;
        }
    } while (selection != 'Q');
    return 0;
}

void handle_add_movie()
{

}

void handle_edit_movie()
{

}

void handle_delete_movie()
{

}

void handle_list_movies()
{

}

void handle_view_movie()
{

}
