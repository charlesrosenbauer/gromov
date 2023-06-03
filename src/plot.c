#include "stdint.h"
#include "stdlib.h"
#include "stdio.h"

#include "SDL2/SDL.h"

#include "struct.h"
#include "util.h"
#include "gfx.h"




void drawBox(uint32_t* px, Box b){
	for(int i = 0; i < b.rect.h; i++){
		for(int j = 0; j < b.rect.w; j++){
			px[((b.rect.y + i) * 512) + j + b.rect.x] = b.color;
		}
	}
}
