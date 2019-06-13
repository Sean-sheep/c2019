#include "Win.h"

boolean WinCheck(unsigned char cover[][_Length][10], struct Location loc, int turn)
{

    if (turn % 2 == 1 && (cover[loc.Y][loc.X][1] >= Score || cover[loc.Y][loc.X][2] >= Score || cover[loc.Y][loc.X][3] >= Score || cover[loc.Y][loc.X][4] >= Score))
    {
        return 0;
    }
    else if (turn % 2 == 0 && (cover[loc.Y][loc.X][5] >= Score || cover[loc.Y][loc.X][6] >= Score || cover[loc.Y][loc.X][7] >= Score || cover[loc.Y][loc.X][8] >= Score))
    {
        return 0;
    }

    return 1;
}
