#ifndef __LISTE_FUNCTIONS__
#define __LISTE_FUNCTIONS__

#include "def.h"

extern renderer rend;

int generate(void){
    srand(time(NULL));
    return rand()%9999;
}

int init_elem(element* tete){
    *tete = (element)malloc(sizeof(struct elem));

    (*tete)->next = NULL;
    (*tete)->val = generate();

    return (*tete) != NULL;
}

int push(element* queue){
    element nouv = NULL;

    INIT_ELEMENT(&nouv);
    
    (*queue) ->next  = nouv;
    nouv     ->next  = NULL;
    *queue = nouv;
    return (queue != NULL);
}

int pull(element tete, element* queue){
    if (tete->next->next != NULL) pull(tete,queue);
    else {
        free(queue);
        *queue = tete->next;
        (*queue)->next = NULL;
    }
    return 0;
}

int draw_list(element tete){
    if(tete !=  NULL){
        SDL_RenderDrawRect(rend, &tete->rectangle);

        draw_list(tete->next);
        
        int y = tete->rectangle.y+tete->rectangle.h/2;
        
        if(tete->next != NULL)
        SDL_RenderDrawLine(rend,
                           tete->rectangle.x+tete->rectangle.w, y,
                           tete->next->rectangle.x, y);
    }
    return 0;
}

int free_list(element tete){
    if(tete != NULL)
        free_list(tete->next);
    free(tete);
    return 0;
}

#endif
