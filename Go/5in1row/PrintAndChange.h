#if !defined(_PrintAndChange_H)
#define PrintAndChange_H

#include "AI.h"
#include "Const.h"

#include <stdio.h>
#include <windows.h>

void PrintBoard(char board[][_Length]);
short ChangeLine(char change, short loc);
short ChangeRow(char change, short loc);
boolean PutChess(char *map, int turn);

#endif