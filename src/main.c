#include "stdint.h"
#include "stdlib.h"
#include "stdio.h"

#include "SDL2/SDL.h"

#include "gfx.h"
#include "util.h"


int main(int ac, char** av){
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* w = SDL_CreateWindow("Gromov",
				SDL_WINDOWPOS_UNDEFINED,
				SDL_WINDOWPOS_UNDEFINED,
				512, 512, SDL_WINDOW_SHOWN);
	SDL_Surface* screen = SDL_GetWindowSurface(w);

	uint8_t** bytes = alloca(sizeof(uint8_t ) * ac);
	int64_t*  sizes = alloca(sizeof(uint64_t) * ac);
	for(int i = 1; i < ac; i++){
		printf("Loading %s...\n", av[i]);
		if(!loadFile(av[i], (char**)&bytes[i], &sizes[i])){
			printf("  Could not load %s\n", av[i]);
		}
	}
	
	uint32_t* pix = screen->pixels;
	for(int i = 0; i < 262144; i++) pix[i] = 0xffffff;
	
	drawBox(pix, (Box){32, 48, 128, 64});
	
	int cont = 1;
	while(cont){
		SDL_Event e;
		while(SDL_PollEvent(&e)) if(e.type == SDL_QUIT) cont = 0;
		
		SDL_UpdateWindowSurface(w);
		SDL_Delay(16);
	}
	SDL_Quit();
}
