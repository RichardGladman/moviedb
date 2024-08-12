#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <memory>
#include "movies.h"

class FileHandler
{
public:
    static bool save(const std::unique_ptr<Movies> &movies);
    static bool load(std::unique_ptr<Movies> &movies);
};

#endif // FILEHANDLER_H
