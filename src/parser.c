#include "string.h"
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
	TokenList ret = makeTokenList(size);
	char last = 0;
	int  head = 0;
	for(int i = 0; i < size; i++){
		char here = text[i];
		if(here <= ' '){
			// whitespace
			if(last > ' '){
				TokenKind k = TK_ID;
				if((text[head] >= 'A') && (text[head] <= 'Z')) k = TK_TYID;
				if( text[head] == 'G'){
					k = (strncmp(&text[head], "GROMOV", 6))? k : TK_K_GROMOV;
				}else if(text[head] == 's'){
					k = (strncmp(&text[head], "struct", 6))? k : TK_K_STRX;
				}else if(text[head] == 'u'){
					k = (strncmp(&text[head], "union" , 5))? k : TK_K_UNON;
				}else if(text[head] == 't'){
					k = (strncmp(&text[head], "tagged", 6))? k : TK_K_TAGU;
				}else if(text[head] == 'e'){
					k = (strncmp(&text[head], "enum"  , 4))? k : TK_K_ENUM;
				}
				
				insertToken(&ret, (Token){k, here, i-head});
			}
			head = i+1;
			last = 0;
		}else{
			int match = 1;
			switch(here){
				case '{' : { insertToken(&ret, (Token){TK_OPN_BRC, i, 1}); head = i+1; } break;
				case '}' : { insertToken(&ret, (Token){TK_END_BRC, i, 1}); head = i+1; } break;
				case '(' : { insertToken(&ret, (Token){TK_OPN_PAR, i, 1}); head = i+1; } break;
				case ')' : { insertToken(&ret, (Token){TK_END_PAR, i, 1}); head = i+1; } break;
				case '[' : { insertToken(&ret, (Token){TK_OPN_BRK, i, 1}); head = i+1; } break;
				case ']' : { insertToken(&ret, (Token){TK_END_BRK, i, 1}); head = i+1; } break;
				case ':' : { insertToken(&ret, (Token){TK_COLON  , i, 1}); head = i+1; } break;
				default  : match = 0;
			}
			if(!match){
				last = text[i];
			}
		}
	}
	return ret;
}


void printTokenList(TokenList tl){
	for(int i = 0; i < tl.fill; i++){
		Token t = tl.tks[i];
		char* str;
		switch(t.kind){
			case TK_NIL		: str = "nil    "; break;
			case TK_OPN_PAR	: str = " (     "; break;
			case TK_END_PAR : str = " )     "; break;
			case TK_OPN_BRK	: str = " [     "; break;
			case TK_END_BRK : str = " ]     "; break;
			case TK_OPN_BRC	: str = " {     "; break;
			case TK_END_BRC : str = " }     "; break;
			
			case TK_ID		: str = "id     "; break;
			case TK_TYID	: str = "tyid   "; break;
			
			case TK_K_GROMOV: str = "gromov "; break;
			case TK_K_STRX	: str = "struct "; break;
			case TK_K_UNON	: str = "union  "; break;
			case TK_K_TAGU	: str = "tagged "; break;
			case TK_K_ENUM	: str = "enum   "; break;
			
			case TK_COLON	: str = " :     "; break;
			default			: str = " ???   "; break;
		}
		printf("%4i | %8s %4i %4i\n", i, str, t.pos, t.size);
	}
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
