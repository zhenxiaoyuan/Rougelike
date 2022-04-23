#include <iostream>
#include <SDL2/SDL.h>

#include "core/app.hpp"

int main(int argc, char **argv)
{
    try
    {
        App app;
        app.run();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}