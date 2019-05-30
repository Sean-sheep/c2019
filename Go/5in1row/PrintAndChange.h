#if !defined(_PrintAndChange_)
#define _PrintAndChange_

#include "AI.h"
#include "Const.h"

#include <stdio.h>
#include <windows.h>

void PrintBoard(char board[][_Length_]);
short ChangeLine(char change, short loc);
short ChangeRow(char change, short loc);
boolean PutChess(char *map, int turn);

#endif