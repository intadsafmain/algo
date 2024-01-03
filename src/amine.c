#include <stdbool.h>
#include <stdio.h>
#include <SDL.h>

typedef struct list{
    int val ;
    struct list *next ; 
}* list ;

void creatrec(SDL_Renderer *ren, int x, int taille){
    SDL_Rect recta;
    int r,i;
    r=(1200/taille);
    i=(50/(taille-1));
    recta.x=(r*x)+i;
    recta.y=200;
    recta.w=r-(r/3);
    recta.h=100;
    if(x!=taille-1){
    SDL_RenderDrawLine(ren,r-(r/3)+(r*x)+i,250,r+(r*x)+i,250);}
    SDL_RenderFillRect(ren,&recta);
}

int main(int arc, char** argv){
    int a;
    int f;
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window  *windo=NULL;
    SDL_Renderer *rend=NULL;
    
    
    printf("taille ya wld");
    scanf("%d",&a);

	windo = SDL_CreateWindow("ta3i",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1200,600,0);
    rend  = SDL_CreateRenderer(windo,-1,SDL_RENDERER_SOFTWARE);
    
    SDL_SetRenderDrawColor(rend, 255, 255, 255, 255);

    f=a;
    while (f!=0)
    {
        creatrec(rend,a-f,a);
        f--;
        
    };
    
  
    SDL_RenderPresent(rend);
    SDL_Delay(9000);
    SDL_DestroyWindow(windo);
    SDL_Quit();
    return EXIT_SUCCESS;
}