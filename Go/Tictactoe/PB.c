#include "Tic.h"

void PrintBoard(Point board[][3])
{
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t t = 0; t < 3; t++)
        {
            switch (board[i][t].outlook)
            {
            case 9:
                printf("��");
                break;
            case 8:
                printf("��");
                break;
            case 7:
                printf("��");
                break;
            case 6:
                printf("��");
                break;
            case 5:
                printf("��");
                break;
            case 4:
                printf("��");
                break;
            case 3:
                printf("��");
                break;
            case 2:
                printf("��");
                break;
            case 1:
                printf("��");
                break;
            case 'B':
                printf("��");
                break;
            case 'W':
                printf("��");
                break;

            default:
                break;
            }
        }
        printf("\n");
    }
}