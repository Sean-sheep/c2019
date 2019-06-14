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

    // if (extro / 2 == Deep) //黑子收尾
    // {
    //     lmt.minimum = 100000000;
    //     for (size_t i = 0; i < t; i++)
    //     {
    //         memcpy(Suboard, board, sizeof(Suboard));
    //         memcpy(Subcover, cover, sizeof(Subcover));
    //         Suboard[loc[i].Y][loc[i].X] = 'B';
    //         profit = DrawCover(Subcover, Suboard, loc[i], extro);
    //         if (!WinCheck(Subcover, loc[i], extro))
    //         {
    //             vert.value = -1000000000;
    //             vert.Y = loc[i].Y;
    //             vert.X = loc[i].X;
    //             break;
    //         }
    //         value = found + profit;
    //         CountIncome(loc[i], value, extro, lmt.maximum);
    //         if (value < lmt.maximum)
    //         {
    //             vert.value = value;
    //             vert.Y = loc[i].Y;
    //             vert.X = loc[i].X;
    //             break;
    //         }
    //         if (value < lmt.minimum)
    //         {
    //             lmt.minimum = vert.value = value;
    //             vert.Y = loc[i].Y;
    //             vert.X = loc[i].X;
    //         }
    //     }

    //     CountDiced(vert, vert.value, extro);

    //     return vert;
    // }
    if (extro % 2) //逢单白子，取最大值
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
            CountIncome(loc[i], value, extro, lmt.minimum);
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
            CountIncome(loc[i], value, extro, lmt.maximum);
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

    CountDiced(vert, vert.value, extro);

    return vert;
}

// int
// Decide(unsigned char cover[][_Length][10], unsigned char board[][_Length], struct Location *ansP, unsigned char extro)
// {
//     // if (extro != 1)
//     // {
//     //     for (size_t i = 1; i < Height - 1; i++)
//     //     {
//     //         for (size_t j = 1; j < _Length - 1; j++)
//     //         {
//     //             if (extro % 2)
//     //             {
//     //                 for (size_t k = 1; k < 5; k++)
//     //                 {
//     //                     if (cover[i][j][k] > 4)
//     //                     {
//     //                         return 10000;
//     //                     }
//     //                 }
//     //             }
//     //             else
//     //             {
//     //                 for (size_t k = 5; k < 9; k++)
//     //                 {
//     //                     if (cover[i][j][k] > 4)
//     //                     {
//     //                         return 10000;
//     //                     }
//     //                 }
//     //             }
//     //         }
//     //     }
//     // }

//     int value = 1, rslt = 0;

//     if (extro / 2 == Deep)
//     {
//         struct Location loc;

//         for (size_t i = 1; i < Height - 1; i++)
//         {
//             for (size_t j = 1; j < _Length - 1; j++)
//             {
//                 if (board[i][j] > 0 && board[i][j] < 10 && cover[i][j][0] >= value)
//                 {
//                     value = cover[i][j][0];
//                     // for (size_t k = 5 - (extro % 2) * 4; k < 9 - (extro % 2) * 4; k++)
//                     // {
//                     //     if (cover[i][j][k] > 3)
//                     //     {
//                     //         value = 1000;
//                     //     }
//                     // }
//                     loc.Y = i;
//                     loc.X = j;
//                 }
//             }
//         }
//         CountIncome(loc, value, extro);
//     }
//     else
//     {
//         value = -10000;
//         struct Location loc[Pool];
//         struct Node ans;
//         unsigned char Subcover[Height][_Length][10] = {0}, Suboard[Height][_Length] = {0};

//         for (size_t i = 0; i < findPoints(cover, board, loc); i++)
//         {
//             // value = max(value, cover[loc[i].Y][loc[i].X][0]);
//             memcpy(Suboard, board, sizeof(Suboard));
//             memcpy(Subcover, cover, sizeof(Subcover));
//             Suboard[loc[i].Y][loc[i].X] = (extro % 2) ? 'W' : 'B';
//             DrawCover(Subcover, Suboard, loc[i], extro);
//             // value = max(value, cover[loc[i].Y][loc[i].X][0] - Decide(Subcover, Suboard, extro + 1));
//             rslt = cover[loc[i].Y][loc[i].X][0] - Decide(Subcover, Suboard, ansP, extro + 1);

