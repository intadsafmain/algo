#ifndef __LISTE_FUNCTIONS__
#define __LISTE_FUNCTIONS__

#include "def.h"

extern renderer rend;
extern TTF_Font* roboto;

SDL_Color Black = {0,0,0,0};
SDL_Color White = {255,255,255,255};


int generate(void){
    srand (rand()+time(NULL));
    return rand()%999;
}

int init_elem(element* tete){
    *tete = (element)malloc(sizeof(struct elem));
    (*tete)->next = NULL;
    
    (*tete)->val = generate();

    char* s = (char*)malloc(sizeof(char)*3);
    sprintf( s, "%d", (*tete)->val);
    
    (*tete)->S = TTF_RenderText_Solid(roboto, s, Black);
    (*tete)->T = SDL_CreateTextureFromSurface(rend, (*tete)->S);

    printf("%d\n",(*tete)->val);
    free(s);

    return (*tete) != NULL;
}

int push(element* queue){
    element nouv = NULL;

    INIT_ELEMENT(&nouv);
    
    (*queue) ->next  = nouv;
    *queue = nouv;
    return (queue != NULL);
}

int pull(element tete, element* queue){
    if (tete->next != *queue) pull(tete->next,queue);
    else {
        free(*queue);
        *queue = tete;
        (*queue)->next = NULL;
    }
    return 0;
}

int draw_list(element* tete){
    if(*tete !=  NULL){
        int w;
        if((*tete)->val<10){
            w = ((*tete)->rectangle.w/3);
        }
        else if((*tete)->val<100){
            w = 2*((*tete)->rectangle.w/3);
        }
        else{
            w = (*tete)->rectangle.w- 2*((*tete)->rectangle.w/10);
        }
        SDL_Rect text_container = {
            (*tete)->rectangle.x + (((*tete)->rectangle.w-w)/2),
            (*tete)->rectangle.y,
            w,
            (*tete)->rectangle.h
        };
        SDL_RenderCopy(rend, (*tete)->T, NULL, &text_container);

        SDL_RenderDrawRect(rend, &(*tete)->rectangle);
        
        /*
        SDL_SetRenderDrawColor(rend, 255, 0, 0, 255);
        SDL_RenderDrawRect(rend, &text_container);
        SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);
        */

        draw_list(&(*tete)->next);
        
        int y = (*tete)->rectangle.y+(*tete)->rectangle.h/2;
        
        if((*tete)->next != NULL)
        SDL_RenderDrawLine(rend,
                           (*tete)->rectangle.x+(*tete)->rectangle.w, Y(rectangle),
                           (*tete)->next->rectangle.x, Y(next->rectangle) );


    }
    return 0;
}

int free_list(element tete){
    if(tete != NULL)
        free_list(tete->next);
    free(tete);
    return 0;
}

void rendDrawColor(renderer rend, SDL_Color color){
    SDL_SetRenderDrawColor(rend, color.r, color.g, color.b, color.a);
}

#endif
