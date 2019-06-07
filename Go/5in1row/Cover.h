#if !defined(_Cover_H)
#define Cover_H



#include "AI.h"
#include "Test.h"
#include "Const.h"

#include <windows.h>

void DrawCover(char cover[][Length][Pool], char board[][Length], struct Location loc, int turn);
void ChangeSocreOfLine(char cover[][Length][Pool], char board[][Length], struct Location loc, char Y, char X, char option);

#endif