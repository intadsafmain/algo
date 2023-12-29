#include <stdbool.h>
#include <stdio.h>
#include <SDL.h>

typedef struct list{
    int val ;
    struct list *next ; 
}* list ;

void creatrec(SDL_Renderer *ren, int x, int taille){
    SDL_Rect recta;
    int r;
    r=250/taille;
    recta.x=((800/taille)*x)+50;
    recta.y=200;
    recta.w=(800/taille)-r-50;
    recta.h=100;
    if(x!=taille){
    SDL_RenderDrawLine(ren,(((800/taille)-r-50)*x)+50,250,((800/taille)*x)+50,250);}
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

	windo = SDL_CreateWindow("ta3i",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,600,0);
    rend  = SDL_CreateRenderer(windo,-1,SDL_RENDERER_SOFTWARE);
    
    SDL_SetRenderDrawColor(rend, 255, 255, 255, 255);

    f=a;
    while (f!=0)
    {
        creatrec(rend,a-f,a);
        f--;
        
    };
    
    /*SDL_RenderDrawPoint(rend,100,450);*/
    /*
    
    SDL_SetRenderDrawColor(rend,112,15,15,SDL_ALPHA_OPAQUE);SDL_RenderDrawLine(rend,50,50,500,500);
    SDL_Rect recta;
    recta.x=1100;
    recta.y=570;
    recta.w=80;
    recta.h=20;
     SDL_RenderFillRect(rend,&recta);
    SDL_Surface *image=NULL;
    SDL_Texture *text=NULL;
    image =SDL_LoadBMP("src/start.bmp");
    text= SDL_CreateTextureFromSurface(ren,image);
    SDL_FreeSurface(image);
    SDL_Rect rec;
    SDL_QueryTexture(text,NULL,NULL,&rec.w,&rec.h);
    rec.x=(800-rec.w)/2;
    rec.y=(600-rec.h)/2;
    SDL_RenderCopy(rend,text,NULL,&rec);
    
    */
    SDL_RenderPresent(rend);
    SDL_Delay(8000);
    SDL_DestroyWindow(windo);
    SDL_Quit();
    return EXIT_SUCCESS;
}