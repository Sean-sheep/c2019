#include "Tic.h"

char PutChessWithCoverCheck(char map, char *turn, char cover[][3], COORD coord)
{
    if (0 < map && map < 10)
    {
        if (*turn % 2) //turn��0��ʼ
        {
            map = 'W'; //�굥�°���
        }
        else
        {
            map = 'B'; //��˫�º���
        }
        ++*turn;
    }
    return map;
}