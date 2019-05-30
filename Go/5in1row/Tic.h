// #if !defined(FiveInARow)
// #define FiveInARow

// #include <stdio.h>
// #include <Windows.h>
// #include <conio.h>
// #include <stdlib.h>
// #include <time.h>

// //Menu
// boolean TwoPlayer(char board[][_Length_], int turn, boolean win, struct Location loc, char cover[][_Length_][Pool], COORD coord, HANDLE handle_out);
// boolean SinglePlayer(char board[][_Length_], int turn, boolean win, struct Location loc, char cover[][_Length_][Pool], COORD coord, HANDLE handle_out);
// //PrintAndChange
// void PrintBoard(char board[][_Length_]);
// short ChangeLine(char change, short loc);
// short ChangeRow(char change, short loc);
// boolean PutChess(char *map, int turn);
// //Cover
// void DrawCover(char cover[][_Length_][Pool], char board[][_Length_], struct Location loc, int turn);
// void ChangeSocreOfLine(char cover[][_Length_][Pool], char board[][_Length_], struct Location loc, char Y, char X, char option);
// //Win
// boolean WinCheck(char cover[][_Length_][Pool], struct Location loc, int turn);
// //AI
// struct Location Decide(char cover[][_Length_][Pool], char board[][_Length_]);
// struct Location AI(char cover[][_Length_][Pool], char board[][_Length_]);
// void CountScore(char cover[][_Length_][Pool], struct Location loc, int option, char board[][_Length_], char dY, char dX);//计算下个点的价值，参数中包括当前点对下个点的相对位置
// //Test
// void InitRecord();
// void PrintCover(char cover[][_Length_][Pool]);
// void EveryStep(char cover[][_Length_][Pool]);
// void EveryPoint(char cover[][_Length_][Pool], struct Location loc, int turn);

// #endif