//             CountIncome(loc[i], rslt, extro);

//             if (rslt > value)
//             {
//                 value = rslt;
//                 // for (size_t k = 5 - (extro % 2) * 4; k < 9 - (extro % 2) * 4; k++)
//                 // {
//                 //     if (cover[loc[i].Y][loc[i].X][k] > 3)
//                 //     {
//                 //         value = 1000;
//                 //     }
//                 // }
//                 if (extro == 1)
//                 {
//                     *ansP = loc[i];
//                 }
//             }
//         }
//     }
//     return value;
// }

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

    // // 我爱重构，真的，不骗人
    // // char t = 0, value = 1;
    // unsigned char t = 0, sum = 0, values[Pool + 1] = {255};
    // values[Pool] = 1;

    // for (size_t i = 1; i < Height - 1; i++)
    // {
    //     for (size_t j = 1; j < _Length - 1; j++)
    //     {
    //         sum = cover[i][j][0] + cover[i][j][9];
    //         if (board[i][j] > 0 && board[i][j] < 10 && sum >= values[Pool])
    //         {
    //             for (size_t k = Pool - 1; k >= 0; k--)
    //             {
    //                 if (sum <= values[k]) //如果小于等于就把值赋给后项
    //                 {
    //                     values[k + 1] = sum;
    //                     t = max(t, k + 1);
    //                     loc[k].Y = i;
    //                     loc[k].X = j;
    //                     break;
    //                 }
    //             }
    //         }

    //         if (board[i][j] > 0 && board[i][j] < 10 && cover[i][j][0] + cover[i][j][9] >= (value + 1) / 2)
    //         {
    //             if (cover[i][j][0] + cover[i][j][9] > value)
    //             {
    //                 value = cover[i][j][0] + cover[i][j][9];
    //                 t = 0;
    //             }
    //             loc[t].Y = i;
    //             loc[t].X = j;
    //             t = (t + 1) % Pool;
    //             // t = (t == (Pool - 1)) ? 0 : t + 1;
    //             // value = max(value, cover[i][j][0]);
    //         }
    //     }
    // }
    // return t;
}
// struct Location AI(int cover[][_Length][10], int board[][_Length], int turn)
// {
//     int t = 0, value = 1;
//     // struct Location altLoc[Pool];
//     struct Location altLoc[Pool], loc[Pool];
//     int Subcover[Height][_Length][10] = {0}, Suboard[Height][_Length] = {0};

//     for (size_t i = 1; i < Height - 1; i++)
//     {
//         for (size_t j = 1; j < _Length - 1; j++)
//         {
//             if (board[i][j] > 0 && board[i][j] < 10 && cover[i][j][0] >= value)
//             {
//                 if (cover[i][j][0] > value)
//                 {
//                     t = 0;
//                     value = cover[i][j][0];
//                 }
//                 altLoc[t].Y = i;
//                 altLoc[t].X = j;
//                 t = (t == Pool - 1) ? 0 : t + 1;
//                 // value = max(value, cover[i][j][0]);
//             }
//         }
//     }

//     // // return Decide(cover, board, altLoc, 0);
//     // value = 0;
//     // int h = 0, benefit = 0;
//     // for (size_t i = 0; i < t; i++)
//     // {
//     //     memcpy(Suboard, board, sizeof(Suboard));
//     //     memcpy(Subcover, cover, sizeof(Subcover));
//     //     benefit = cover[altLoc[i].Y][altLoc[i].X][0] * 10 + DrawCover(Subcover, Suboard, altLoc[i], turn + 1);
//     //     // memcpy(Suboard, board, sizeof(Suboard));
//     //     // memcpy(Subcover, cover, sizeof(Subcover));
//     //     // benefit += DrawCover(Subcover, Suboard, altLoc[i], turn);
//     //     CountIncome(altLoc[i], benefit);
//     //     if (benefit > value)
//     //     {
//     //         value = benefit;
//     //         loc[h++] = altLoc[i];
//     //     }
//     // }

//     // h = (rand() % h);
//     // return loc[h];

//     t = (rand() % t);
//     return altLoc[t];
// }