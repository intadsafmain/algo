#include "def.h"


window wind;
renderer rend;

int main(int argc, char** argv){
    int return_v = EXIT_SUCCESS;
    SDL_Init(SDL_INIT_VIDEO);
    //  _ -
    // (OUo)
    //   o

    if ( (wind = CREATE_WIN("window >:O")) == NULL){
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
    SDL_Quit();
    return return_v;
}
