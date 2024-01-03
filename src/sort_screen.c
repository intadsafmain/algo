#ifndef __SORT_SCREEN__
#define __SORT_SCREEN__

#include "liste_fun.h"
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
    
    bool tri = false;

    INIT_ELEMENT(&tete);
    (tete != NULL) ? puts("less go (nsm)"): puts("azy putain");

    queue = tete;
    printf("%p %p", queue, &queue);
    puts("j'ai fait ça pour me sauver il a dit");
    PUSH(&queue);
    PUSH(&queue);
    PUSH(&queue);
    puts("less go");
    int nbre_elems = 3;

    SDL_Rect boutons[3];

    init_rect(&boutons[PLUS],   50, 450, 100, 100);
    init_rect(&boutons[MOINS], 200, 450, 100, 100);
    init_rect(&boutons[START], 450, 450, 200, 100);
    puts("azy");

init_rectangles:
    init_rect_liste(tete, 0, nbre_elems);
    
    puts("aya nikmok");
    while(loop){
        puts("a");
        SDL_RenderClear(rend);
        
        for(int i=0; i<3; i++){
            SDL_RenderDrawRect(rend,&boutons[i]);
        }

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
                                goto init_rectangles;
                            }
                        }
                        else
                        CLIQUE_COMP(MOINS){
                            if(nbre_elems > 3){
                                nbre_elems--;
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
    int rectw = 700/number_of_elements,
        rectd = 50/(number_of_elements-1);
    init_rect(&tete->rectangle,
              (rectw * index) + rectd + 50,
              100, rectw, rectw);

    // passage a l'element suivant
    if(tete != NULL) init_rect_liste( tete->next, index+1, number_of_elements);
}


#endif
