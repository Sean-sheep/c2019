#include "AI.h"

struct Location AI(char cover[][Length][Pool], char board[][Length])
{
    char SubCover[Height][Length][Pool], SubBoard[Height][Length];
    strcpy(SubCover[Height][Length], cover[Height][Length]);
    strcpy(SubBoard[Height], board[Height]);

    return Decide(SubCover, SubBoard);

    //printf("%d", t);
    //return set[t];
}

void
CountScore(char cover[][Length][Pool], struct Location loc, int option, char board[][Length], char dY, char dX)
{
    for (size_t i = 1; i < Height; i++)
    {
        for (size_t j = 1; j < Length; j++)
        {
            cover[i][j][0] = cover[i][j][Pool] = 0;

            for (size_t k = 1; k < 10; k++)
            {
                cover[i][j][0] += cover[i][j][k];

                switch (cover[i][j][k])
                {
                case 2:
                    if (board[loc.Y + dY][loc.X + dX] > 0 && board[loc.Y + dY][loc.X + dX] < 10) //ǰ�治������ͬ
                    {
                        cover[i][j][0] += cover[i][j][k];
                    }
                    else
                    {
                        ++cover[i][j][0];
                    }

                    break;

                case 3:
                    if (board[loc.Y + dY][loc.X + dX] > 0 && board[loc.Y + dY][loc.X + dX] < 10) //ǰ�治������ͬ
                    {
                        if (board[loc.Y - 4 * dY][loc.X - 4 * dX] > 0 && board[loc.Y - 4 * dY][loc.X - 4 * dX] < 10 && (dX * 2 + dY) >= 0) //˫����
                        {
                            if ((option - 1) / 4) //5~8Ϊ�ڣ�1~4Ϊ��
                            {
                                cover[i][j][0] += cover[i][j][k] * 3;
                            }
                            else
                            {
                                cover[i][j][0] += cover[i][j][k] * 4;
                            }
                        }
                        else //������
                        {
                            if ((option - 1) / 4) //5~8Ϊ�ڣ�1~4Ϊ��
                            {
                                cover[i][j][0] += cover[i][j][k] * 3;
                            }
                            else
                            {
                                cover[i][j][0] += cover[i][j][k] * 2;
                            }
                        }

                        if (board[loc.Y - 4 * dY][loc.X - 4 * dX] > 0 && board[loc.Y - 4 * dY][loc.X - 4 * dX] < 10 && (dX * 2 + dY) >= 0) //˫������һ��
                        {
                            if ((option - 1) / 4) //5~8Ϊ�ڣ�1~4Ϊ��
                            {
                                cover[i][j][0] += cover[i][j][k] * 2;
                            }
                            else
                            {
                                cover[i][j][0] += cover[i][j][k] * 3;
                            }
                        }
                        else //˫��������һ��
                        {
                            if ((option - 1) / 4) //5~8Ϊ�ڣ�1~4Ϊ��
                            {
                                cover[i][j][0] += cover[i][j][k] * 2;
                            }
                            else
                            {
                                cover[i][j][0] += cover[i][j][k];
                            }
                        }
                    }
                    else
                    {
                        cover[i][j][0] += cover[i][j][k];
                    }
                    break;

                case 4:
                    if ((option - 1) / 4) //5~8Ϊ�ڣ�1~4Ϊ��
                    {
                        cover[i][j][0] += cover[i][j][k] * 4;
                    }
                    else
                    {
                        cover[i][j][0] += cover[i][j][k] * 5;
                    }
                    break;

                default:
                    break;
                }
            }
            cover[i][j][0] += (cover[i][j][0] <= 0);
        }
    }
}

// for (size_t i = 1; i < Height - 1; i++)
// {
//     for (size_t t = 1; t < Length - 1; t++)
//     {
//         cover[i][t][0] -= (cover[i][t][0] > 0);
//     }
// }

// cover[loc.Y][loc.X][0] = 0;
// for (size_t i = 1; i < 9; i++)
// {
//     cover[loc.Y][loc.X][0] += cover[loc.Y][loc.X][i];

