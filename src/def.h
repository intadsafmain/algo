#include <SDL2/SDL_rect.h>
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

typedef struct {int x,y;} pos;
typedef struct {int w,h;} dim;

typedef struct elem {
    SDL_Rect rectangle;
    pos queue; // les cordonnées de la tete c'est ( x+w, y+(1/2)h) donc pas besoins de les stocker tu vois
    int val;
    struct elem* next;
}* element;

// on devrait ajouter un truc teh ttf ou chepaquoi ici on vera apres.
/* la queue de cheval? XD XD
 * serieusement la queue be like:
 * > elem.line.queue.x = elem->next.rectangle.x (en gros euh)
 * > elem.line.queue.y = (elem->next.rectagle.y + elem->next.rectangle.h) / 2
 * > ET si elem->next == NULL, la queue elle reçoit la tete. ou bien ba rien mais ça prend de l'espace a la fin grrr (énervé)
 * > la tete elle est constante elle est pas variable c'est pas la peine de la stocker
 * 
 * le truc c'est que ça dessinne des lignes droite pas des lignes courbé là grrrrr (different de grrr).
 * mais de toute façon y a pas besoins de as t'es bete ou quoi?(ToT).
 * mais au cas ou c'est SDL2_GFX  .L. 
 *                                  o m
 *           (je voulais)            //
 *       (dessiner une main)
 */
