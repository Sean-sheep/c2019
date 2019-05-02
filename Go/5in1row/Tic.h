#if !defined(FiveInARow)
#define FiveInARow

#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#define Height 17
#define Length 17
#define Score 5

struct Location
{
    char Y;
    char X;
};

//Menu
boolean TwoPlayer(char board[][Length], int turn, boolean win, struct Location loc, char cover[][Length][9], COORD coord, HANDLE handle_out);
boolean SinglePlayer(char board[][Length], int turn, boolean win, struct Location loc, char cover[][Length][9], COORD coord, HANDLE handle_out);
//PrintAndChange
void PrintBoard(char board[][Length]);
short ChangeLine(char change, short loc);
short ChangeRow(char change, short loc);
boolean PutChess(char *map, int turn);
//Cover
void DrawCover(char cover[][Length][9], char board[][Length], struct Location loc, int turn);
void ChangeSocreOfLine(char cover[][Length][9], char board[][Length], struct Location loc, char Y, char X, char option);
//Win
boolean WinCheck(char cover[][Length][9], struct Location loc, int turn);
//AI
struct Location AI(char cover[][Length][9], char board[][Length]);
void CountScore(char cover[][Length][9], struct Location loc, int turn);
//Test
void PrintCover(char cover[][Length][9]);
void EveryStep(char cover[][Length][9]);
void EveryPoint(char cover[][Length][9], struct Location loc);

#endif