#include "filehandler.h"

#include <string>
#include <fstream>
#include <filesystem>

#include <ansicodes.h>

bool FileHandler::save(const std::unique_ptr<Movies> &movies)
{
    const char *env_home = std::getenv("HOME");
    const std::string home = env_home != NULL ? env_home : "/tmp";
    const std::string path = home + "/Documents/moviedb/";
    const std::string filename = path + "db.txt";

    if (!std::filesystem::exists(path)) {
        std::filesystem::create_directories(path);
    }

    std::ofstream file {filename};
    if (!file.is_open()) {
        std::cout << ANSICodes::RED << "Failed to open " << path << " for writing" << ANSICodes::RESET << std::endl;
        return false;
    }

    for (const std::shared_ptr<Movie> &movie: movies->get_movies()) {
        file << movie->get_title() << "|" << movie->get_format() << "|" << movie->get_certificate() << "|"
             << movie->get_rating() << "|" << movie->get_running_time() << std::endl;
    }

    file.close();

    return true;
}
