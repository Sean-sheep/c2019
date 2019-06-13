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
//     unsigned char Y;
//     unsigned char X;
// };

// //Menu
// boolean TwoPlayer(unsigned char board[][_Length], int turn, boolean win, struct Location loc, unsigned char cover[][_Length][10], COORD coord, HANDLE handle_out);
// boolean SinglePlayer(unsigned char board[][_Length], int turn, boolean win, struct Location loc, unsigned char cover[][_Length][10], COORD coord, HANDLE handle_out);
// //PrintAndChange
// void PrintBoard(unsigned char board[][_Length]);
// short ChangeLine(unsigned char change, short loc);
// short ChangeRow(unsigned char change, short loc);
// boolean PutChess(unsigned char *map, int turn);
// //Cover
// void DrawCover(unsigned char cover[][_Length][10], unsigned char board[][_Length], struct Location loc, int turn);
// void ChangeSocreOfLine(unsigned char cover[][_Length][10], unsigned char board[][_Length], struct Location loc, unsigned char Y, unsigned char X, unsigned char option);
// //Win
// boolean WinCheck(unsigned char cover[][_Length][10], struct Location loc, int turn);
// //AI
// struct Location AI(unsigned char cover[][_Length][10], unsigned char board[][_Length]);
// void CountScore(unsigned char cover[][_Length][10], struct Location loc, int option, unsigned char board[][_Length], unsigned char dY, unsigned char dX);//�����¸���ļ�ֵ�������а�����ǰ����¸�������λ��
// //Test
// void InitRecord();
// void PrintCover(unsigned char cover[][_Length][10]);
// void EveryStep(unsigned char cover[][_Length][10]);
// void EveryPoint(unsigned char cover[][_Length][10], struct Location loc);

// #endif