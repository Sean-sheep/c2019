#if !defined(_PrintAndChange_H)
#define PrintAndChange_H

// #include "AI.h"
#include "Const.h"

#include <stdio.h>
#include <windows.h>

void PrintBoard(int board[][_Length]);
short ChangeLine(int change, short loc);
short ChangeRow(int change, short loc);
boolean PutChess(int *map, int turn);
void ChangeBoard(int turn);

#endif