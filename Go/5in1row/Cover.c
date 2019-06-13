#include "Cover.h"

struct Location AI(unsigned char cover[][_Length][10], unsigned char board[][_Length], int turn)
{
    struct Location ans;
    unsigned char Subcover[Height][_Length][10] = {0}, Suboard[Height][_Length] = {0};
    memcpy(Suboard, board, sizeof(Suboard));
    memcpy(Subcover, cover, sizeof(Subcover));
    Decide(cover, board, &ans, 1);
    return ans;
}

int
Decide(unsigned char cover[][_Length][10], unsigned char board[][_Length], struct Location *ansP, unsigned char extro)
{
    // if (extro != 1)
    // {
    //     for (size_t i = 1; i < Height - 1; i++)
    //     {
    //         for (size_t j = 1; j < _Length - 1; j++)
    //         {
    //             if (extro % 2)
    //             {
    //                 for (size_t k = 1; k < 5; k++)
    //                 {
    //                     if (cover[i][j][k] > 4)
    //                     {
    //                         return 10000;
    //                     }
    //                 }
    //             }
    //             else
    //             {
    //                 for (size_t k = 5; k < 9; k++)
    //                 {
    //                     if (cover[i][j][k] > 4)
    //                     {
    //                         return 10000;
    //                     }
    //                 }
    //             }
    //         }
    //     }
    // }

    int value = 1, rslt = 0;

    if (extro / 2 == Deep)
    {
        struct Location loc;

        for (size_t i = 1; i < Height - 1; i++)
        {
            for (size_t j = 1; j < _Length - 1; j++)
            {
                if (board[i][j] > 0 && board[i][j] < 10 && cover[i][j][0] >= value)
                {
                    value = cover[i][j][0];
                    // for (size_t k = 5 - (extro % 2) * 4; k < 9 - (extro % 2) * 4; k++)
                    // {
                    //     if (cover[i][j][k] > 3)
                    //     {
                    //         value = 1000;
                    //     }
                    // }
                    loc.Y = i;
                    loc.X = j;
                }
            }
        }
        CountIncome(loc, value, extro);
    }
    else
    {
        value = -10000;
        struct Location loc[Pool];
        struct Node ans;
        unsigned char Subcover[Height][_Length][10] = {0}, Suboard[Height][_Length] = {0};

        for (size_t i = 0; i < findPoints(cover, board, loc); i++)
        {
            // value = max(value, cover[loc[i].Y][loc[i].X][0]);
            memcpy(Suboard, board, sizeof(Suboard));
            memcpy(Subcover, cover, sizeof(Subcover));
            Suboard[loc[i].Y][loc[i].X] = (extro % 2) ? 'W' : 'B';
            DrawCover(Subcover, Suboard, loc[i], extro);
            // value = max(value, cover[loc[i].Y][loc[i].X][0] - Decide(Subcover, Suboard, extro + 1));
            rslt = cover[loc[i].Y][loc[i].X][0] - Decide(Subcover, Suboard, ansP, extro + 1);

            CountIncome(loc[i], rslt, extro);

            if (rslt > value)
            {
                value = rslt;
                // for (size_t k = 5 - (extro % 2) * 4; k < 9 - (extro % 2) * 4; k++)
                // {
                //     if (cover[loc[i].Y][loc[i].X][k] > 3)
                //     {
                //         value = 1000;
                //     }
                // }
                if (extro == 1)
                {
                    *ansP = loc[i];
                }
            }
        }
    }
    return value;
}

