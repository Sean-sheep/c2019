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
                if (cover[i][j][0] > value)
                {
                    value = cover[i][j][0];
                    t = 0;
                }
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
CountScore(char cover[][Length][9], struct Location loc, int option, char board[][Length], char dY, char dX)
{
    cover[loc.Y][loc.X][0] = 0;
    for (size_t i = 1; i < 9; i++)
    {
        switch (cover[loc.Y][loc.X][i])
        {
        case 2:
            cover[loc.Y][loc.X][0] += cover[loc.Y][loc.X][i];
            break;

        case 3:
            if (board[loc.Y + 4 * dY][loc.X + 4 * dX] > 0 && board[loc.Y + 4 * dY][loc.X + 4 * dX] < 10 && (dX * 2 + dY) >= 0)
            {
                if ((option - 1) / 4) //5~8Ϊ�ڣ�1~4Ϊ��
                {
                    cover[loc.Y][loc.X][0] += cover[loc.Y][loc.X][i] * 3;
                }
                else
                {
                    cover[loc.Y][loc.X][0] += cover[loc.Y][loc.X][i] * 2;
                }
            }
            else
            {
                cover[loc.Y][loc.X][0] += cover[loc.Y][loc.X][i];
            }
            break;

        case 4:
            if ((option - 1) / 4) //5~8Ϊ�ڣ�1~4Ϊ��
            {
                cover[loc.Y][loc.X][0] += cover[loc.Y][loc.X][i] * 4;
            }
            else
            {
                cover[loc.Y][loc.X][0] += cover[loc.Y][loc.X][i] * 3;
            }
            break;

        default:
            break;
        }
    }
    if (cover[loc.Y][loc.X][0] == 0)
    {
        ++cover[loc.Y][loc.X][0];
    }
}
