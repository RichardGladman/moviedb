#ifndef MOVIES_H
#define MOVIES_H

#include <vector>
#include <string>
#include <memory>
#include "movie.h"
#include "printable.h"

class Movies: public Printable
{
public:
    Movies();

    std::shared_ptr<Movie> find(std::string title);
    bool add(std::string name, std::string format, int certificate, int rating, int running_time);
    bool remove(std::string name);
    virtual void print(std::ostream &os) const override;

private:
    std::vector<std::shared_ptr<Movie>> movies;
};

#endif // MOVIES_H
