#ifdef _WIN32
    #include <SDL.h>
#else
    #include <SDL2/SDL.h>
#endif

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "sort_screen.h"

#define DEF_WIN_W 800 
#define DEF_WIN_H 600

#define CREATE_WIN(x) SDL_CreateWindow( x, SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, DEF_WIN_W, DEF_WIN_H, SDL_WINDOW_SHOWN|SDL_WINDOW_RESIZABLE)
#define CREATE_REND   SDL_CreateRenderer( wind, -1, SDL_RENDERER_SOFTWARE)

#define BUTTON_W
#define BUTTON_H

#define pi 3.14159265359

typedef SDL_Window* window;
typedef SDL_Renderer* renderer;
