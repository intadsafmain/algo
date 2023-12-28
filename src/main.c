#include "def.h"
#include "sort_screen.h"

window wind;
renderer rend;

int main(int argc, char** argv){
    SDL_Init(SDL_INIT_VIDEO);
    // gestion teh les euh problemes ta vu
    //  _ -
    // (OUo)
    //   o

    if ( (wind = CREATE_WIN("")) == NULL){
        printf("ereur creation fenetre: %s", SDL_GetError());
        goto quit;
    }
    
    if ( (rend = CREATE_REND) == NULL){
        printf("ereur creation rendu: %s", SDL_GetError());
        goto quit_2;
    }   
    // main loop ici ça commence !!

        puts("tout va bien dans le meilleur des mondes"); 
        main_Loop();

    // fin du program on rembale (et non XD)
    SDL_DestroyWindow(wind);
quit_2:
    SDL_DestroyRenderer(rend);
quit:
    SDL_Quit();
    return 0;
}
