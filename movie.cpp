#include "movie.h"

#include <ansicodes.h>
#include <iomanip>

Movie::Movie(std::string title, std::string format, std::string certificate, int rating, int running_time):
    title {title}, format {format}, certificate {certificate}, rating {rating}, running_time {running_time}
{

}

Movie::Movie(std::string title): Movie {title, "", "0""", 0, 0}
{

}

Movie::Movie(): Movie {"", "", "0""", 0, 0}
{

}

std::string Movie::get_title() const
{
    return title;
}

std::string Movie::get_format() const
{
    return format;
}

std::string Movie::get_certificate() const
{
    return certificate;
}

int Movie::get_rating() const
{
    return rating;
}

int Movie::get_running_time() const
{
    return running_time;
}

void Movie::print(std::ostream &os) const
{
    const unsigned int width {15};
    os << ANSICodes::BOLD << std::setw(width) << std::left << "Title:" << ANSICodes::RESET << title << "\n";
    os << ANSICodes::BOLD << std::setw(width) << std::left << "Format:" << ANSICodes::RESET << format << "\n";
    os << ANSICodes::BOLD << std::setw(width) << std::left << "Certificate:" << ANSICodes::RESET << certificate << "\n";
    os << ANSICodes::BOLD << std::setw(width) << std::left << "Rating:" << ANSICodes::RESET << rating << "\n";
    os << ANSICodes::BOLD << std::setw(width) << std::left << "Running Time:" << ANSICodes::RESET << running_time << " min\n";
}
