#include <algorithm>

#include "movies.h"

Movies::Movies(): movies {} {}

bool Movies::add(std::string name, std::string format, int certificate, int rating, int running_time)
{
    auto it = std::find_if(movies.begin(), movies.end(), [name] (Movie movie) { return movie.get_title() == name; });
    if (it != movies.end()) {
        return false;
    }

    std::shared_ptr<Movie> movie = std::make_shared<Movie>(name, format, certificate, rating, running_time);
    movies.push_back(movie);

    return true;
}

bool Movies::remove(std::string name)
{
    auto it = std::find_if(movies.begin(), movies.end(), [name] (Movie movie) { return movie.get_title() == name; });
    if (it != movies.end()) {
        movies.erase(it);
        return true;
    }

    return false;
}

void Movies::print(std::ostream &os) const {

    for (std::shared_ptr<Movie> movie: movies) {
        os << movie;
    }
}
