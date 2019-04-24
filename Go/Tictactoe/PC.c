#include "Tic.h"

char PutChess(char map, char *turn)
{
    if (0 < map && map < 10)
    {
        if (*turn % 2) //turn从0开始
        {
            map = 'W'; //逢单下白子
        }
        else
        {
            map = 'B'; //逢双下黑子
        }
        ++*turn;
    }
    return map;
}