#include "WareHouse.h"

int Outport()

{

    /*
    *linebuffer����ȡ�ļ��е�һ�д���Ļ���
    *good2: ���ı��ж�ȡ���ļ�¼
    */
    struct Goods goods, good2;
    char linebuffer[512] = {0};
    int line_len = 0;
    int len = 0;
    FILE *fp;

    for (size_t i = 13; i == 13;)
    {
        printf("\nƷ����");
        scanf("%s", &goods.name);
        printf("�ͺţ�");
        scanf("%s", &goods.model);

        fp = fopen("����¼.txt", "r+");
        while (fgets(linebuffer, 512, fp))
        {
            line_len = strlen(linebuffer);
            len += line_len;

            sscanf(linebuffer, "%s%s%d", &good2.name, &good2.model, &good2.quantity);
            if (0 == strcmp(goods.name, good2.name) && 0 == strcmp(goods.model, good2.model))
            {
                /* �����Ѿ��ҵ�����Ҫд��λ�ã�������Ҫдλ�õġ�ͷ��*/
                len -= strlen(linebuffer);
                /* ʵ���ļ�λ�õ�ƫ�ƣ�Ϊд�ļ���׼��*/
                fseek(fp, len, SEEK_SET);
                for (;;)
                {
                    printf("������");
                    if (scanf("%d", &goods.quantity))
                    {
                        if (good2.quantity >= goods.quantity)
                        {
                            fprintf(fp, "\n%s %s %d", goods.name, goods.model, good2.quantity - goods.quantity);
                            break;
                        }
                        else
                        {
                            printf("��治�㣬����%d��\n", good2.quantity);
                            fflush(stdin);
                        }
                    }
                    else
                    {
                        printf("�������\n");
                        fflush(stdin);
                    }
                }
                break;
            }
        }
        fclose(fp);
        printf("\n���س��Լ�����Esc���˳�\n");
        i = getch();
    }
    return 1;
}