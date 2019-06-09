#if !defined(_Cover_H)
#define Cover_H

// #include "AI.h"
#include "Test.h"
#include "Const.h"

#include <stdio.h>
#include <windows.h>

struct Location AI(int cover[][_Length][10], int board[][_Length], int turn);
int Decide(int cover[][_Length][10], int board[][_Length], struct Location *ansP, int extro);
int Point(int cover[][_Length][10], int board[][_Length], struct Location loc[]);

//计算下个点的价值，参数中包括当前点对下个点的相对位置,返回白分对黑分之差
int CountScore(int cover[][_Length][10], struct Location loc, int option, int board[][_Length], int dY, int dX);

//返回八方差值之和
int DrawCover(int cover[][_Length][10], int board[][_Length], struct Location loc, int turn);

//继续向外传递CountScore返回的差值
int ChangeSocreOfLine(int cover[][_Length][10], int board[][_Length], struct Location loc, int Y, int X, int option);

#endif