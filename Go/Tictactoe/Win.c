#include "Tic.h"

boolean WinCheck(char cover[][Length][Pool], struct Location loc, int turn)
{
    if (cover[loc.Y][loc.X][1] >= 3 || cover[loc.Y][loc.X][2] >= 3 || cover[loc.Y][loc.X][3] >= 3 || cover[loc.Y][loc.X][4] >= 3 || cover[loc.Y][loc.X][5] >= 3 || cover[loc.Y][loc.X][6] >= 3 || cover[loc.Y][loc.X][7] >= 3 || cover[loc.Y][loc.X][8] >= 3)
    {
        return 0;
    }
    return 1;
}
