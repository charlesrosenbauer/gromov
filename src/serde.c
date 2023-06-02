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
	
	return ret;
}
