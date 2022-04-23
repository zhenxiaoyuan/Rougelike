#include <iostream>
#include <SDL2/SDL.h>

int
main(int argc, char **argv)
{
    std::cout << "Hello SDL2" << std::endl;
    SDL_Init(SDL_INIT_VIDEO);

    return 0;
}