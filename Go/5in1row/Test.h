#if !defined(_Test_)
#define _Test_

#include "Const.h"
#include <windows.h>
#include <stdio.h>

void InitRecord();
void PrintCover(char cover[][_Length_][Pool]);
void EveryStep(char cover[][_Length_][Pool]);
void EveryPoint(char cover[][_Length_][Pool], struct Location loc, int turn);

#endif