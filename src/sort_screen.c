#ifndef __SORT_SCREEN__
#define __SORT_SCREEN__

#include "def.h"

extern window   wind;
extern renderer rend;

bool loop = true;

void init_rect(SDL_Rect* rect, int x, int y, int w, int h);

int main_Loop(){

    SDL_Event e;
    SDL_Rect start_bout;
    bool left_hold = false;
    

    //mes enrengistrements a oim UwU
    pos mouse_pos, diff;
    dim window_dim;
    element tete = NULL;
    tete = (element)malloc(sizeof(element));
    tete->next = (element)malloc(sizeof(element));
    tete->next->next = NULL;

    int i = 0;

    // les coordinations constante avant la boucle
    
    for(element p = tete; p!=NULL; p = p->next){
       init_rect( &p->rectangle, 50 + 150*i, 50, 100, 50);
       if(p->next != NULL){
            p->queue.x = 50 + 150*(i+1);
            p->queue.y = 75;
        }   
    }    



    while(loop){
        SDL_SetRenderDrawColor(rend, 0, 0, 0, 0);
        SDL_RenderClear(rend);

        SDL_GetWindowSize(wind, &window_dim.w, &window_dim.h);
        
        /*
         *  animation rendering: tout ce qui se modifie par rapport a l'environemnt genre la taille de la fenetre qui géchan
         *  qui n'a rien a voir avec les interactions mais qui fait une animation quand meme (genre euh le triage)
         *  je pense a implementer les threads, pour avoir le input et l'animation en paralele comme ça on pourais intérompre
         *  comme on veux ta capté?
        */

        /*
         *  init_rect(&start_bout, 9*window_dim.w/16, 7*window_dim.h/12, 3*window_dim.w/8, window_dim.h/3);
         *  ça c'est marrant mais on a besoins de savoir:
         *  -[] comment fixer un taille minimum pour la fenetre
         *  -[] le ratio teh le bouton
        */


        
        //interaction / interaction rendering: tout ce qui est
        //rendering par rapport a l'input
        if(SDL_WaitEvent(&e)){
            switch (e.type) {
            case SDL_QUIT:
                loop = false;
                break;
            
            case SDL_MOUSEBUTTONDOWN:
                if
                (e.button.button == SDL_BUTTON_LEFT /*&&
                        e.button.x >= rect.x && e.button.x <= rect.x+rect.w &&
                        e.button.y >= rect.y && e.button.y <= rect.y+rect.h*/){
                        left_hold = true;
                }
                break;

            case SDL_MOUSEBUTTONUP:
                if(left_hold) left_hold = false;
                break;

            case SDL_MOUSEMOTION:
                break;
            }
        }

        //conclution: euh voila on imprime tout ici
        SDL_SetRenderDrawColor(rend, 255, 255, 255, 255);

        for(element p = tete; p!=NULL; p = p->next){
            SDL_RenderDrawRect(rend, &p->rectangle);
            SDL_RenderDrawLine(rend,
                               p->rectangle.x+p->rectangle.w, // x1
                               p->rectangle.y+(1/2)*p->rectangle.h, //y1
                               p->queue.x, p->queue.y); // x2, y2
        }   
    }    

        SDL_RenderDrawRect(rend, &start_bout);
        SDL_RenderPresent(rend);
    return 0;
}

void init_rect(SDL_Rect* rect, int x, int y, int w, int h){
    (*rect).x = x;
    (*rect).y = y;
    (*rect).w = w;
    (*rect).h = h;
}

#endif
