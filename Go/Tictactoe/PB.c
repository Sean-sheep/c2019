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
                printf("©¸");
                break;
            case 8:
                printf("©Ø");
                break;
            case 7:
                printf("©¼");
                break;
            case 6:
                printf("©À");
                break;
            case 5:
                printf("©à");
                break;
            case 4:
                printf("©È");
                break;
            case 3:
                printf("©°");
                break;
            case 2:
                printf("©Ð");
                break;
            case 1:
                printf("©´");
                break;
            case 'B':
                printf("¡ñ");
                break;
            case 'W':
                printf("¡ð");
                break;

            default:
                break;
            }
        }
        printf("\n");
    }
}