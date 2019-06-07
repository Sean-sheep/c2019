#if !defined(_Menu_H)
#define Menu_H

#include "AI.h"
#include "Win.h"
#include "Const.h"
#include "Cover.h"
#include "PrintAndChange.h"

#include <time.h>
#include <conio.h>
#include <windows.h>

boolean TwoPlayer(char board[][Length], int turn, boolean win, struct Location loc, char cover[][Length][Pool], COORD coord, HANDLE handle_out);
boolean SinglePlayer(char board[][Length], int turn, boolean win, struct Location loc, char cover[][Length][Pool], COORD coord, HANDLE handle_out);

#endif