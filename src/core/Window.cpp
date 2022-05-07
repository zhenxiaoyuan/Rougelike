#include "Window.hpp"

#include <iostream>

Window::Window()
{

}

Window::~Window()
{
    SDL_DestroyRenderer(m_pRenderer);
    SDL_DestroyWindow(m_pWindow);
}

void Window::create(
    const char *title, 
    int pos_x, 
    int pos_y, 
    int width, 
    int height, 
    Uint32 window_flags, 
    Uint32 renderer_flags)
{
    m_pWindow = SDL_CreateWindow(
        title,
        pos_x,
        pos_y,
        width,
        height,
        window_flags);
    if (!m_pWindow)
    {
        std::cout << "Failed to open window: " << SDL_GetError() << std::endl;
        exit(1);
    }

    m_pRenderer = SDL_CreateRenderer(
        m_pWindow,
        -1,
        renderer_flags);
    if (!m_pRenderer)
    {
        std::cout << "Failed to create renderer: " << SDL_GetError() << std::endl;
        exit(1);
    }
}

SDL_Renderer *Window::renderer()
{
    return m_pRenderer;
}
