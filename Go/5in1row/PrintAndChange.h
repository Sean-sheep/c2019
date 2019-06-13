#if !defined(_PrintAndChange_H)
#define PrintAndChange_H

// #include "AI.h"
#include "Const.h"

#include <stdio.h>
#include <windows.h>

void PrintBoard(unsigned char board[][_Length]);
short ChangeLine(unsigned char change, short loc);
short ChangeRow(unsigned char change, short loc);
boolean PutChess(unsigned char *map, int turn);
void ChangeBoard(int turn);

#endif