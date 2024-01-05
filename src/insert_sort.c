#ifndef __INSERT_SORT__
#define __INSERT_SORT__
#include "liste_fun.h"

extern renderer rend;
extern SDL_Color Black;
extern SDL_Color White;
SDL_Color Red   = {255, 0, 0, 255};
SDL_Color Green = {0, 255, 0, 255};

int insert_sort(element current, element tete){
    puts("a");
    if(tete->next != current){
        if(insert_sort(current, tete->next) == 1){
            current->next = tete->next;
            tete->next = current;
        }

    }
    else{
        if(tete->val > current->val){
            rendDrawColor(rend, Red);
            SDL_RenderFillRect( rend,    &(tete->rectangle));
            SDL_RenderFillRect( rend, &(current->rectangle));
            tete->next = current->next;
            return 1;
        }
        else{
            rendDrawColor(rend, Green);
            SDL_RenderFillRect( rend,    &(tete->rectangle));
            SDL_RenderFillRect( rend, &(current->rectangle));
        }
    }
    return 0;
}

#endif
