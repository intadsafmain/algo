#define WIN_W 800
#define WIN_H 600
#define pi 3.14159265359

#define CREATEWIND SDL_CreateWindow("salim XD", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, WIN_W, WIN_H, SDL_WINDOW_SHOWN)
#define CREATEREND SDL_CreateRenderer(wind, -1, SDL_RENDERER_SOFTWARE)


typedef struct{
  int x, y;
} pos;

typedef struct{
    pos centre;
    int rayon;
} cercle;

