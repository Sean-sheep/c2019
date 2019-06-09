// #if !defined(FiveInARow)
// #define FiveInARow

// #include <stdio.h>
// #include <Windows.h>
// #include <conio.h>
// #include <stdlib.h>
// #include <time.h>

// #define Height 17
// #define _Length 17
// #define Score 5

// struct Location
// {
//     char Y;
//     char X;
// };

// //Menu
// boolean TwoPlayer(char board[][_Length], int turn, boolean win, struct Location loc, char cover[][_Length][10], COORD coord, HANDLE handle_out);
// boolean SinglePlayer(char board[][_Length], int turn, boolean win, struct Location loc, char cover[][_Length][10], COORD coord, HANDLE handle_out);
// //PrintAndChange
// void PrintBoard(char board[][_Length]);
// short ChangeLine(char change, short loc);
// short ChangeRow(char change, short loc);
// boolean PutChess(char *map, int turn);
// //Cover
// void DrawCover(char cover[][_Length][10], char board[][_Length], struct Location loc, int turn);
// void ChangeSocreOfLine(char cover[][_Length][10], char board[][_Length], struct Location loc, char Y, char X, char option);
// //Win
// boolean WinCheck(char cover[][_Length][10], struct Location loc, int turn);
// //AI
// struct Location AI(char cover[][_Length][10], char board[][_Length]);
// void CountScore(char cover[][_Length][10], struct Location loc, int option, char board[][_Length], char dY, char dX);//�����¸���ļ�ֵ�������а�����ǰ����¸�������λ��
// //Test
// void InitRecord();
// void PrintCover(char cover[][_Length][10]);
// void EveryStep(char cover[][_Length][10]);
// void EveryPoint(char cover[][_Length][10], struct Location loc);

// #endif