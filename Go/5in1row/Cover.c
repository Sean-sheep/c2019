#include "Cover.h"

short CountScoreOfMid(unsigned char cover[][_Length][10], struct Location loc, unsigned char option, unsigned char board[][_Length], char dY, char dX)
{
    unsigned char playerNum = option / 5 * 9, //白0,黑9
        prevalue = cover[loc.Y][loc.X][playerNum];
    cover[loc.Y][loc.X][playerNum] = 0;

    for (size_t i = option / 5 * 5; i < option / 5 * 5 + 4; i++)
    {
        switch (cover[loc.Y][loc.X][i])
        {
        case 2:
            cover[loc.Y][loc.X][playerNum] += half_two;
            break;

        case 3:
            cover[loc.Y][loc.X][playerNum] += half_three;
            break;

        default:
            cover[loc.Y][loc.X][playerNum] += half_four;
            break;
        }
    }
    return playerNum ? prevalue - cover[loc.Y][loc.X][playerNum] : cover[loc.Y][loc.X][playerNum] - prevalue;
}

short CountScore(unsigned char cover[][_Length][10], struct Location loc, unsigned char option, unsigned char prevalueOfDrct, unsigned char board[][_Length], char dY, char dX)
{
    unsigned char countpart = 0,    //线的另一头
        playerNum = option / 5 * 9, //白0,黑9
                                    // player = playerNum ? 'B' : 'W',
        prevalue = cover[loc.Y][loc.X][playerNum];

    switch (prevalueOfDrct)
    {
    case 0:
        break;

    case 1:
        cover[loc.Y][loc.X][playerNum] -= one;
        break;

    case 2:
        cover[loc.Y][loc.X][playerNum] -= two;
        break;

    case 3:
        cover[loc.Y][loc.X][playerNum] -= three;
        break;

    case 4:
        cover[loc.Y][loc.X][playerNum] -= four;
        break;

    default:
        break;
    }
    switch (cover[loc.Y][loc.X][option])
    {
    case 0:
        break;

    case 1:
        cover[loc.Y][loc.X][playerNum] += one;
        break;

    case 2:
        countpart = board[loc.Y - dY * 3][loc.X - dX * 3];
        if (0 < countpart && countpart < 10)
        {
            cover[loc.Y][loc.X][playerNum] += two;
        }
        else
        {
            cover[loc.Y][loc.X][playerNum] += half_two;
        }
        break;

    case 3:
        countpart = board[loc.Y - dY * 4][loc.X - dX * 4];
        if (0 < countpart && countpart < 10)
        {
            cover[loc.Y][loc.X][playerNum] += three;
        }
        else
        {
            cover[loc.Y][loc.X][playerNum] += half_three;
        }
        break;

    case 4:
        countpart = board[loc.Y - dY * 5][loc.X - dX * 5];
        if (0 < countpart && countpart < 10)
        {
            cover[loc.Y][loc.X][playerNum] += four;
        }
        else
        {
            cover[loc.Y][loc.X][playerNum] += half_four;
        }
        break;

    default:
        cover[loc.Y][loc.X][playerNum] += five;
        break;
    }
    return playerNum ? prevalue - cover[loc.Y][loc.X][playerNum] : cover[loc.Y][loc.X][playerNum] - prevalue;

    //第二遍重写了……呜呜呜呜
    // unsigned char player = 0, countpart = 0, prevalueW = cover[loc.Y][loc.X][0], prevalueB = cover[loc.Y][loc.X][9];
    // cover[loc.Y][loc.X][9] = cover[loc.Y][loc.X][0] = 0;

    // for (size_t i = 1; i < 9; i++)
    // {
    //     player = i / 5 * 9;
    //     switch (cover[loc.Y][loc.X][i])
    //     {
    //     case 0:
    //         break;

    //     case 1:
    //         cover[loc.Y][loc.X][player] += one;
    //         break;

    //     case 2:
    //         countpart = board[loc.Y - dY * 3][loc.X - dX * 3];
    //         if (0 < countpart && countpart < 10)
    //         {
    //             cover[loc.Y][loc.X][player] += two;
    //         }
    //         else
    //         {
    //             cover[loc.Y][loc.X][player] += half_two;
    //         }
    //         break;

    //     case 3:
    //         countpart = board[loc.Y - dY * 4][loc.X - dX * 4];
    //         if (0 < countpart && countpart < 10)
    //         {
    //             cover[loc.Y][loc.X][player] += three;
    //         }
    //         else
    //         {
    //             cover[loc.Y][loc.X][player] += half_three;
    //         }
    //         break;

    //     case 4:
    //         countpart = board[loc.Y - dY * 5][loc.X - dX * 5];
    //         if (0 < countpart && countpart < 10)
    //         {
    //             cover[loc.Y][loc.X][player] += four;
    //         }
    //         else
    //         {
    //             cover[loc.Y][loc.X][player] += half_four;
    //         }
    //         break;

    //     default:
    //         cover[loc.Y][loc.X][player] += five;
    //         break;
    //     }
    // }
    // return cover[loc.Y][loc.X][0] - prevalueW + prevalueB - cover[loc.Y][loc.X][9]; //白方收益减去黑方收益

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

short ChangeSocreOfLine(unsigned char cover[][_Length][10], unsigned char board[][_Length], struct Location loc, char Y, char X, unsigned char option)
{
    int O = (option < 5),
        W = (board[loc.Y + Y][loc.X + X] == 'W'),
        WW = (board[loc.Y + 2 * Y][loc.X + 2 * X] == 'W'),
        B = (board[loc.Y + Y][loc.X + X] == 'B'),
        BB = (board[loc.Y + 2 * Y][loc.X + 2 * X] == 'B');

    if (board[loc.Y + Y][loc.X + X] > 0 && board[loc.Y + Y][loc.X + X] < 10) //下个点没子
    {
        unsigned char prevalueOfDrct = cover[loc.Y + Y][loc.X + X][option]; //储存下个点原来的方向分
        cover[loc.Y + Y][loc.X + X][option] = cover[loc.Y][loc.X][option];  //将本点方向分赋给下个点

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

        switch ((O * 2 + WW) * 2 + BB) //判断是不是间点
        {
        case 0b110: // if (option >= 1 && option <= 4 && board[loc.Y + 2 * Y][loc.X + 2 * X] == 'W')
            cover[loc.Y + Y][loc.X + X][option] += cover[loc.Y + 2 * Y][loc.X + 2 * X][option];
            break;

        case 0b001: // else if (option >= 5 && option <= 8 && board[loc.Y + 2 * Y][loc.X + 2 * X] == 'B')
            cover[loc.Y + Y][loc.X + X][option] += cover[loc.Y + 2 * Y][loc.X + 2 * X][option];
            break;

        default: //下下点没同色子
            break;
        }
        loc.Y += Y;
        loc.X += X;
        return CountScore(cover, loc, option, prevalueOfDrct, board, Y, X);
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
    switch ((O * 2 + W) * 2 + B)
    {
    case 0b110: // else if (option >= 1 && option <= 4 && board[loc.Y + Y][loc.X + X] == 'W')
        cover[loc.Y][loc.X][option] = cover[loc.Y - Y][loc.X - X][option];
        // loc.Y += Y;
        // loc.X += X;
        ChangeSocreOfLine(cover, board, loc, Y, X, option);
        break;

    case 0b001: // else if (option >= 5 && option <= 8 && board[loc.Y + Y][loc.X + X] == 'B')
        cover[loc.Y][loc.X][option] = cover[loc.Y - Y][loc.X - X][option];
        // loc.Y += Y;
        // loc.X += X;
        ChangeSocreOfLine(cover, board, loc, Y, X, option);
        break;

    case 0b101:
        // loc.Y += Y;
        // loc.X += X;
        ChangeSocreOfLine(cover, board, loc, Y, X, option + 4);
        break;

    case 0b010:
        // loc.Y += Y;
        // loc.X += X;
        ChangeSocreOfLine(cover, board, loc, Y, X, option - 4);
        break;

    default:
        break;
    }

    return 0;
}