#if !defined(Tictactoe)
#define Tictactoe

#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>

struct Location
{
    char Y;
    char X;
};

struct Line
{
    char Diag;
    char Subdiag;
    char Line;
    char Row;
};

struct Point
{
    char Count;
    struct Line Black;
    struct Line White;
};

void PrintBoard(char board[][5]);
short ChangeLine(char change, short loc);
short ChangeRow(char change, short loc);
boolean PutChess(char *map, int turn);
struct Point InitCover(struct Point point);
struct Point CountScore(struct Point point);
void DrawCover(struct Point cover[][5], struct Location loc, int turn);
boolean WinCheck(struct Point point, char board, int turn);

#endif