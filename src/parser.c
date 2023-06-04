#include "stdint.h"
#include "stdlib.h"
#include "stdio.h"

#include "parser.h"


TokenList makeTokenList(int size){
	TokenList ret;
	ret.tks  = malloc(sizeof(Token) * size);
	ret.fill = 0;
	ret.size = size;
	return ret;
}

int insertToken(TokenList* tl, Token t){
	if(tl->fill+5 >= tl->size){
		Token* tmp = tl->tks;
		tl->size  *= 2;
		tl->tks    = malloc(sizeof(Token) * tl->size);
		for(int i  = 0; i < tl->fill; i++)  tl->tks[i] = tmp[i];
		free(tmp);
	}
	tl->tks[tl->fill] = t;
	tl->fill++;
	return tl->fill-1;
}


TokenList lex(char* text, int size){
	TokenList ret;
	char last = 0;
	int  head = 0;
	for(int i = 0; i < size; i++){
		
	}
	return ret;
}


int findPar(TokenList tl, TokenKind k, int start){
	for(int i = start; i < tl.fill; i++)
		if(tl.tks[i].kind == k) return i;
	return -1;
}

int pairPar(TokenList tl, int start){
	int depth = 0;
	for(int i = start; i < tl.fill; i++){
		if      (tl.tks[i].kind == TK_OPN_PAR){
			depth++;
		}else if(tl.tks[i].kind == TK_END_PAR){
			depth--;
		}
		if(depth < 0) return i;
	}
	return -1;
}


int pairBrk(TokenList tl, int start){
	int depth = 0;
	for(int i = start; i < tl.fill; i++){
		if      (tl.tks[i].kind == TK_OPN_BRK){
			depth++;
		}else if(tl.tks[i].kind == TK_END_BRK){
			depth--;
		}
		if(depth < 0) return i;
	}
	return -1;
}


int pairBrc(TokenList tl, int start){
	int depth = 0;
	for(int i = start; i < tl.fill; i++){
		if      (tl.tks[i].kind == TK_OPN_BRC){
			depth++;
		}else if(tl.tks[i].kind == TK_END_BRC){
			depth--;
		}
		if(depth < 0) return i;
	}
	return -1;
}
