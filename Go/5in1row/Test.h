#if !defined(_Test_H)
#define Test_H

#include "Const.h"
#include <windows.h>
#include <stdio.h>

void InitRecord();
void PrintCover(int cover[][_Length][10]);
void EveryStep(int cover[][_Length][10],int board[][_Length]);
void EveryPoint(int cover[][_Length][10], struct Location loc, int turn);
void CountIncome(struct Location loc, int benefit, int turn);

#endif