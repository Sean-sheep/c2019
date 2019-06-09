#if !defined(_Menu_H)
#define Menu_H

// #include "AI.h"
#include "Win.h"
#include "Test.h"
#include "Const.h"
#include "Cover.h"
#include "PrintAndChange.h"

#include <time.h>
#include <conio.h>
#include <windows.h>

boolean TwoPlayer(int board[][_Length], int turn, boolean win, struct Location loc, int cover[][_Length][10], COORD coord, HANDLE handle_out);
boolean SinglePlayer(int board[][_Length], int turn, boolean win, struct Location loc, int cover[][_Length][10], COORD coord, HANDLE handle_out);

#endif