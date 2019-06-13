#include "Tic.h"

void PrintBoard(char board[][5])
{
    for (size_t i = 1; i < 4; i++)
    {
        for (size_t t = 1; t < 4; t++)
        {
            switch (board[i][t])
            {
            case 9:
                printf("©¼");
                break;
            case 8:
                printf("©Ø");
                break;
            case 7:
                printf("©¸");
                break;
            case 6:
                printf("©È");
                break;
            case 5:
                printf("©à");
                break;
            case 4:
                printf("©À");
                break;
            case 3:
                printf("©´");
                break;
            case 2:
                printf("©Ð");
                break;
            case 1:
                printf("©°");
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