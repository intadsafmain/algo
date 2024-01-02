#ifndef __SORT_SCREEN__
#define __SORT_SCREEN__

#include "def.h"

extern window   wind;
extern renderer rend;
bool loop = true;

void init_rect(SDL_Rect* rect, int x, int y, int w, int h);

int init_elem(element tete);
int push(element tete);

int main_Loop(){
    SDL_Event e;
    element tete = NULL;

    if(!init_elem(tete)){
        puts("tout le va pas bien en fin de compte");
        fprintf(stderr, "ereur alocation element");
        return EXIT_FAILURE;
    }


    while(loop){
        SDL_RenderClear(rend);

        if(SDL_WaitEvent(&e)){
            switch (e.type){
                case SDL_QUIT:
                    loop = false;
                break;
            }
        }

        SDL_RenderPresent(rend);
    }

    free(tete);
    return EXIT_SUCCESS;
}

//-------------------------

void init_rect(SDL_Rect* rect, int x, int y, int w, int h){
    (*rect).x = x;
    (*rect).y = y;
    (*rect).w = w;
    (*rect).h = h;

    SDL_RenderDrawRect(rend, rect);
}

int init_elem(element tete){
    tete = (element)malloc(sizeof(struct elem));
    tete->next = NULL;
    return tete != NULL;
}

int push(element tete){
    if(tete->next != NULL){
        push(tete->next);
    }
    else{
        element nouv = NULL;
        init_elem(nouv);
        tete->next = nouv;
        nouv->next = NULL;
    }
    return 0;
}

#endif
