#if !defined(_AI_H)
#define AI_H

#include "Test.h"
#include "Const.h"
#include "Cover.h"

#include <stdio.h>

//输出决策结果
struct Location AI(unsigned char cover[][_Length][10], unsigned char board[][_Length], int turn);

//决策树循环节
struct Vertex Decide(struct Limit lmt, unsigned char cover[][_Length][10], unsigned char board[][_Length], int found, unsigned char extro);

//寻找高价值点储存在接受的坐标组中并统计个数t(<=20)
unsigned char findPoints(unsigned char cover[][_Length][10], unsigned char board[][_Length], struct Location loc[]);

#endif