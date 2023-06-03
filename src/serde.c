#include "string.h"
#include "stdint.h"
#include "stdlib.h"
#include "stdio.h"

#include "struct.h"
#include "util.h"



/*
	We need to parse a byte stream based on a specification and transform it
	into a data structure. For debugging, etc. we probably want to also include
	the inverse as well.
	
	Additionally, we need operations on it: construct trees, traverse trees,
	read contents, edit contents, check types, check identifiers, etc.
*/
File initFile(char* path){
	File ret;
	ret.path	= path;
	printf("Loading %s...        ", path);
	if(!loadFile(path, (char**)&ret.bytes, &ret.size)){
		printf("fail\n");
		return (File){.path=path, .bytes=NULL, .size=-1};
	}else{
		printf("done\n");
	}
	
	int len   = strlen(path);
	int ix    = -1;
	for(int i = 0; i < len; i++) ix = (path[i] == '.')? i : ix;
	
	if(ix >= 0){
		if(!strncmp(&path[ix], ".grv", 4)) ret.kind = FK_TSPEC;
		if(!strncmp(&path[ix], ".gvb", 4)) ret.kind = FK_BSPEC;
		if(!strncmp(&path[ix], ".gbn", 4)) ret.kind = FK_BIN;
	}else{
		ret.kind = FK_NIL;
	}
	
	return ret;
}
