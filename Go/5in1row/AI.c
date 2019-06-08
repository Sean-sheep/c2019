#include "AI.h"

struct Location AI(char cover[][_Length][Pool], char board[][_Length], int turn)
{
    int t = 0, value = 1;
    struct Location set[100];

    for (size_t i = 1; i < Height - 1; i++)
    {
        for (size_t j = 1; j < _Length - 1; j++)
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
    // printf("%d", t);
    return set[t];
}

char CountScore(char cover[][_Length][Pool], struct Location loc, int option, char board[][_Length], char dY, char dX)
{
    // for (size_t i = 1; i < _Length; i++)
    // {
    //     for (size_t t = 1; t < Height; t++)
    //     {
    //         cover[i][t][0] -= (cover[i][t][0] > 0);
    //     }
    // }

    cover[loc.Y][loc.X][Pool] = cover[loc.Y][loc.X][0] = 0;
    for (size_t i = 1; i < 9; i++)
    {
        switch (cover[loc.Y][loc.X][i])
        {
        case 2:
            if (board[loc.Y + dY][loc.X + dX] > 0 && board[loc.Y + dY][loc.X + dX] < 10) //前面不是死胡同
            {
                cover[loc.Y][loc.X][0] += cover[loc.Y][loc.X][i];
                cover[loc.Y][loc.X][Pool] += cover[loc.Y][loc.X][i];
            }
            else
            {
                ++cover[loc.Y][loc.X][0];
                ++cover[loc.Y][loc.X][Pool];
            }

            break;

        case 3:
            if (board[loc.Y + dY][loc.X + dX] > 0 && board[loc.Y + dY][loc.X + dX] < 10) //前面不是死胡同
            {
                if (board[loc.Y - 4 * dY][loc.X - 4 * dX] > 0 && board[loc.Y - 4 * dY][loc.X - 4 * dX] < 10 && (dX * 2 + dY) >= 0) //双活三
                {
                    if ((option - 1) / 4) //5~8为黑，1~4为白
                    {
                        cover[loc.Y][loc.X][0] += cover[loc.Y][loc.X][i] * 2;
                        cover[loc.Y][loc.X][Pool] += cover[loc.Y][loc.X][i] * 3;
                    }
                    else
                    {
                        cover[loc.Y][loc.X][0] += cover[loc.Y][loc.X][i] * 3;
                        cover[loc.Y][loc.X][Pool] += cover[loc.Y][loc.X][i] * 2;
                    }
                }
                else //单活三
                {
                    if ((option - 1) / 4) //5~8为黑，1~4为白
                    {
                        cover[loc.Y][loc.X][0] += cover[loc.Y][loc.X][i] * 2;
                        cover[loc.Y][loc.X][Pool] += cover[loc.Y][loc.X][i];
                    }
                    else
                    {
                        cover[loc.Y][loc.X][0] += cover[loc.Y][loc.X][i];
                        cover[loc.Y][loc.X][Pool] += cover[loc.Y][loc.X][i] * 2;
                    }
                }

                // if (board[loc.Y - 4 * dY][loc.X - 4 * dX] > 0 && board[loc.Y - 4 * dY][loc.X - 4 * dX] < 10 && (dX * 2 + dY) >= 0) //双活三的一侧
                // {
                //     if ((option - 1) / 4) //5~8为黑，1~4为白
                //     {
                //         cover[loc.Y][loc.X][0] += cover[loc.Y][loc.X][i] * 2;
                //     }
                //     else
                //     {
                //         cover[loc.Y][loc.X][0] += cover[loc.Y][loc.X][i] * 3;
                //     }
                // }
                // else //双活三的另一侧
                // {
                //     if ((option - 1) / 4) //5~8为黑，1~4为白
                //     {
                //         cover[loc.Y][loc.X][0] += cover[loc.Y][loc.X][i] * 2;
                //     }
                //     else
                //     {
                //         cover[loc.Y][loc.X][0] += cover[loc.Y][loc.X][i];
                //     }
                // }
            }
            else
            {
                cover[loc.Y][loc.X][0] += cover[loc.Y][loc.X][i];
                cover[loc.Y][loc.X][Pool] += cover[loc.Y][loc.X][i];
            }
            break;

        case 4:
            if ((option - 1) / 4) //5~8为黑，1~4为白
            {
                cover[loc.Y][loc.X][0] += cover[loc.Y][loc.X][i] * 3;
                cover[loc.Y][loc.X][Pool] += cover[loc.Y][loc.X][i] * 4;
            }
            else
            {
                cover[loc.Y][loc.X][0] += cover[loc.Y][loc.X][i] * 4;
                cover[loc.Y][loc.X][Pool] += cover[loc.Y][loc.X][i] * 3;
            }
            break;

        default:
            break;
        }
    }
    cover[loc.Y][loc.X][0] += (cover[loc.Y][loc.X][0] <= 0);
    cover[loc.Y][loc.X][Pool] += (cover[loc.Y][loc.X][Pool] <= 0);
    // cover[loc.Y][loc.X][0] *= 3;

    return cover[loc.Y][loc.X][0] - cover[loc.Y][loc.X][Pool];
}
