#include "Test.h"

void PrintCover(char cover[][_Length_][Pool])
{
    for (size_t i = 1; i < Height - 1; i++)
    {
        for (size_t t = 1; t < _Length_ - 1; t++)
        {
            printf("%2d,", cover[i][t][0]);
        }
        printf("\n");
    }
}

void InitRecord()
{
    FILE *fp;
    fp = fopen("¼ÇÂ¼.txt", "w");
    fclose(fp);
}

void EveryStep(char cover[][_Length_][Pool])
{
    FILE *fp;
    fp = fopen("¼ÇÂ¼.txt", "a");
    for (size_t i = 1; i < Height - 1; i++)
    {
        for (size_t t = 1; t < _Length_ - 1; t++)
        {
            if (cover[i][t][0] < 10)
            {
                fprintf(fp, " ");
            }
            fprintf(fp, "%d,", cover[i][t][0]);
        }
        fprintf(fp, "\n");
    }
    fprintf(fp, "\n \n");
    fclose(fp);
}

void EveryPoint(char cover[][_Length_][Pool], struct Location loc, int turn)
{
    FILE *fp;
    fp = fopen("¼ÇÂ¼.txt", "a");
    if (turn)
    {
        fprintf(fp, "White:");
    }
    else
    {
        fprintf(fp, "Black:");
    }
    fprintf(fp, "X:%d,Y:%d,count:%d,white:", loc.X, loc.Y, cover[loc.Y][loc.X][0]);
    for (size_t i = 1; i < 5; i++)
    {
        fprintf(fp, "%d ", cover[loc.Y][loc.X][i]);
    }
    fprintf(fp, "black:");
    for (size_t i = 5; i < 9; i++)
    {
        fprintf(fp, "%d ", cover[loc.Y][loc.X][i]);
    }
    fprintf(fp, "\n");
    fclose(fp);
}