#ifndef __STRUCT_HEADER__
#define __STRUCT_HEADER__


#include "stdint.h"


typedef enum{
	TK_NIL		= 0x00,
	
	TK_PI8		= 0x01,
	TK_PI16		= 0x02,
	TK_PI32		= 0x03,
	TK_PI64		= 0x04,
	TK_PU8		= 0x05,
	TK_PU16		= 0x06,
	TK_PU32		= 0x07,
	TK_PU64		= 0x08,
	TK_PF16		= 0x09,
	TK_PF32		= 0x0A,
	TK_PF64		= 0x0B,
	TK_PCHR		= 0x0C,
	
	TK_STX		= 0x40,
	TK_UNI		= 0x41,
	TK_TAG		= 0x42,
	TK_ENM		= 0x43,
	TK_IDX		= 0x44,
	TK_ARR		= 0x45,
	TK_PTR		= 0x46,
	TK_TAB		= 0x47
}TypeKind;

typedef struct{
	void*		bytes;
	uint32_t	type;
	uint64_t	size;
}TypeArr;

typedef struct{
	uint32_t	type;
}TypeIdx;

typedef struct{
	uint32_t*	fields;
	uint32_t*	types;
	int			size;
}TypeStruct;

typedef struct{
	uint32_t*	fields;
	uint32_t*	types;
	int			size;
}TypeUnion;

typedef struct{
	uint64_t*	tags;
	uint32_t*	fields;
	uint32_t*	types;
	int			size, tagsize;
}TypeTags;



typedef struct{
	TypeKind		kind;
	uint32_t		name;
	union{
		uint64_t	prim;
		TypeArr		arr;
		TypeIdx		idx;
		TypeStruct	stx;
		TypeUnion	uni;
		TypeTags	tag;
	};
}Type;


typedef struct{
	Type*		types;
	char*		names;
	int			tfill, tsize;
	int			nfill, nsize;
}TypeTable;



typedef struct{
	uint64_t	index, size, type;
}Segment;

typedef struct{
	char*		path;
	uint8_t*	bytes;
	int64_t		size;
	
	Segment*	segs;
	int64_t		sfill, ssize;
}File;


File	initFile	(char*);









#endif
