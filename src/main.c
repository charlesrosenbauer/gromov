#include "stdint.h"
#include "stdlib.h"
#include "stdio.h"

#include "SDL2/SDL.h"

#include "util.h"


int main(int ac, char** av){
	uint8_t** bytes = alloca(sizeof(uint8_t ) * ac);
	int64_t*  sizes = alloca(sizeof(uint64_t) * ac);
	for(int i = 1; i < ac; i++){
		printf("Loading %s...\n", av[i]);
		if(!loadFile(av[i], (char**)&bytes[i], &sizes[i])){
			printf("  Could not load %s\n", av[i]);
		}
	}
}
