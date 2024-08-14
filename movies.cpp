#include <algorithm>
#include <iomanip>

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

    os << std::setw(80) << std::left << std::setfill('-') << "" << std::setfill(' ') << "\n";
    os << std::setw(35) << "Title" << std::setw(10) << std::left << "Format" << std::right
       << std::setw(12) << "Certificate" << std::setw(10) << "Rating" << std::setw(13) << "Running Time" << "\n";
    os << std::setw(80) << std::left << std::setfill('-') << "" << std::setfill(' ') << "\n";

    for (const std::shared_ptr<Movie> &movie: movies) {
        os << std::setw(35) << std::left << movie->get_title();
        os << std::setw(10) << movie->get_format();
        os << std::setw(12) << std::right << movie->get_certificate();
        os << std::setw(10) << movie->get_rating();
        os << std::setw(13) << movie->get_running_time() << "\n";
    }
}

std::vector<std::shared_ptr<Movie>> &Movies::get_movies() {
    return movies;
}
