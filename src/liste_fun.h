#ifndef __LISTE_FUNCTIONS__
#define __LISTE_FUNCTIONS__
#include "def.h"

int init_elem   (element* tete);
int draw_list   (element* tete);
int free_list   (element tete);
int push        (element* queue);
int pull        (element tete, element* queue);
#endif
