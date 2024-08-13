#include <algorithm>

#include "movies.h"

Movies::Movies(): movies {} {}

std::shared_ptr<Movie> Movies::find(std::string title)
{
    std::transform(title.begin(), title.end(), title.begin(), [] (unsigned char c) { return std::tolower(c); });
    auto it = std::find_if(movies.begin(), movies.end(), [title] (std::shared_ptr<Movie> movie) {
        std::string movie_title = movie->get_title();
        std::transform(movie_title.begin(), movie_title.end(), movie_title.begin(), [] (unsigned char c) { return std::tolower(c); });
        return movie_title == title;
    });

    if (it == movies.end()) {
        return nullptr;
    }

    return *it;
}

bool Movies::add(std::string title, std::string format, std::string certificate, int rating, int running_time)
{
    std::string target = title;
    std::transform(target.begin(), target.end(), target.begin(), [] (unsigned char c) { return std::tolower(c); });
    auto it = std::find_if(movies.begin(), movies.end(), [target] (std::shared_ptr<Movie> movie) {
        std::string movie_title = movie->get_title();
        std::transform(movie_title.begin(), movie_title.end(), movie_title.begin(), [] (unsigned char c) { return std::tolower(c); });
        return movie_title == target;
    });

    if (it != movies.end()) {
        return false;
    }

    std::shared_ptr<Movie> movie = std::make_shared<Movie>(title, format, certificate, rating, running_time);
    movies.push_back(movie);

    return true;
}

bool Movies::remove(std::string title)
{
    std::string target = title;
    std::transform(target.begin(), target.end(), target.begin(), [] (unsigned char c) { return std::tolower(c); });
    auto it = std::find_if(movies.begin(), movies.end(), [target] (std::shared_ptr<Movie> movie) {
        std::string movie_title = movie->get_title();
        std::transform(movie_title.begin(), movie_title.end(), movie_title.begin(), [] (unsigned char c) { return std::tolower(c); });
        return movie_title == target;
    });

    if (it != movies.end()) {
        movies.erase(it);
        return true;
    }

    return false;
}

void Movies::print(std::ostream &os) const {

    for (const std::shared_ptr<Movie> &movie: movies) {
        os << *movie << "\n";
    }
}

std::vector<std::shared_ptr<Movie>> &Movies::get_movies() {
    return movies;
}
