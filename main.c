#include <stdbool.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <stdlib.h>
#include "def.h"
#include "menu.h"


SDL_Window*   wind = NULL;
SDL_Renderer* rend = NULL;

int main(int argc, char **argv) {
  int state = EXIT_FAILURE;

  SDL_Init(SDL_INIT_VIDEO);
    
  if( (wind = CREATEWIND) == NULL ){
    fprintf(stderr, "Ereur creation de fenetre: %s", SDL_GetError());
    goto quit;
  }
  
  if( (rend = CREATEREND) == NULL ){
    fprintf(stderr, "Ereur creation de rendue: %s", SDL_GetError());
    goto quit_rend_err;
  }

  // le contenu!
  printf("tout va bien");

  menu_loop();

  // fin du contenu!

  state = EXIT_SUCCESS;
  SDL_DestroyRenderer(rend);

quit_rend_err:
  SDL_DestroyWindow  (wind);

quit:
  SDL_Quit();
  return state;
}
