#include "Tic.h"

Point Initboard(Point board[][3])
{
    int t = 0;
    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            board[i][j].outlook = ++t;
        }
    }
}