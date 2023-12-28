#ifndef __MENU__
#define __MENU__

#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_timer.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include "def.h"

extern SDL_Window* wind;
extern SDL_Renderer* rend;

SDL_Event e;

bool loop = true;

int mainLoop(int size) {

  bool up = true;
  pos clic;
  pos coord;

  cercle cercle;
  cercle.centre.x = WIN_W/2;
  cercle.centre.y = WIN_H/2;
  cercle.rayon = 100;

  SDL_Rect rect;
  
  SDL_Rect elem;

  while (loop) {
    SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);
    SDL_RenderClear(rend);

    SDL_SetRenderDrawColor(rend, 255, 255, 255, 255);



    while (SDL_PollEvent(&e)) {

      switch (e.type) {

        case SDL_QUIT:
          loop = false;
          break;

        case SDL_MOUSEBUTTONDOWN:
          if(e.button.button == SDL_BUTTON_LEFT){
            mouse_hold = true;
            clic.x = e.button.x;
            clic.y = e.button.y;
          }
          break;
        
        case SDL_MOUSEBUTTONUP:
          if(e.button.button == SDL_BUTTON_LEFT)
            mouse_hold = false;
          break;


      }
    }
    
    if(mouse_hold){
      SDL_GetMouseState(&coord.x, &coord.y);
      rect.x = clic.x;
      rect.y = clic.y;
      rect.w = coord.x - clic.x;
      rect.h = coord.y - clic.y;

      printf("%d %d %d %d\n", rect.x, rect.y, rect.w, rect.h);
      SDL_SetRenderDrawColor(rend, 255, 0, 255, 255);
      SDL_RenderDrawRect(rend, &rect);
    }

    SDL_Delay(100);
    SDL_RenderPresent(rend);
    
    //if(up){
      j+=0.5;
    /*  if(j==cercle.rayon) up = false;
    }
    else{
      j--;
      if(j==0) up = true;
    }
    */
  }
  
  return 0;
}

#endif
