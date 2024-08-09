#include "movie.h"

Movie::Movie(std::string title, std::string format, int certificate, int rating, int running_time):
    title {title}, format {format}, certificate {certificate}, rating {rating}, running_time {running_time}
{

}

Movie::Movie(std::string title): Movie {title, "", 0, 0, 0}
{

}

Movie::Movie(): Movie {"", "", 0, 0, 0}
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

int Movie::get_certificate() const
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

void Movie::print(std::ostream &os) const {

    os << title << ": " << format << ", " << certificate << ", " << rating << ", " << running_time << " min";
}
