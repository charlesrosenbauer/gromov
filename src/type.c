#include "stdint.h"
#include "stdlib.h"
#include "stdio.h"

#include "struct.h"
#include "util.h"


TypeTable makeTypeTable(int tsize, int nsize){
	TypeTable ret;
	ret.types	= malloc(sizeof(Type) * tsize);
	ret.names	= malloc(sizeof(char) * nsize);
	ret.tsize	= tsize;
	ret.nsize	= nsize;
	ret.tfill	= 0;
	ret.nfill	= 0;
	return ret;
}


void printTypeTable(TypeTable ttab){
	printf("========[T: %5i/%5i]====[N: %6i/%6i]========\n", ttab.tfill, ttab.tsize, ttab.nfill, ttab.nsize);
	for(int i = 1; i < ttab.tfill; i++){
		printf("%16s : ", &ttab.names[ttab.types[i].name]);
		switch(ttab.types[i].kind){
			case TK_NIL		: printf("nil\n"); break;
	
			case TK_PI8		: printf("i8 \n"); break;
			case TK_PI16	: printf("i16\n"); break;
			case TK_PI32	: printf("i32\n"); break;
			case TK_PI64	: printf("i64\n"); break;
			case TK_PU8		: printf("u8 \n"); break;
			case TK_PU16	: printf("u16\n"); break;
			case TK_PU32	: printf("u32\n"); break;
			case TK_PU64	: printf("u64\n"); break;
			case TK_PF16	: printf("f16\n"); break;
			case TK_PF32	: printf("f32\n"); break;
			case TK_PF64	: printf("f64\n"); break;
			case TK_PCHR	: printf("chr\n"); break;
	
			case TK_STX		: printf("stx\n"); break;
			case TK_UNI		: printf("uni\n"); break;
			case TK_TAG		: printf("tag\n"); break;
			case TK_ENM		: printf("enm\n"); break;
			case TK_IDX		: printf("idx\n"); break;
			case TK_ARR		: printf("arr\n"); break;
			case TK_PTR		: printf("ptr\n"); break;
			case TK_TAB		: printf("tab\n"); break;
		}
	}
	
}
