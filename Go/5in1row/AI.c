#include "AI.h"

struct Location AI(unsigned char cover[][_Length][10], unsigned char board[][_Length], int turn)
{
    struct Location ans;
    struct Vertex vert;
    struct Limit lmt = {-100000000, 100000000};
    unsigned char Subcover[Height][_Length][10] = {0}, Suboard[Height][_Length] = {0};
    memcpy(Suboard, board, sizeof(Suboard));
    memcpy(Subcover, cover, sizeof(Subcover));
    vert = Decide(lmt, Subcover, Suboard, 0, 1);
    ans.Y = vert.Y;
    ans.X = vert.X;
    return ans;
}

struct Vertex
Decide(struct Limit lmt, unsigned char cover[][_Length][10], unsigned char board[][_Length], int found, unsigned char extro)
{
    unsigned char Subcover[Height][_Length][10] = {0}, Suboard[Height][_Length] = {0};
    struct Location loc[Pool];
    struct Vertex vert = {0};
    int value = 0, profit = 0;

    if (extro % 2) //逢单白子,取最大值
    {
        lmt.maximum = -200000000;
        for (size_t i = 0; i < findPoints(cover, board, loc); i++)
        {
            memcpy(Suboard, board, sizeof(Suboard));
            memcpy(Subcover, cover, sizeof(Subcover));
            Suboard[loc[i].Y][loc[i].X] = 'W';
            profit = DrawCover(Subcover, Suboard, loc[i], extro);
            if (!WinCheck(Subcover, loc[i], extro))
            {
                vert.value = 1000000000;
                vert.Y = loc[i].Y;
                vert.X = loc[i].X;
                break;
            }
            value = Decide(lmt, Subcover, Suboard, found + profit, extro + 1).value;
            // CountIncome(loc[i], value, extro, lmt.minimum);
            if (value > lmt.minimum)
            {
                vert.value = value;
                vert.Y = loc[i].Y;
                vert.X = loc[i].X;
                break;
            }
            if (value > lmt.maximum)
            {
                lmt.maximum = vert.value = value;
                vert.Y = loc[i].Y;
                vert.X = loc[i].X;
            }
        }
    }
    else
    {
        lmt.minimum = 200000000;
        for (size_t i = 0; i < findPoints(cover, board, loc); i++)
        {
            memcpy(Suboard, board, sizeof(Suboard));
            memcpy(Subcover, cover, sizeof(Subcover));
            Suboard[loc[i].Y][loc[i].X] = 'B';
            profit = DrawCover(Subcover, Suboard, loc[i], extro);
            if (!WinCheck(Subcover, loc[i], extro))
            {
                vert.value = -1000000000;
                vert.Y = loc[i].Y;
                vert.X = loc[i].X;
                break;
            }
            if (extro / 2 == Deep) //黑子收尾
            {
                value = found + profit;
            }
            else
            {
                value = Decide(lmt, Subcover, Suboard, found + profit, extro + 1).value;
            }
            // CountIncome(loc[i], value, extro, lmt.maximum);
            if (value < lmt.maximum)
            {
                vert.value = value;
                vert.Y = loc[i].Y;
                vert.X = loc[i].X;
                break;
            }
            if (value < lmt.minimum)
            {
                lmt.minimum = vert.value = value;
                vert.Y = loc[i].Y;
                vert.X = loc[i].X;
            }
        }
    }
    if (!vert.X && !vert.Y)
    {
        vert.value = value;
        vert.Y = loc[0].Y;
        vert.X = loc[0].X;
    }
    // CountDiced(vert, vert.value, extro);
    return vert;
}

unsigned char findPoints(unsigned char cover[][_Length][10], unsigned char board[][_Length], struct Location loc[])
{
    unsigned char t = 0, sum = 0;
    struct Vertex verts[Pool] = {0}, vert;

    for (size_t i = 1; i < Height - 1; i++)
    {
        for (size_t j = 1; j < _Length - 1; j++)
        {
            vert.value = cover[i][j][0] + cover[i][j][9];
            if (vert.value > verts[0].value && 0 < board[i][j] && board[i][j] < 10)
            {
                vert.Y = i;
                vert.X = j;

                for (size_t k = Pool; k > 0; k--)
                {
                    t = Pool + 1 - k;
                    if (vert.value > verts[k - 1].value)
                    {
                        if (verts[k - 1].value == 0)
                        {
                            verts[k - 1] = vert;
                            break;
                        }
                        struct Vertex temp = vert;
                        vert = verts[k - 1];
                        verts[k - 1] = temp;
                    }
                }
            }
        }
    }
    for (size_t i = 0; i < t; i++)
    {
        loc[i].Y = verts[Pool - 1 - i].Y;
        loc[i].X = verts[Pool - 1 - i].X;
    }
    return t;
}