//     switch (cover[loc.Y][loc.X][i])
//     {
//     case 2:
//         if (board[loc.Y + dY][loc.X + dX] > 0 && board[loc.Y + dY][loc.X + dX] < 10) //ǰ�治������ͬ
//         {
//             cover[loc.Y][loc.X][0] += cover[loc.Y][loc.X][i];
//         }
//         else
//         {
//             ++cover[loc.Y][loc.X][0];
//         }

//         break;

//     case 3:
//         if (board[loc.Y + dY][loc.X + dX] > 0 && board[loc.Y + dY][loc.X + dX] < 10) //ǰ�治������ͬ
//         {
//             if (board[loc.Y - 4 * dY][loc.X - 4 * dX] > 0 && board[loc.Y - 4 * dY][loc.X - 4 * dX] < 10 && (dX * 2 + dY) >= 0) //˫����
//             {
//                 if ((option - 1) / 4) //5~8Ϊ�ڣ�1~4Ϊ��
//                 {
//                     cover[loc.Y][loc.X][0] += cover[loc.Y][loc.X][i] * 3;
//                 }
//                 else
//                 {
//                     cover[loc.Y][loc.X][0] += cover[loc.Y][loc.X][i] * 4;
//                 }
//             }
//             else //������
//             {
//                 if ((option - 1) / 4) //5~8Ϊ�ڣ�1~4Ϊ��
//                 {
//                     cover[loc.Y][loc.X][0] += cover[loc.Y][loc.X][i] * 3;
//                 }
//                 else
//                 {
//                     cover[loc.Y][loc.X][0] += cover[loc.Y][loc.X][i] * 2;
//                 }
//             }

//             if (board[loc.Y - 4 * dY][loc.X - 4 * dX] > 0 && board[loc.Y - 4 * dY][loc.X - 4 * dX] < 10 && (dX * 2 + dY) >= 0) //˫������һ��
//             {
//                 if ((option - 1) / 4) //5~8Ϊ�ڣ�1~4Ϊ��
//                 {
//                     cover[loc.Y][loc.X][0] += cover[loc.Y][loc.X][i] * 2;
//                 }
//                 else
//                 {
//                     cover[loc.Y][loc.X][0] += cover[loc.Y][loc.X][i] * 3;
//                 }
//             }
//             else //˫��������һ��
//             {
//                 if ((option - 1) / 4) //5~8Ϊ�ڣ�1~4Ϊ��
//                 {
//                     cover[loc.Y][loc.X][0] += cover[loc.Y][loc.X][i] * 2;
//                 }
//                 else
//                 {
//                     cover[loc.Y][loc.X][0] += cover[loc.Y][loc.X][i];
//                 }
//             }
//         }
//         else
//         {
//             cover[loc.Y][loc.X][0] += cover[loc.Y][loc.X][i];
//         }
//         break;

//     case 4:
//         if ((option - 1) / 4) //5~8Ϊ�ڣ�1~4Ϊ��
//         {
//             cover[loc.Y][loc.X][0] += cover[loc.Y][loc.X][i] * 4;
//         }
//         else
//         {
//             cover[loc.Y][loc.X][0] += cover[loc.Y][loc.X][i] * 5;
//         }
//         break;

//     default:
//         break;
//     }

// }
// cover[loc.Y][loc.X][0] += (cover[loc.Y][loc.X][0] <= 0);
// cover[loc.Y][loc.X][0] *= 20;

struct Location Decide(char cover[][Length][Pool], char board[][Length])
{
    int t = 0, value = 1;
    struct Location set[225];
    for (size_t i = 1; i < Height - 1; i++)
    {
        for (size_t j = 1; j < Length - 1; j++)
        {
            if (board[i][j] > 0 && board[i][j] < 10 && cover[i][j][0] >= value - 10)
            {
                if (cover[i][j][0] > value)
                {
                    value = cover[i][j][0];
                    i = j = t = 0;
                }
                set[t].Y = i;
                set[t].X = j;
                ++t;
            }
        }
    }
    t = (rand() % t);
}
