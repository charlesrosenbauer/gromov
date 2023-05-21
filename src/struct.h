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
	TK_PTR		= 0x46
	
}TypeKind;



#endif
