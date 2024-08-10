#ifndef INPUT_H
#define INPUT_H

#include <string>

class Input
{
public:
    static std::string get_text(std::string prompt, int max_len = 0);
    static int get_number(std::string prompt);
};

#endif // INPUT_H
