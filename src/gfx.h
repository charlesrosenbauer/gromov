#ifndef __GFX_HEADER__
#define __GFX_HEADER__


#include "stdint.h"

#include "struct.h"




typedef struct{
	int h, w, x, y;
}Rect;

typedef struct{
	Rect rect;
	uint32_t color;
}Box;



void drawBox(uint32_t*, Box);


#endif
