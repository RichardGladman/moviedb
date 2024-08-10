#include <algorithm>

#include "movies.h"

Movies::Movies(): movies {} {}

std::shared_ptr<Movie> Movies::find(std::string title)
{
    auto it = std::find_if(movies.begin(), movies.end(), [title] (std::shared_ptr<Movie> movie) { return movie->get_title() == title; });

    if (it == movies.end()) {
        return nullptr;
    }

    return *it;
}

bool Movies::add(std::string name, std::string format, int certificate, int rating, int running_time)
{
    auto it = std::find_if(movies.begin(), movies.end(), [name] (std::shared_ptr<Movie> movie) { return movie->get_title() == name; });
    if (it != movies.end()) {
        return false;
    }

    std::shared_ptr<Movie> movie = std::make_shared<Movie>(name, format, certificate, rating, running_time);
    movies.push_back(movie);

    return true;
}

bool Movies::remove(std::string name)
{
    auto it = std::find_if(movies.begin(), movies.end(), [name] (std::shared_ptr<Movie> movie) { return movie->get_title() == name; });
    if (it != movies.end()) {
        movies.erase(it);
        return true;
    }

    return false;
}

void Movies::print(std::ostream &os) const {

    for (const std::shared_ptr<Movie> &movie: movies) {
        os << movie;
    }
}
