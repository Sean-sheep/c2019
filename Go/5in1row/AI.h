#if !defined(_AI_H)
#define AI_H

#include "Const.h"

#include <stdio.h>
#include <Windows.h>

struct Location Decide(char cover[][_Length][Pool], char board[][_Length]);
struct Location AI(char cover[][_Length][Pool], char board[][_Length], int turn);
char CountScore(char cover[][_Length][Pool], struct Location loc, int option, char board[][_Length], char dY, char dX);//计算下个点的价值，参数中包括当前点对下个点的相对位置,返回白子对黑子的价值差

#endif