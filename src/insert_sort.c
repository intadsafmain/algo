#ifndef __INSERT_SORT__
#define __INSERT_SORT__
#include "liste_fun.h"
#include <SDL2/SDL_surface.h>

extern renderer rend;
SDL_Color Red = {255,0,0,255};

int insert_sort(element current, element tete){
    if(tete->next != current){
        if(insert_sort(current, tete->next)){
            current->next = tete->next;
            tete->next = current;
            return 1;
        } else
        if(tete->val > current->val){
            SDL_FillRect( NULL, &(tete->rectangle), Red);
            tete->next = current->next;
            return 1;
        }
    }
    return 0;
}

#endif
