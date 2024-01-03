#ifndef __SORT_SCREEN__
#define __SORT_SCREEN__

#include "liste_fun.h"
#include <SDL2/SDL_render.h>
#include <time.h>


extern window   wind;
extern renderer rend;
bool loop = true;

void init_rect(SDL_Rect* rect, int x, int y, int w, int h);
void init_rect_liste (element tete, int index, int number_of_elements);

int main_Loop(){
    SDL_Event e;
    element tete = NULL;
    element queue = NULL;
    
    bool tri = false, plus = false;

    INIT_ELEMENT(&tete);

    queue = tete;

    SDL_Rect boutons[3];

    init_rect(&boutons[PLUS],   50, 450, 100, 100);
    init_rect(&boutons[MOINS], 200, 450, 100, 100);
    init_rect(&boutons[START], 550, 450, 200, 100);

    PUSH(&queue);
    PUSH(&queue);
    int nbre_elems = 3;

init_rectangles:
    if(plus){
        PUSH(&queue)
    }
    else{

    }
    printf("%d\n", nbre_elems);
    init_rect_liste(tete, 0, nbre_elems);
    
    while(loop){

        SDL_SetRenderDrawColor(rend, 0, 0, 0, 0);
        SDL_RenderClear(rend);
        
        SDL_SetRenderDrawColor(rend, 255, 255, 255, 255);
        
        for(int i=0; i<3; i++){
            SDL_RenderDrawRect(rend,&boutons[i]);
        }
        
        draw_list(tete);

        if(SDL_WaitEvent(&e)){
            switch (e.type){
                case SDL_QUIT:
                    loop = false;
                    break;

                // euheuh
                case SDL_MOUSEBUTTONUP:
                    if( e.button.button == SDL_BUTTON_LEFT ){
                        CLIQUE_COMP(PLUS){
                            if(nbre_elems < 10){
                                nbre_elems++;
                                plus = true;
                                goto init_rectangles;
                            }
                        }
                        else
                        CLIQUE_COMP(MOINS){
                            if(nbre_elems > 3){
                                nbre_elems--;
                                plus = false;
                                goto init_rectangles;
                            }
                        }
                        else
                        CLIQUE_COMP(START){
                            tri = true;
                            loop = false;
                        }
                    }
                break;
            }
        }

        SDL_RenderPresent(rend);
    }

    free_list(tete);
    return EXIT_SUCCESS;
}

//-------------------------

void init_rect(SDL_Rect* rect, int x, int y, int w, int h){
    (*rect).x = x;
    (*rect).y = y;
    (*rect).w = w;
    (*rect).h = h;
}

void init_rect_liste (element tete, int index, int number_of_elements){
    int rectw = 700/(number_of_elements*2),
        rectd = 50/((number_of_elements-1)*2);
    init_rect(&tete->rectangle,
              rectw * index + ((index == 0) ? 0 : rectd)+50,
              100, rectw, rectw);

    // passage a l'element suivant
    if(tete->next != NULL) init_rect_liste( tete->next, index+1, number_of_elements);
}


#endif
