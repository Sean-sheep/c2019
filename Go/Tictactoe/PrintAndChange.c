#include "Tic.h"

boolean PutChess(char *map, int turn)
{
    if (0 < *map && *map < 10) //判断该点是否已落子
    {
        if (turn % 2) //turn从0开始
        {
            *map = 'W'; //逢单下白子
        }
        else
        {
            *map = 'B'; //逢双下黑子
        }
        return 1;
    }
    return 0;
}

void PrintBoard(char board[][5])
{
    for (size_t i = 1; i < 4; i++)
    {
        for (size_t t = 1; t < 4; t++)
        {
            switch (board[i][t])
            {
            case 9:
                printf("┘");
                break;
            case 8:
                printf("┴");
                break;
            case 7:
                printf("└");
                break;
            case 6:
                printf("┤");
                break;
            case 5:
                printf("┼");
                break;
            case 4:
                printf("├");
                break;
            case 3:
                printf("┐");
                break;
            case 2:
                printf("┬");
                break;
            case 1:
                printf("┌");
                break;
            case 'B':
                printf("●");
                break;
            case 'W':
                printf("○");
                break;

            default:
                break;
            }
        }
        printf("\n");
    }
}

short ChangeLine(char change, short loc)
{
    switch (change)
    {
    case '+':
        if (loc >= 0 && loc <= 3)
        {
            loc += 2;
        }
        break;

    case '-':
        if (loc >= 2 && loc <= 5)
        {
            loc -= 2;
        }
        break;
    default:
        break;
    }
    return loc;
}

short ChangeRow(char change, short loc)
{
    switch (change)
    {
    case '+':
        if (loc >= 0 && loc <= 1)
        {
            loc += 1;
        }
        break;

    case '-':
        if (loc >= 1 && loc <= 2)
        {
            loc -= 1;
        }
        break;

    default:
        break;
    }
    return loc;
}