#include "Test.h"

void PrintCover(unsigned char cover[][_Length][10])
{
    for (size_t i = 1; i < Height - 1; i++)
    {
        for (size_t t = 1; t < _Length - 1; t++)
        {
            if (cover[i][t][0] < 10)
            {
                printf(" ");
            }
            printf("%d,", cover[i][t][0]);
        }
        printf("\n");
    }
}

void InitRecord()
{
    FILE *fp;
    fp = fopen("��¼.txt", "w");
    fclose(fp);
}

void EveryStep(unsigned char cover[][_Length][10], unsigned char board[][_Length])
{
    FILE *fp;
    fp = fopen("��¼.txt", "a");
    for (size_t i = 1; i < Height - 1; i++)
    {
        for (size_t t = 1; t < _Length - 1; t++)
        {
            if (0 < board[i][t] && board[i][t] < 10)
            {
                fprintf(fp, "%2d,", cover[i][t][0]);
            }
            else
            {
                fprintf(fp, "%2c,", board[i][t]);
            }
        }
        fprintf(fp, "\n");
    }
    fprintf(fp, "\n \n");
    fclose(fp);
}

void EveryPoint(unsigned char cover[][_Length][10], struct Location loc, int turn)
{
    FILE *fp;
    fp = fopen("��¼.txt", "a");
    fprintf(fp, "X:%2c,Y:%2d,count:%d,white:", loc.X + 64, loc.Y, cover[loc.Y][loc.X][0]);
    for (size_t i = 1; i < 5; i++)
    {
        fprintf(fp, "%2d", cover[loc.Y][loc.X][i]);
    }
    fprintf(fp, "black:");
    for (size_t i = 5; i < 9; i++)
    {
        fprintf(fp, "%2d", cover[loc.Y][loc.X][i]);
    }
    fprintf(fp, "\n");
    fclose(fp);
}

void CountIncome(struct Location loc, int benefit, int turn)
{
    FILE *fp;
    fp = fopen("��¼.txt", "a");
    for (size_t i = 1; i < turn; i++)
    {
        fprintf(fp, "   ");
    }
    fprintf(fp, "%d)X:%2c,Y:%2d,benefit:%2d\n", turn, loc.X + 64, loc.Y, benefit);
    fclose(fp);
}