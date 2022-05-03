#include "Window.hpp"
#include "../utils/Constants.hpp"

#include <iostream>

Window::Window()
{

}

Window::~Window()
{
    //SDL_DestroyRenderer(m_pRenderer);
    //SDL_DestroyWindow(m_pWindow);
}

void Window::create()
{
    m_pWindow = SDL_CreateWindow(
        "Rougelike",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
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

//Window::Window(Window&& win)
//{
//    this->m_pRenderer = win.m_pRenderer;
//    this->m_pWindow = win.m_pWindow;
//}
//
//Window::Window(Window& win)
//{
//    this->m_pRenderer = win.m_pRenderer;
//    this->m_pWindow = win.m_pWindow;
//}
//
//Window& Window::operator=(Window&& win)
//{
//    if (this != &win)
//    {
//        this->m_pRenderer = win.m_pRenderer;
//        this->m_pWindow = win.m_pWindow;
//    }
//    return *this;
//}

SDL_Renderer *Window::renderer()
{
    return m_pRenderer;
}