#if !defined(Tictactoe)
#define Tictactoe

#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>

#define Height 17
#define Length 17
#define Score 5

struct Location
{
    char Y;
    char X;
};

void PrintBoard(char board[][Length]);
short ChangeLine(char change, short loc);
short ChangeRow(char change, short loc);
boolean PutChess(char *map, int turn);
void CountScore(char cover[][Length][9], struct Location loc);
void DrawCover(char cover[][Length][9], char board[][Length], struct Location loc, int turn);
boolean WinCheck(char cover[][Length][9], struct Location loc, int turn);
void ChangeSocreOfLine(char cover[][Length][9], char board[][Length], struct Location loc, char Y, char X, char option);

#endif