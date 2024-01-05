#include "sort_screen.h"

window wind;
renderer rend;
TTF_Font* roboto = NULL;

int main(int argc, char** argv){
    int return_v = EXIT_SUCCESS;

    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    
    TTF_Init();

    //  _ -
    // (OUo)
    //   o

    if( (roboto = TTF_OpenFont("bin/Roboto-Regular.ttf", 500))==NULL ) {
        puts(TTF_GetError());
        goto quit;
    }

    if ( (wind = CREATE_WIN("PROJECT ALGO 3")) == NULL){
        printf("ereur creation fenetre: %s", SDL_GetError());
        goto quit;
    }
    SDL_SetWindowMinimumSize(wind, DEF_WIN_W, DEF_WIN_H);
    
    if ( (rend = CREATE_REND) == NULL){
        printf("ereur creation rendu: %s", SDL_GetError());
        SDL_DestroyWindow(wind);
        goto quit;
    }   

    return_v = main_Loop();

    // fin du program on rembale
    SDL_DestroyWindow(wind);
    SDL_DestroyRenderer(rend);
quit:
    TTF_Quit();
    SDL_Quit();
    return return_v;
}
