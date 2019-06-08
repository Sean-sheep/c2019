#if !defined(_Test_H)
#define Test_H

#include "Const.h"
#include <windows.h>
#include <stdio.h>

void InitRecord();
void PrintCover(char cover[][_Length][Pool]);
void EveryStep(char cover[][_Length][Pool]);
void EveryPoint(char cover[][_Length][Pool], struct Location loc, int turn);

#endif