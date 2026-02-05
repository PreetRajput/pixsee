#include <stdio.h>
#include "decoder.h"
#include <SDL3/SDL.h>

int main(int argc, char **argv)
{
  // p[]
    if(argc<2)
    {
        printf("forgot to give the image path ig");
        return 1;
    }
    char *path = argv[1];
    decoder(path);
    SDL_Quit();
}

