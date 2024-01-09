#ifndef __SORT_SCREEN__
#define __SORT_SCREEN__

#include "insert_sort.h"

extern window   wind;
extern renderer rend;
extern TTF_Font* roboto;

extern SDL_Color White;
extern SDL_Color Black;

bool loop = true;

void init_rect          (SDL_Rect* rect, int x, int y, int w, int h);
void init_rect_liste    (element tete, int index, int number_of_elements);

int main_Loop(void){
    SDL_Event e;
    element tete = NULL;
    element queue = NULL;

    SDL_Surface* element_val = NULL;
    
    bool tri = false, plus = true;

    INIT_ELEMENT(&tete);

    queue = tete;

    
    bouton boutons[3];

    boutons [PLUS].S = SDL_LoadBMP("plus.bmp" );
    boutons[MOINS].S = SDL_LoadBMP("moins.bmp");
    boutons[START].S = SDL_LoadBMP("start.bmp");

    init_rect(&boutons  [PLUS].R,  50, 450, 100, 100);
    init_rect(&boutons [MOINS].R, 200, 450, 100, 100);
    init_rect(&boutons [START].R, 550, 450, 200, 100);

    for(int i = 0; i<3; i++){
        boutons[i].T = SDL_CreateTextureFromSurface(rend, boutons[i].S);
        SDL_QueryTexture(boutons[i].T, NULL, NULL,
                         &boutons[i].R.w, &boutons[i].R.h);
    }


    PUSH(&queue)
    PUSH(&queue)
    PUSH(&queue)
    int nbre_elems = 5;

init_rectangles:
    if(plus){
        PUSH(&queue)
    }
    else{
        pull(tete, &queue);
    }

    init_rect_liste(tete, 0, nbre_elems);
    
    
//euheuh
    while(loop){

        rendDrawColor(rend, White);
        SDL_RenderClear(rend);
        
        rendDrawColor(rend, Black);

        for(int i=0; i<3; i++){
            SDL_RenderCopy(rend, boutons[i].T, NULL, &boutons[i].R);
        }
        draw_list(&tete);

        SDL_RenderPresent(rend);

        if(SDL_WaitEvent(&e)){
            switch (e.type){
                case SDL_QUIT:
                    loop = false;
                    break;
                // euheuh
                case SDL_MOUSEBUTTONUP:
                    if( e.button.button == SDL_BUTTON_LEFT ){
                        CLIQUE_COMP(PLUS){
                            if(nbre_elems < LIMITE_MAX){
                                nbre_elems++;
                                plus = true;
                                goto init_rectangles;
                            }
                        }
                        else
                        CLIQUE_COMP(MOINS){
                            if(nbre_elems > LIMITE_MIN){
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
    }
    
    for(int i = 0 ; i<3; i++){
        SDL_DestroyTexture(boutons[i].T);
    }
    element current = tete->next;
    //printf("\n%p\n", current);

    while(tri){
        rendDrawColor(rend, White);
        SDL_RenderClear(rend);


        insert_sort(&current, &tete);
        
        current = current->next;
        while(SDL_PollEvent(&e)){
            switch (e.type){
                case SDL_QUIT:
                    tri = false;
                    break;
            }
        }
        
        rendDrawColor(rend, Black);
        init_rect_liste (tete, 0, nbre_elems);
        draw_list(&tete);
        SDL_RenderPresent(rend);
        if (current == NULL) tri = false;
        SDL_Delay(1000);
    }
    loop = true;
    while(loop){
        if(SDL_WaitEvent(&e)){
            if(e.type == SDL_QUIT){
                loop = false;
            }
        }
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
    int rectd = 100/((number_of_elements-1)),
        rectw = (700/number_of_elements) - rectd;

    init_rect(&tete->rectangle,
              (rectw + rectd) * index + 50,
              300-(rectw/2), rectw, rectw);

    // passage a l'element suivant
    if(tete->next != NULL) init_rect_liste( tete->next, index+1,
                                           number_of_elements);
}


#endif
