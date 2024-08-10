#include <iostream>
#include <memory>
#include <string>
#include <ansicodes.h>
#include <limits>

#include "input.h"
#include "menu.h"
#include "movies.h"

void handle_add_movie(std::unique_ptr<Movies> &movies);
void handle_edit_movie();
void handle_delete_movie();
void handle_list_movies();
void handle_view_movie();

int main()
{
    std::unique_ptr<Movies> movies = std::make_unique<Movies>();
    std::unique_ptr<Menu> menu = std::make_unique<Menu>();
    char selection {};

    do {
        menu->display_main();
        selection = menu->get_selection();

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cin.clear();

        switch (selection) {
        case 'A':
            handle_add_movie(movies);
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

void handle_add_movie(std::unique_ptr<Movies> &movies)
{
    std::string title = Input::get_text("Enter the movie title", 1);
    std::string format = Input::get_text("Enter the movie format", 3);

    int certificate = Input::get_number("Enter the movie certificate");
    int rating = Input::get_number("Enter the movie rating");
    int running_time = Input::get_number("Enter the movie running time in minutes");

    movies->add(title, format, certificate, rating, running_time);
    std::cout << ANSICodes::GREEN << "Movie " << title << " successfully added to moviedb" << ANSICodes::RESET << std::endl << std::endl;
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
