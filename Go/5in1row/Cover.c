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
}

int DrawCover(unsigned char cover[][_Length][10], unsigned char board[][_Length], struct Location loc, int turn)
{
    char dY[4] = {1, 0, 1, 1}, dX[4] = {1, 1, 0, -1};
    int profit = 0;

    if (turn % 2) //逢单白子,逢双黑子
    {
        // //[1]White Diag 对角线上前后及自身共三个点的对角线值均增加(下同)
        // //[2]White Line 行
        // //[3]White Row 列
        // //[4]White Subdiag 副对角线
        for (size_t i = 1; i < 5; i++)
        {
            ++cover[loc.Y][loc.X][i];
            profit += ChangeSocreOfLine(cover, board, loc, dY[i - 1], dX[i - 1], i);
            profit += ChangeSocreOfLine(cover, board, loc, -dY[i - 1], -dX[i - 1], i);
        }
    }
    else
    {
        for (size_t i = 5; i < 9; i++)
        {
            ++cover[loc.Y][loc.X][i];
            profit += ChangeSocreOfLine(cover, board, loc, dY[i - 5], dX[i - 5], i);
            profit += ChangeSocreOfLine(cover, board, loc, -dY[i - 5], -dX[i - 5], i);
        }
    }
    return profit;
}

short ChangeSocreOfLine(unsigned char cover[][_Length][10], unsigned char board[][_Length], struct Location loc, char Y, char X, unsigned char option)
{
    loc.Y += Y;
    loc.X += X;
    int O = (option < 5),
        W = (board[loc.Y][loc.X] == 'W'),
        WW = (board[loc.Y + Y][loc.X + X] == 'W'),
        B = (board[loc.Y][loc.X] == 'B'),
        BB = (board[loc.Y + Y][loc.X + X] == 'B');

    if (board[loc.Y][loc.X] > 0 && board[loc.Y][loc.X] < 10) //下个点没子
    {
        unsigned char prevalueOfDrct = cover[loc.Y][loc.X][option];        //储存下个点原来的方向分
        cover[loc.Y][loc.X][option] = cover[loc.Y - Y][loc.X - X][option]; //将本点方向分赋给下个点

        switch ((O * 2 + WW) * 2 + BB) //判断是不是间点
        {
        case 0b110: // if (option >= 1 && option <= 4 && board[loc.Y + 2 * Y][loc.X + 2 * X] == 'W')
            cover[loc.Y][loc.X][option] += cover[loc.Y + Y][loc.X + X][option];
            break;

        case 0b001: // else if (option >= 5 && option <= 8 && board[loc.Y + 2 * Y][loc.X + 2 * X] == 'B')
            cover[loc.Y][loc.X][option] += cover[loc.Y + Y][loc.X + X][option];
            break;

        default: //下下点没同色子
            break;
        }
        return CountScore(cover, loc, option, prevalueOfDrct, board, Y, X);
    }
    switch ((O * 2 + W) * 2 + B)
    {
    case 0b110: // else if (option >= 1 && option <= 4 && board[loc.Y + Y][loc.X + X] == 'W')
        cover[loc.Y][loc.X][option] = cover[loc.Y - Y][loc.X - X][option];
        ChangeSocreOfLine(cover, board, loc, Y, X, option);
        break;

    case 0b001: // else if (option >= 5 && option <= 8 && board[loc.Y + Y][loc.X + X] == 'B')
        cover[loc.Y][loc.X][option] = cover[loc.Y - Y][loc.X - X][option];
        ChangeSocreOfLine(cover, board, loc, Y, X, option);
        break;

    case 0b101:
        ChangeSocreOfLine(cover, board, loc, Y, X, option + 4);
        break;

    case 0b010:
        ChangeSocreOfLine(cover, board, loc, Y, X, option - 4);
        break;

    default:
        break;
    }

    return 0;
}