#include "Tic.h"

struct Point InitCover(struct Point point)
{
    point.Count = 0;
    point.Black.Diag = 0;
    point.Black.Line = 0;
    point.Black.Row = 0;
    point.Black.Subdiag = 0;
    point.White.Diag = 0;
    point.White.Line = 0;
    point.White.Row = 0;
    point.White.Subdiag = 0;
    return point;
}

struct Point CountScore(struct Point point)
{
    point.Count =
        point.Black.Diag +
        point.Black.Line +
        point.Black.Row +
        point.Black.Subdiag +
        point.White.Diag +
        point.White.Line +
        point.White.Row +
        point.White.Subdiag;
    return point;
}

void DrawCover(struct Point cover[][5], struct Location loc, int turn)
{
    if (turn) //逢单白子,逢双黑子
    {
        //对角线上前后及自身共三个点的对角线值均增加(下同)
        cover[loc.Y - 1][loc.X - 1].White.Diag += ++cover[loc.Y][loc.X].White.Diag;
        cover[loc.Y + 1][loc.X + 1].White.Diag += cover[loc.Y][loc.X].White.Diag;
        //行
        cover[loc.Y][loc.X - 1].White.Line += ++cover[loc.Y][loc.X].White.Line;
        cover[loc.Y][loc.X + 1].White.Line += cover[loc.Y][loc.X].White.Line;
        //列
        cover[loc.Y - 1][loc.X].White.Row += ++cover[loc.Y][loc.X].White.Row;
        cover[loc.Y + 1][loc.X].White.Row += cover[loc.Y][loc.X].White.Row;
        //副对角线
        cover[loc.Y - 1][loc.X + 1].White.Subdiag += ++cover[loc.Y][loc.X].White.Subdiag;
        cover[loc.Y + 1][loc.X - 1].White.Subdiag += cover[loc.Y][loc.X].White.Subdiag;
    }
    else
    {
        cover[loc.Y - 1][loc.X - 1].Black.Diag += ++cover[loc.Y][loc.X].Black.Diag;
        cover[loc.Y + 1][loc.X + 1].Black.Diag += cover[loc.Y][loc.X].Black.Diag;
        cover[loc.Y][loc.X - 1].Black.Line += ++cover[loc.Y][loc.X].Black.Line;
        cover[loc.Y][loc.X + 1].Black.Line += cover[loc.Y][loc.X].Black.Line;
        cover[loc.Y - 1][loc.X].Black.Row += ++cover[loc.Y][loc.X].Black.Row;
        cover[loc.Y + 1][loc.X].Black.Row += cover[loc.Y][loc.X].Black.Row;
        cover[loc.Y - 1][loc.X + 1].Black.Subdiag += ++cover[loc.Y][loc.X].Black.Subdiag;
        cover[loc.Y + 1][loc.X - 1].Black.Subdiag += cover[loc.Y][loc.X].Black.Subdiag;
    }
    CountScore(cover[loc.Y][loc.X]);
    printf("%d, %d %d %d %d, %d %d %d %d",
           cover[loc.Y][loc.X].Count,
           cover[loc.Y][loc.X].Black.Diag,
           cover[loc.Y][loc.X].Black.Line,
           cover[loc.Y][loc.X].Black.Row,
           cover[loc.Y][loc.X].Black.Subdiag,
           cover[loc.Y][loc.X].White.Diag,
           cover[loc.Y][loc.X].White.Line,
           cover[loc.Y][loc.X].White.Row,
           cover[loc.Y][loc.X].White.Subdiag);
    system("pause");
}