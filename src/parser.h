#ifndef __PARSER_HEADER__
#define __PARSER_HEADER__


#include "stdint.h"



typedef enum{
	TK_NIL		= 0,
	TK_OPN_PAR	= 1,
	TK_END_PAR	= 2,
	TK_OPN_BRK	= 3,
	TK_END_BRK	= 4,
	TK_OPN_BRC	= 5,
	TK_END_BRC	= 6,
	
	TK_ID		= 32,
	TK_TYID		= 33,
	
	TK_K_STRX	= 64,
	TK_K_UNON	= 65,
	TK_K_TAGU	= 66,
	TK_K_ENUM	= 67,
	
	TK_COLON	= 96
}TokenKind;

typedef struct{
	TokenKind	kind;
	int			pos, size;
}Token;

typedef struct{
	Token*		tks;
	int			fill, size;
}TokenList;


TokenList	lex		(char*, int);
int			findTok	(TokenList, TokenKind, int);

int			pairPar	(TokenList, int);
int			pairBrk	(TokenList, int);
int			pairBrc	(TokenList, int);



#endif
