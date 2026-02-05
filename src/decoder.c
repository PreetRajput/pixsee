#include <stdio.h>
#define STB_IMAGE_IMPLEMENTATION
#include "../stb_image.h"
#include <SDL3/SDL.h>
#include "../decoder.h"
#include "../windowCreation.h"
int running = 1;
void handle_events(void) {
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_EVENT_QUIT) {
            running = 0;
        }
    }
}

void decoder(char *x)
{
    int width, height, channel;
    unsigned char *pixels= stbi_load(x, &width, &height, &channel, 3);

    if (!pixels) {
        printf("decode failed: %s\n", stbi_failure_reason());
        return ;
    }

    printf("width=%d height=%d channels=%d\n",
           width, height, channel);

    unsigned char r = pixels[0];
    unsigned char g = pixels[1];
    unsigned char b = pixels[2];

    printf("first pixel: %u %u %u\n", r, g, b);

   SDL_Window *window=  windowCreation(width, height);
   SDL_Renderer *renderer = SDL_CreateRenderer(window, NULL);

   
   
   SDL_Texture *tex = SDL_CreateTexture(
    renderer,
    SDL_PIXELFORMAT_RGB24,
    SDL_TEXTUREACCESS_STREAMING,
    width,
    height
        );

    int pitch= width*3;
    SDL_UpdateTexture(tex, NULL, pixels, pitch);
    stbi_image_free(pixels);


    while (running) {
            handle_events();
            SDL_RenderClear(renderer);
            SDL_RenderTexture(renderer, tex, NULL, NULL);
            SDL_RenderPresent(renderer);
    }

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyTexture(tex);
}