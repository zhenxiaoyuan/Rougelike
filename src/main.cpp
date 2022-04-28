#include <iostream>
#include <SDL2/SDL.h>

#include "core/game.hpp"

int main(int argc, char **argv)
{
    try
    {
        Game game;
        game.run();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}