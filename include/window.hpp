#include <SDL3/SDL.h>
#include "type.h"
#include "node.hpp"

class Window : public Node{
public:
    Window(const char* title, Transform transf);
    ~Window();

    SDL_Renderer* GetRenderer();
private:
    SDL_Window* sdlWindow = nullptr;
    SDL_Renderer* sdlRenderer = nullptr;
};