#include "Tic.h"

boolean WinCheck(char cover[][Length][9], struct Location loc, int turn)
{
    if (cover[loc.Y][loc.X][1] >= Score || cover[loc.Y][loc.X][2] >= Score || cover[loc.Y][loc.X][3] >= Score || cover[loc.Y][loc.X][4] >= Score || cover[loc.Y][loc.X][5] >= Score || cover[loc.Y][loc.X][6] >= Score || cover[loc.Y][loc.X][7] >= Score || cover[loc.Y][loc.X][8] >= 3)
    {
        return 0;
    }
    return 1;
}