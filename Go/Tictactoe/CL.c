#include "Tic.h"

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