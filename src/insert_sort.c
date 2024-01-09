#ifndef __INSERT_SORT__
#define __INSERT_SORT__

#include "liste_fun.h"

extern  renderer rend;
extern  SDL_Color Black;
extern  SDL_Color White;
        SDL_Color Red    = {255, 20, 20, 255};
        SDL_Color Green  = {20, 255, 20, 255};
        SDL_Color Purple = {255, 0, 255, 255};

int insert_sort(element* current, element* tete){
    
    rendDrawColor(rend, Purple);
    SDL_RenderFillRect(rend, &CURRENT->rectangle);
    element pp = TETE, pg = TETE, temp = TETE;
    
    while(temp->next != CURRENT){
        temp = temp->next;
    }
    while(pg->val < CURRENT->val && pg != CURRENT){
        rendDrawColor(rend, Green);
        SDL_RenderFillRect(rend, &pg->rectangle);
        pg   = pg -> next;
    }

    if(pg == TETE){
        if(pg->val < CURRENT->val) return 0;

        TETE = CURRENT;
        if(pg->next == CURRENT){
            pg->next = CURRENT->next;
            CURRENT->next = pg;
            CURRENT = pg->next;
            return 1;
        }
        else{
            temp->next = CURRENT->next;
            CURRENT->next = pg;
            CURRENT = temp;
            return 1;
        }
    }
    else if(pg == CURRENT){
        return 0;
    }

    while(pp->next != pg){
        pp   = pp -> next;
    }

    rendDrawColor(rend, Red);
    SDL_RenderFillRect(rend, &pp->next->rectangle);

    temp->next = CURRENT->next;
    CURRENT->next = pg;
    pp->next = CURRENT;
    //CURRENT = temp;
    return 1;
}

#endif
