#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include "printable.h"

class Movie: public Printable
{
public:
    Movie(std::string title, std::string format, int certificate, int rating, int running_time);
    Movie(std::string title);
    Movie();

    std::string get_title() const;
    std::string get_format() const;
    int get_certificate() const;
    int get_rating() const;
    int get_running_time() const;

    virtual void print(std::ostream &os) const override;

private:
    std::string title;
    std::string format;
    int certificate;
    int rating;
    int running_time;
};

#endif // MOVIE_H
