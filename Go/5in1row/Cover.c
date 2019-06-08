#include "Cover.h"

int DrawCover(char cover[][_Length][Pool], char board[][_Length], struct Location loc, int turn)
{
    char dY[4] = {1, 0, 1, 1}, dX[4] = {1, 1, 0, -1};
    int profit = 0;

    EveryPoint(cover, loc, turn); //Test
    EveryStep(cover);             //Test

    if (turn % 2) //�굥����,��˫����
    {
        for (size_t i = 1; i < 5; i++)
        {
            ++cover[loc.Y][loc.X][i];
            profit += ChangeSocreOfLine(cover, board, loc, dY[i - 1], dX[i - 1], i);
            profit += ChangeSocreOfLine(cover, board, loc, -dY[i - 1], -dX[i - 1], i);
        }
        // //[1]White Diag �Խ�����ǰ������������ĶԽ���ֵ������(��ͬ)
        // ++cover[loc.Y][loc.X][1];
        // ChangeSocreOfLine(cover, board, loc, -1, -1, 1);
        // ChangeSocreOfLine(cover, board, loc, 1, 1, 1);
        // //[2]White Line ��
        // ++cover[loc.Y][loc.X][2];
        // ChangeSocreOfLine(cover, board, loc, 0, -1, 2);
        // ChangeSocreOfLine(cover, board, loc, 0, 1, 2);
        // //[3]White Row ��
        // ++cover[loc.Y][loc.X][3];
        // ChangeSocreOfLine(cover, board, loc, -1, 0, 3);
        // ChangeSocreOfLine(cover, board, loc, 1, 0, 3);
        // //[4]White Subdiag ���Խ���
        // ++cover[loc.Y][loc.X][4];
        // ChangeSocreOfLine(cover, board, loc, -1, 1, 4);
        // ChangeSocreOfLine(cover, board, loc, 1, -1, 4);
    }
    else
    {
        for (size_t i = 5; i < 9; i++)
        {
            ++cover[loc.Y][loc.X][i];
            profit += ChangeSocreOfLine(cover, board, loc, dY[i - 5], dX[i - 5], i);
            profit += ChangeSocreOfLine(cover, board, loc, -dY[i - 5], -dX[i - 5], i);
        }
        // //[5]Black Diag
        // ++cover[loc.Y][loc.X][5];
        // ChangeSocreOfLine(cover, board, loc, -1, -1, 5);
        // ChangeSocreOfLine(cover, board, loc, 1, 1, 5);
        // //[6]Black Line
        // ++cover[loc.Y][loc.X][6];
        // ChangeSocreOfLine(cover, board, loc, 0, -1, 6);
        // ChangeSocreOfLine(cover, board, loc, 0, 1, 6);
        // //[7]Black Row
        // ++cover[loc.Y][loc.X][7];
        // ChangeSocreOfLine(cover, board, loc, -1, 0, 7);
        // ChangeSocreOfLine(cover, board, loc, 1, 0, 7);
        // //[8]Black Subdiag
        // ++cover[loc.Y][loc.X][8];
        // ChangeSocreOfLine(cover, board, loc, -1, 1, 8);
        // ChangeSocreOfLine(cover, board, loc, 1, -1, 8);
    }
    return profit;
}

char ChangeSocreOfLine(char cover[][_Length][Pool], char board[][_Length], struct Location loc, char Y, char X, char option)
{
    if (board[loc.Y + Y][loc.X + X] > 0 && board[loc.Y + Y][loc.X + X] < 10) //�¸���û��
    {
        cover[loc.Y + Y][loc.X + X][option] = cover[loc.Y][loc.X][option];

        // if (board[loc.Y + 2 * Y][loc.X + 2 * X] > 0 && board[loc.Y + 2 * Y][loc.X + 2 * X] < 10) //���µ�Ҳû��
        // {
        //     cover[loc.Y + Y][loc.X + X][option] = cover[loc.Y][loc.X][option];
        // }
        // else

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
        return CountScore(cover, loc, option, board, Y, X); //�����¸���ļ�ֵ�������а����¸���Ե�ǰ������λ��,���ذ��ӶԺ��ӵļ�ֵ��
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