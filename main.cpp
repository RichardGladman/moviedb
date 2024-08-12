#include <iostream>
#include <memory>
#include <string>
#include <ansicodes.h>
#include <limits>

#include "input.h"
#include "menu.h"
#include "movies.h"
#include "filehandler.h"

void handle_add_movie(std::unique_ptr<Movies> &movies);
void handle_edit_movie(std::unique_ptr<Movies> &movies);
void handle_delete_movie(std::unique_ptr<Movies> &movies);
void handle_list_movies(std::unique_ptr<Movies> &movies);
void handle_view_movie(std::unique_ptr<Movies> &movies);
void handle_quit(std::unique_ptr<Movies> &movies);

int main()
{
    std::unique_ptr<Movies> movies = std::make_unique<Movies>();
    std::unique_ptr<Menu> menu = std::make_unique<Menu>();
    bool data_changed {false};
    char selection {};

    FileHandler::load(movies);

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
            handle_edit_movie(movies);
            break;
        case 'D':
            handle_delete_movie(movies);
            break;
        case 'L':
            handle_list_movies(movies);
            break;
        case 'V':
            handle_view_movie(movies);
            break;
        case 'Q':
            handle_quit(movies);
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

    if (movies->add(title, format, certificate, rating, running_time)) {
        std::cout << ANSICodes::GREEN << "Movie " << title << " successfully added to moviedb" << ANSICodes::RESET << std::endl << std::endl;
    } else {
        std::cout << ANSICodes::RED << "Failed to add " << title << " to moviedb" << ANSICodes::RESET << std::endl << std::endl;
    }
}

void handle_edit_movie(std::unique_ptr<Movies> &movies)
{
    std::string target = Input::get_text("Enter movie title to edit");
    std::shared_ptr<Movie> movie = movies->find(target);

    if (movie == nullptr) {
        std::cout << ANSICodes::RED << target << " not found" << ANSICodes::RESET << std::endl << std::endl;
        return;
    }

    std::string title = Input::get_text("Enter title for movie (blank to use existing)", 0, movie->get_title());
    std::string format = Input::get_text("Enter format for movie (blank to use existing)", 0, movie->get_format());

    int certificate = Input::get_number("Enter the movie certificate (blank to use existing)", movie->get_certificate());
    int rating = Input::get_number("Enter the movie rating (blank to use existing)", movie->get_rating());
    int running_time = Input::get_number("Enter the movie running time in minutes (blank to use existing)", movie->get_running_time());

    movies->remove(target);
    if (movies->add(title, format, certificate, rating, running_time)) {
        std::cout << ANSICodes::GREEN << "Movie " << title << " successfully updated in moviedb" << ANSICodes::RESET << std::endl << std::endl;
    } else {
        std::cout << ANSICodes::RED << "Failed to edit " << title << " in moviedb" << ANSICodes::RESET << std::endl << std::endl;
    }
}

void handle_delete_movie(std::unique_ptr<Movies> &movies)
{
    std::string target = Input::get_text("Enter movie title to delete");
    std::shared_ptr<Movie> movie = movies->find(target);

    if (movie == nullptr) {
        std::cout << ANSICodes::RED << target << " not found" << ANSICodes::RESET << std::endl << std::endl;
        return;
    }

    movies->remove(target);
    std::cout << ANSICodes::GREEN << "Movie " << target << " successfully removed from moviedb" << ANSICodes::RESET << std::endl << std::endl;
}

void handle_list_movies(std::unique_ptr<Movies> &movies)
{
    std::cout << *movies << std::endl;
}

void handle_view_movie(std::unique_ptr<Movies> &movies)
{
    std::string target = Input::get_text("Enter movie title to view");
    std::shared_ptr<Movie> movie = movies->find(target);

    if (movie == nullptr) {
        std::cout << ANSICodes::RED << target << " not found" << ANSICodes::RESET << std::endl << std::endl;
        return;
    }

    std::cout << *movie <<std::endl << std::endl;
}

void handle_quit(std::unique_ptr<Movies> &movies)
{
    FileHandler::save(movies);
}
