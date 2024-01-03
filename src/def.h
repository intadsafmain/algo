#ifdef _WIN32
    #include <SDL.h>
#else
    #include <SDL2/SDL.h>
#endif

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define DEF_WIN_W 800 
#define DEF_WIN_H 600

#define CREATE_WIN(x) SDL_CreateWindow( x, SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, DEF_WIN_W, DEF_WIN_H, SDL_WINDOW_SHOWN)
#define CREATE_REND   SDL_CreateRenderer( wind, -1, SDL_RENDERER_SOFTWARE)

#define BUTTON_W
#define BUTTON_H

#define pi 3.14159265359

#define PLUS    0
#define MOINS   1
#define START   2

#define CLIQUE_COMP(INDX)   if(e.button.x >= boutons[INDX].x && e.button.x <= boutons[INDX].x+boutons[INDX].w && e.button.y >= boutons[INDX].y && e.button.y <= boutons[INDX].y+boutons[INDX].h)
#define PUSH(x)             if(!push(x))        { puts("probleme de pushage askip");    return EXIT_FAILURE;}
#define INIT_ELEMENT(x)     if(!init_elem(x))   { puts("y a un probleme XD");           return EXIT_FAILURE;}

typedef SDL_Window* window;
typedef SDL_Renderer* renderer;

typedef struct {int x,y;} pos;
typedef struct {int w,h;} dim;

typedef struct elem {
    SDL_Rect rectangle;
    int val;
    struct elem* next;
}* element;

