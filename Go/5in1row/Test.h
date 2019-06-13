#if !defined(_Test_H)
#define Test_H

#include "Const.h"
#include <windows.h>
#include <stdio.h>

void InitRecord();
void PrintCover(unsigned char cover[][_Length][10]);
void EveryStep(unsigned char cover[][_Length][10],unsigned char board[][_Length]);
void EveryPoint(unsigned char cover[][_Length][10], struct Location loc, int turn);
void CountIncome(struct Location loc, int benefit, int turn);

#endif