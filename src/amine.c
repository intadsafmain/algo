#include <SDL_ttf.h>
#include <stdbool.h>
#include <stdio.h>
#include <SDL.h>
int main(int arc, char** argv){
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *windo=NULL;
    SDL_Renderer *rend=NULL;
	windo=SDL_CreateWindow("ta3i",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,600,0);  
    rend=SDL_CreateRenderer(windo,-1,SDL_RENDERER_SOFTWARE);
    SDL_CreateWindowAndRenderer(1200,600,0,&windo,&rend);
    SDL_SetRenderDrawColor(rend,112,15,15,SDL_ALPHA_OPAQUE);
    /*SDL_RenderDrawPoint(rend,100,450);*/
    /*SDL_RenderDrawLine(rend,50,50,500,500);*/
    SDL_Rect recta;
    recta.x=1100;
    recta.y=570;
    recta.w=80;
    recta.h=20;
 


    SDL_RenderFillRect(rend,&recta);

    SDL_RenderPresent(rend);
    SDL_Delay(600000);
    SDL_DestroyWindow(windo);
    SDL_Quit();
    return EXIT_SUCCESS;
}