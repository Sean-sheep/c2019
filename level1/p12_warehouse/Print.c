#include "WareHouse.h"

int Print()
{
    struct Goods goods;
    FILE *fp;

    fp = fopen("����¼.txt", "r");
    while (fscanf(fp, "%s%s%d", &goods.name, &goods.model, &goods.quantity) != EOF)
    {
        printf("\nƷ����%s  �ͺţ�%s  ������%d", goods.name, goods.model, goods.quantity);
    }
    fclose(fp);
    printf("\n");
    system("pause");
    return 1;
}