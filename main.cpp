#include <iostream>
#include <memory>
#include <string>
#include <ansicodes.h>
#include <limits>

#include "menu.h"
#include "movies.h"

void handle_add_movie(std::unique_ptr<Movies> &movies);
void handle_edit_movie();
void handle_delete_movie();
void handle_list_movies();
void handle_view_movie();

std::string input(std::string prompt, int min_len=0);

int main()
{
    std::unique_ptr<Movies> movies = std::make_unique<Movies>();
    char selection {};
    std::unique_ptr<Menu> menu = std::make_unique<Menu>();

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
    std::string title = input("Enter the movie title", 1);
    std::string format = input("Enter the movie format", 3);

    int certificate {};
    int rating {};
    int running_time {};

    try {
        std::string in = input("Enter the movie certificate");
        certificate = std::stoi(in);
    } catch (std::invalid_argument e) {
        std::cout << ANSICodes::RED << "Fatal Error non-numeric input for certificate" << ANSICodes::RESET << std::endl;
        return;
    }

    try {
        std::string in = input("Enter the movie rating");
        rating = std::stoi(in);
    } catch (std::invalid_argument e) {
        std::cout << ANSICodes::RED << "Fatal Error non-numeric input for rating" << ANSICodes::RESET << std::endl;
        return;
    }

    try {
        std::string in = input("Enter the movie running time in minutes");
        running_time = std::stoi(in);
    } catch (std::invalid_argument e) {
        std::cout << ANSICodes::RED << "Fatal Error non-numeric input for running time" << ANSICodes::RESET << std::endl;
        return;
    }

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

std::string input(std::string prompt, int min_len)
{
    std::string in {};

    do {
        std::cout << prompt << ": ";

        std::getline(std::cin, in);

        if (min_len > 0 && in.length() < min_len) {
            std::cout << ANSICodes::RED << "Error: Input must be at least " << min_len << " characters long" << ANSICodes::RESET << std::endl;
        }

    } while (min_len > 0 && in.length() < min_len);

    return in;
}