unsigned char findPoints(unsigned char cover[][_Length][10], unsigned char board[][_Length], struct Location loc[])
{
    char t = 0, value = 1;
    // unsigned char t = 0, values[Pool + 1] = {255};
    // values[Pool] = 1;

    for (size_t i = 1; i < Height - 1; i++)
    {
        for (size_t j = 1; j < _Length - 1; j++)
        {
            // if (board[i][j] > 0 && board[i][j] < 10 && cover[i][j][0] >= values[Pool])
            // {
            //     for (size_t k = Pool - 1; k >= 0; k--)
            //     {
            //         if (cover[i][j][0] <= values[k]) //如果小于等于就把值赋给后项
            //         {
            //             values[k] = cover[i][j][0];
            //             t = max(t, k + 1);
            //             loc[k].Y = i;
            //             loc[k].X = j;
            //             break;
            //         }
            //     }
            // }

            if (board[i][j] > 0 && board[i][j] < 10 && cover[i][j][0] >= (value + 1) / 2)
            {
                if (cover[i][j][0] > value)
                {
                    value = cover[i][j][0];
                    t = 0;
                }
                loc[t].Y = i;
                loc[t].X = j;
                t = (t + 1) % Pool;
                // t = (t == (Pool - 1)) ? 0 : t + 1;
                // value = max(value, cover[i][j][0]);
            }
        }
    }
    return t;
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

unsigned char CountScore(unsigned char cover[][_Length][10], struct Location loc, unsigned char option, unsigned char board[][_Length], char dY, char dX)
{
    unsigned char player = 0, countpart = 0, prevalueW = cover[loc.Y][loc.X][0], prevalueB = cover[loc.Y][loc.X][9];
    cover[loc.Y][loc.X][9] = cover[loc.Y][loc.X][0] = 0;

    for (size_t i = 1; i < 9; i++)
    {
        player = i / 5 * 9;
        switch (cover[loc.Y][loc.X][i])
        {
        case 0:
            break;

        case 1:
            cover[loc.Y][loc.X][player] += one;
            break;

        case 2:
            countpart = board[loc.Y - dY * 3][loc.X - dX * 3];
            if (0 < countpart && countpart < 10)
            {
                cover[loc.Y][loc.X][player] += two;
            }
            else
            {
                cover[loc.Y][loc.X][player] += half_two;
            }
            break;

        case 3:
            countpart = board[loc.Y - dY * 4][loc.X - dX * 4];
            if (0 < countpart && countpart < 10)
            {
                cover[loc.Y][loc.X][player] += three;
            }
            else
            {
                cover[loc.Y][loc.X][player] += half_three;
            }
            break;

        case 4:
            countpart = board[loc.Y - dY * 5][loc.X - dX * 5];
            if (0 < countpart && countpart < 10)
            {
                cover[loc.Y][loc.X][player] += four;
            }
            else
            {
                cover[loc.Y][loc.X][player] += half_four;
            }
            break;

        default:
            cover[loc.Y][loc.X][player] += five;
            break;
        }
    }
    return cover[loc.Y][loc.X][0] - prevalueW + prevalueB - cover[loc.Y][loc.X][9]; //白方收益减去黑方收益

    // // cover[loc.Y][loc.X][0] = cover[loc.Y][loc.X][9] = 0;
    // // int prevalue = cover[loc.Y][loc.X][0];
    // cover[loc.Y][loc.X][0] = 0;

    // for (size_t i = 1; i < 9; i++)
    // {
    //     if (cover[loc.Y][loc.X][i] > 1)
    //     {
    //         cover[loc.Y][loc.X][0] += cover[loc.Y][loc.X][i] * cover[loc.Y][loc.X][i] * cover[loc.Y][loc.X][i];
    //         // cover[loc.Y][loc.X][9] += cover[loc.Y][loc.X][i];
    //     }
    //     // if (cover[loc.Y][loc.X][i] > 4)
    //     // {
    //     //     cover[loc.Y][loc.X][0] *= 10;
    //     //     // cover[loc.Y][loc.X][9] *= 10;
    //     // }
    // }
    // cover[loc.Y][loc.X][0] += (cover[loc.Y][loc.X][0] <= 0);
    // // cover[loc.Y][loc.X][9] += (cover[loc.Y][loc.X][9] <= 0);
    // // int feedback = cover[loc.Y][loc.X][0] - cover[loc.Y][loc.X][9];

    // return cover[loc.Y][loc.X][0];
}

int DrawCover(unsigned char cover[][_Length][10], unsigned char board[][_Length], struct Location loc, int turn)
{
    char dY[4] = {1, 0, 1, 1}, dX[4] = {1, 1, 0, -1};
    int profit = 0;

    if (turn % 2) //逢单白子,逢双黑子
    {
        for (size_t i = 1; i < 5; i++)
        {
            ++cover[loc.Y][loc.X][i];
            profit += ChangeSocreOfLine(cover, board, loc, dY[i - 1], dX[i - 1], i);
            profit += ChangeSocreOfLine(cover, board, loc, -dY[i - 1], -dX[i - 1], i);
        }
        // //[1]White Diag 对角线上前后及自身共三个点的对角线值均增加(下同)
        // ++cover[loc.Y][loc.X][1];
        // ChangeSocreOfLine(cover, board, loc, -1, -1, 1);
        // ChangeSocreOfLine(cover, board, loc, 1, 1, 1);
        // //[2]White Line 行
        // ++cover[loc.Y][loc.X][2];
        // ChangeSocreOfLine(cover, board, loc, 0, -1, 2);
        // ChangeSocreOfLine(cover, board, loc, 0, 1, 2);
        // //[3]White Row 列
        // ++cover[loc.Y][loc.X][3];
        // ChangeSocreOfLine(cover, board, loc, -1, 0, 3);
        // ChangeSocreOfLine(cover, board, loc, 1, 0, 3);
        // //[4]White Subdiag 副对角线
        // ++cover[loc.Y][loc.X][4];
        // ChangeSocreOfLine(cover, board, loc, -1, 1, 4);
        // ChangeSocreOfLine(cover, board, loc, 1, -1, 4);
    }
    else
    {
        for (size_t i = 5; i < 9; i++)
        {
            ++cover[loc.Y][loc.X][i];
            profit += ChangeSocreOfLine(cover, board, loc, dY[i - 5], dX[i - 5], i);
            profit += ChangeSocreOfLine(cover, board, loc, -dY[i - 5], -dX[i - 5], i);
        }
        // //[5]Black Diag
        // ++cover[loc.Y][loc.X][5];
        // ChangeSocreOfLine(cover, board, loc, -1, -1, 5);
        // ChangeSocreOfLine(cover, board, loc, 1, 1, 5);
        // //[6]Black Line
        // ++cover[loc.Y][loc.X][6];
        // ChangeSocreOfLine(cover, board, loc, 0, -1, 6);
        // ChangeSocreOfLine(cover, board, loc, 0, 1, 6);
        // //[7]Black Row
        // ++cover[loc.Y][loc.X][7];
        // ChangeSocreOfLine(cover, board, loc, -1, 0, 7);
        // ChangeSocreOfLine(cover, board, loc, 1, 0, 7);
        // //[8]Black Subdiag
        // ++cover[loc.Y][loc.X][8];
        // ChangeSocreOfLine(cover, board, loc, -1, 1, 8);
        // ChangeSocreOfLine(cover, board, loc, 1, -1, 8);
    }
    return profit;
}

unsigned char ChangeSocreOfLine(unsigned char cover[][_Length][10], unsigned char board[][_Length], struct Location loc, char Y, char X, unsigned char option)
{
    int a = (option < 5) * 2,
        b = (board[loc.Y + Y][loc.X + X] == 'W'),
        c = (board[loc.Y + 2 * Y][loc.X + 2 * X] == 'W');

    if (board[loc.Y + Y][loc.X + X] > 0)
    {
        if (board[loc.Y + Y][loc.X + X] < 10) //下个点没子
        {
            cover[loc.Y + Y][loc.X + X][option] = cover[loc.Y][loc.X][option];

            // if (board[loc.Y + 2 * Y][loc.X + 2 * X] > 0 && board[loc.Y + 2 * Y][loc.X + 2 * X] < 10) //下下点也没子
            // {
            //     cover[loc.Y + Y][loc.X + X][option] = cover[loc.Y][loc.X][option];
            // }
            // else

            // if (option >= 1 && option <= 4 && board[loc.Y + 2 * Y][loc.X + 2 * X] == 'W')
            // {
            //     cover[loc.Y + Y][loc.X + X][option] += cover[loc.Y + 2 * Y][loc.X + 2 * X][option];
            // }
            // else if (option >= 5 && option <= 8 && board[loc.Y + 2 * Y][loc.X + 2 * X] == 'B')
            // {
            //     cover[loc.Y + Y][loc.X + X][option] += cover[loc.Y + 2 * Y][loc.X + 2 * X][option];
            // }

            switch (a + c)
            {
            case 0b11: // if (option >= 1 && option <= 4 && board[loc.Y + 2 * Y][loc.X + 2 * X] == 'W')
                cover[loc.Y + Y][loc.X + X][option] += cover[loc.Y + 2 * Y][loc.X + 2 * X][option];
                break;

            case 0b00: // else if (option >= 5 && option <= 8 && board[loc.Y + 2 * Y][loc.X + 2 * X] == 'B')
                cover[loc.Y + Y][loc.X + X][option] += cover[loc.Y + 2 * Y][loc.X + 2 * X][option];
                break;

            default:
                break;
            }

            loc.Y += Y;
            loc.X += X;
            return CountScore(cover, loc, option, board, Y, X);
        }

        // else if (option >= 1 && option <= 4 && board[loc.Y + Y][loc.X + X] == 'W')
        // {
        //     cover[loc.Y + Y][loc.X + X][option] = cover[loc.Y][loc.X][option];
        //     loc.Y += Y;
        //     loc.X += X;
        //     ChangeSocreOfLine(cover, board, loc, Y, X, option);
        // }
        // else if (option >= 5 && option <= 8 && board[loc.Y + Y][loc.X + X] == 'B')
        // {
        //     cover[loc.Y + Y][loc.X + X][option] = cover[loc.Y][loc.X][option];
        //     loc.Y += Y;
        //     loc.X += X;
        //     ChangeSocreOfLine(cover, board, loc, Y, X, option);
        // }

        loc.Y += Y; //反正都要加，不如提前
        loc.X += X;
        switch (a + b)
        {
        case 0b11: // else if (option >= 1 && option <= 4 && board[loc.Y + Y][loc.X + X] == 'W')
            cover[loc.Y][loc.X][option] = cover[loc.Y - Y][loc.X - X][option];
            // loc.Y += Y;
            // loc.X += X;
            ChangeSocreOfLine(cover, board, loc, Y, X, option);
            break;

        case 0b00: // else if (option >= 5 && option <= 8 && board[loc.Y + Y][loc.X + X] == 'B')
            cover[loc.Y][loc.X][option] = cover[loc.Y - Y][loc.X - X][option];
            // loc.Y += Y;
            // loc.X += X;
            ChangeSocreOfLine(cover, board, loc, Y, X, option);
            break;

        case 0b10:
            // loc.Y += Y;
            // loc.X += X;
            ChangeSocreOfLine(cover, board, loc, Y, X, option + 4);
            break;

        case 0b01:
            // loc.Y += Y;
            // loc.X += X;
            ChangeSocreOfLine(cover, board, loc, Y, X, option - 4);
            break;

        default:
            break;
        }
    }
    return 0;
}