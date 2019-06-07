#if !defined(_Test_H)
#define Test_H

#include "Const.h"
#include <windows.h>
#include <stdio.h>

void InitRecord();
void PrintCover(char cover[][Length][Pool]);
void EveryStep(char cover[][Length][Pool]);
void EveryPoint(char cover[][Length][Pool], struct Location loc, int turn);

#endif