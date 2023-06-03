#include "stdint.h"
#include "stdlib.h"
#include "stdio.h"

#include "parser.h"



TokenList lex(char* text, int size){
	TokenList ret;

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
