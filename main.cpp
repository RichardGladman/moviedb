#include <iostream>
#include <memory>
#include <string>
#include <ansicodes.h>

#include "menu.h"

void handle_add_movie();
void handle_edit_movie();
void handle_delete_movie();
void handle_list_movies();
void handle_view_movie();

std::string input(std::string prompt, int min_len=0);

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

std::string input(std::string prompt, int min_len)
{
    std::string in {};

    do {
        std::cout << prompt << ": ";
        std::getline(std::cin, in);

        if (min_len > 0 && in.length() < min_len) {
            std::cout << ANSICodes::RED << "Error: Input must be at least " << min_len << " characters long" << ANSICodes::RESET << std::endl;
        }

    } while (in.length() < min_len);

    return in;
}
