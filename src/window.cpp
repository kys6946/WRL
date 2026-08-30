#include "window.hpp"
#include <iostream>

Window::Window(const char* title, Transform transf){
    sdlWindow = SDL_CreateWindow(title, (int)transf.scale.x, (int)transf.scale.y,0);

    if (sdlWindow == nullptr)
    {
        SDL_Log("SDL_CreateWindow failed: %s", SDL_GetError());
    }
    else
    {
        SDL_Log("Window created successfully!");
    }

    sdlRenderer = SDL_CreateRenderer(sdlWindow, nullptr);
    
    if(sdlWindow == nullptr)
    {
        SDL_Log("SDL_CreateRenderer failed: %s", SDL_GetError());
    }
    else
    {
        SDL_Log("SDL_Renderer created succesfully!");
    }
}

Window::~Window()
{
    if(sdlWindow != nullptr)
    {
        SDL_DestroyWindow(sdlWindow);
    }
}

SDL_Renderer* Window::GetRenderer()
{
    return sdlRenderer;
}