#ifndef __STRUCT_HEADER__
#define __STRUCT_HEADER__


#include "stdint.h"


typedef enum{
	T_NIL		= 0x00,
	
	T_PI8		= 0x01,
	T_PI16		= 0x02,
	T_PI32		= 0x03,
	T_PI64		= 0x04,
	T_PU8		= 0x05,
	T_PU16		= 0x06,
	T_PU32		= 0x07,
	T_PU64		= 0x08,
	T_PF16		= 0x09,
	T_PF32		= 0x0A,
	T_PF64		= 0x0B,
	T_PCHR		= 0x0C,
	
	T_STX		= 0x40,
	T_UNI		= 0x41,
	T_TAG		= 0x42,
	T_ENM		= 0x43,
	T_IDX		= 0x44,
	T_ARR		= 0x45,
	T_PTR		= 0x46,
	T_TAB		= 0x47
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

typedef enum{
	FK_NIL		= 0,
	FK_TSPEC	= 1,
	FK_BSPEC	= 2,
	FK_BIN		= 3
}FileKind;

typedef struct{
	char*		path;
	uint8_t*	bytes;
	int64_t		size;
	
	FileKind	kind;
	
	Segment*	segs;
	int64_t		sfill, ssize;
}File;


File	initFile	(char*);









#endif
