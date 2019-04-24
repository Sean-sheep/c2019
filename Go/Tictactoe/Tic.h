#if !defined(Tictactoe)
#define Tictactoe

#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>

struct Location
{
    int Y;
    int X;
} loc;

void PrintBoard(char board[][3]);
short ChangeLine(char change, short loc);
short ChangeRow(char change, short loc);
char PutChess(char map, char *turn);

#endif