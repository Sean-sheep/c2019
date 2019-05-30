#if !defined(_Cover_)
#define _Cover_



#include "AI.h"
#include "Test.h"
#include "Const.h"

#include <windows.h>

void DrawCover(char cover[][_Length_][Pool], char board[][_Length_], struct Location loc, int turn);
void ChangeSocreOfLine(char cover[][_Length_][Pool], char board[][_Length_], struct Location loc, char Y, char X, char option);

#endif