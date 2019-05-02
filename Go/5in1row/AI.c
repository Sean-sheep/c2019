#include "Tic.h"

struct Location AI(char cover[][Length][9], char board[][Length])
{
    int t = 0, value = 1;
    struct Location set[100];

    for (size_t i = 1; i < Height - 1; i++)
    {
        for (size_t j = 1; j < Length - 1; j++)
        {
            if (board[i][j] > 0 && board[i][j] < 10 && cover[i][j][0] >= value)
            {
                value = cover[i][j][0];
                set[t].Y = i;
                set[t].X = j;
                ++t;
            }
        }
    }
    t = (rand() % t);
    printf("%d", t);
    return set[t];
}

void
CountScore(char cover[][Length][9], struct Location loc, int turn)
{
    int Y = 0, X = 0;
    turn *= -4;
    /*
    for (size_t i = 1; i < 9; i++)
    {
        if (cover[loc.Y][loc.X][0] < cover[loc.Y][loc.X][i])
        {
        cover[loc.Y][loc.X][0] = cover[loc.Y][loc.X][i];
        }
    }
    */
    for (size_t i = 0; i < 4; i++)
    {
        Y = i / 3 - 1;
        X = i % 3 - 1;
        if (cover[loc.Y][loc.X][i + 5 + turn] > 1 || cover[loc.Y + Y][loc.X + X][0] < 1)
        {
            cover[loc.Y + Y][loc.X + X][0] += cover[loc.Y][loc.X][i + 5 + turn];
        }
        if (cover[loc.Y][loc.X][i + 5 + turn] > 1 || cover[loc.Y - Y][loc.X - X][0] < 1)
        {
            cover[loc.Y - Y][loc.X - X][0] += cover[loc.Y][loc.X][i + 5 + turn];
        }
        EveryStep(cover); //Test
    }
}
