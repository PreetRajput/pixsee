#include <SDL3/SDL.h>
#include "../windowCreation.h"

SDL_Window* windowCreation(int width, int height) {
  
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = SDL_CreateWindow(
        "Image Viewer",
        width,
        height,
        0
    );


    return window;

}
