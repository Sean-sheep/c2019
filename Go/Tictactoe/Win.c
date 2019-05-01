#include "Tic.h"

boolean WinCheck(struct Point point, char board, int turn)
{
    if (point.White.Diag >= 3 || point.White.Line >= 3 || point.White.Row >= 3 || point.White.Subdiag >= 3 || point.Black.Diag >= 3 || point.Black.Line >= 3 || point.Black.Row >= 3 || point.Black.Subdiag >= 3)
    {
        return 0;
    }
    return 1;
}
