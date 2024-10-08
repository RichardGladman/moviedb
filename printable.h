#ifndef I_PRINTABLE_H
#define I_PRINTABLE_H

#pragma once

#include <iostream>

class Printable
{
    friend std::ostream &operator<<(std::ostream &os, const Printable &obj);
public:
    virtual void print(std::ostream &os) const = 0;
};

#endif
