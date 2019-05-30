#if !defined(_Menu_)
#define _Menu_

#include "AI.h"
#include "Win.h"
#include "Const.h"
#include "Cover.h"
#include "PrintAndChange.h"

#include <time.h>
#include <conio.h>
#include <windows.h>

boolean TwoPlayer(char board[][_Length_], int turn, boolean win, struct Location loc, char cover[][_Length_][Pool], COORD coord, HANDLE handle_out);
boolean SinglePlayer(char board[][_Length_], int turn, boolean win, struct Location loc, char cover[][_Length_][Pool], COORD coord, HANDLE handle_out);

#endif