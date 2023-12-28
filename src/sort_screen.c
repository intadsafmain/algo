#ifndef __SORT_SCREEN__
#define __SORT_SCREEN__

#include "def.h"

extern window   wind;
extern renderer rend;

bool loop = true;

int main_Loop(){
    SDL_Event e;

    while(loop){
        SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);
        SDL_RenderClear(rend);
        //default rendering
        
        
        //interaction / interaction rendering
        while(SDL_PollEvent(&e)){
            switch (e.type) {
            case SDL_QUIT:
                loop = false;
                break;
            }
        }

        SDL_RenderPresent(rend);
    }
    
    return 0;
}

#endif
