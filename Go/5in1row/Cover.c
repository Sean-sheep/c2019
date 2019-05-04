#include "Tic.h"

void DrawCover(char cover[][Length][9], char board[][Length], struct Location loc, int turn)
{
    EveryPoint(cover, loc); //Test
    EveryStep(cover);       //Test
    if (turn)               //逢单白子,逢双黑子
    {
        //[1]White Diag 对角线上前后及自身共三个点的对角线值均增加(下同)
        ++cover[loc.Y][loc.X][1];
        ChangeSocreOfLine(cover, board, loc, -1, -1, 1);
        ChangeSocreOfLine(cover, board, loc, 1, 1, 1);
        //[2]White Line 行
        ++cover[loc.Y][loc.X][2];
        ChangeSocreOfLine(cover, board, loc, 0, -1, 2);
        ChangeSocreOfLine(cover, board, loc, 0, 1, 2);
        //[3]White Row 列
        ++cover[loc.Y][loc.X][3];
        ChangeSocreOfLine(cover, board, loc, -1, 0, 3);
        ChangeSocreOfLine(cover, board, loc, 1, 0, 3);
        //[4]White Subdiag 副对角线
        ++cover[loc.Y][loc.X][4];
        ChangeSocreOfLine(cover, board, loc, -1, 1, 4);
        ChangeSocreOfLine(cover, board, loc, 1, -1, 4);
    }
    else
    { //[5]Black Diag
        ++cover[loc.Y][loc.X][5];
        ChangeSocreOfLine(cover, board, loc, -1, -1, 5);
        ChangeSocreOfLine(cover, board, loc, 1, 1, 5);
        //[6]Black Line
        ++cover[loc.Y][loc.X][6];
        ChangeSocreOfLine(cover, board, loc, 0, -1, 6);
        ChangeSocreOfLine(cover, board, loc, 0, 1, 6);
        //[7]Black Row
        ++cover[loc.Y][loc.X][7];
        ChangeSocreOfLine(cover, board, loc, -1, 0, 7);
        ChangeSocreOfLine(cover, board, loc, 1, 0, 7);
        //[8]Black Subdiag
        ++cover[loc.Y][loc.X][8];
        ChangeSocreOfLine(cover, board, loc, -1, 1, 8);
        ChangeSocreOfLine(cover, board, loc, 1, -1, 8);
    }
}

void ChangeSocreOfLine(char cover[][Length][9], char board[][Length], struct Location loc, char Y, char X, char option)
{
    if (board[loc.Y + Y][loc.X + X] > 0 && board[loc.Y + Y][loc.X + X] < 10) //下个点没子
    {
        cover[loc.Y + Y][loc.X + X][option] = cover[loc.Y][loc.X][option];
        /*
        if (board[loc.Y + 2 * Y][loc.X + 2 * X] > 0 && board[loc.Y + 2 * Y][loc.X + 2 * X] < 10) //下下点也没子
        {
            cover[loc.Y + Y][loc.X + X][option] = cover[loc.Y][loc.X][option];
        }
        else
        */
        if (option >= 1 && option <= 4 && board[loc.Y + 2 * Y][loc.X + 2 * X] == 'W')
        {
            cover[loc.Y + Y][loc.X + X][option] += cover[loc.Y + 2 * Y][loc.X + 2 * X][option];
        }
        else if (option >= 5 && option <= 8 && board[loc.Y + 2 * Y][loc.X + 2 * X] == 'B')
        {
            cover[loc.Y + Y][loc.X + X][option] += cover[loc.Y + 2 * Y][loc.X + 2 * X][option];
        }
        loc.Y += Y;
        loc.X += X;
        CountScore(cover, loc, option, board, Y, X); //计算下个点的价值，参数中包括下个点对当前点的相对位置
    }
    else if (option >= 1 && option <= 4 && board[loc.Y + Y][loc.X + X] == 'W')
    {
        cover[loc.Y + Y][loc.X + X][option] = cover[loc.Y][loc.X][option];
        loc.Y += Y;
        loc.X += X;
        ChangeSocreOfLine(cover, board, loc, Y, X, option);
    }
    else if (option >= 5 && option <= 8 && board[loc.Y + Y][loc.X + X] == 'B')
    {
        cover[loc.Y + Y][loc.X + X][option] = cover[loc.Y][loc.X][option];
        loc.Y += Y;
        loc.X += X;
        ChangeSocreOfLine(cover, board, loc, Y, X, option);
    }
}