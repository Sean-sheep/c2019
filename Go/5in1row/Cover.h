#if !defined(_Cover_H)
#define Cover_H



#include "AI.h"
#include "Test.h"
#include "Const.h"

#include <windows.h>

int DrawCover(char cover[][_Length][Pool], char board[][_Length], struct Location loc, int turn);
char ChangeSocreOfLine(char cover[][_Length][Pool], char board[][_Length], struct Location loc, char Y, char X, char option); //继续向外传递CountScore返回的差

#endif