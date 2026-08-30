#include "type.h"
#include <SDL3/SDL.h>
#include "window.hpp"
//main process of the app

int main(void){

//we start by initialising SDL, if it fail, we return with the error code
   if (!SDL_Init(SDL_INIT_VIDEO))
   {
    SDL_Log("SDL_Init Error: %s",SDL_GetError());
    return 1;
   }

//creating the first window for testing
    Transform transform;
    transform.scale.x = 600;
    transform.scale.y = 400;

//Creating a Node of type window
    Window window("NRL Test", transform);
    Window window2("test", transform);

   bool running = true;

//SDL Loop
   while(running)
   {
        SDL_Event event;
//SDL Event polling to catch closing signal
        while (SDL_PollEvent(&event))
        {
            if(event.type == SDL_EVENT_QUIT)
            {
                running = false;
            }
        }
        SDL_RenderPresent(window.GetRenderer());
        SDL_RenderPresent(window2.GetRenderer());
   }

// no need to manually destroy Node, automatically destroyed in the constructor
   SDL_Quit();


    return 0;
}