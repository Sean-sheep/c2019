#include "WareHouse.h"

int main(int argc, char const *argv[])
{
    int option = 0;

    system("color f9");
    system("mode con cols=80 lines=26");

    for (size_t i = 1; i;)
    {
        system("cls");
        printf(
            "                           �X�T�T�T�T�T�T�T�T�T�T�[\n"
            "                           �U                    �U\n"
            "                           �U   ����������ѡ��   �U\n"
            "                           �U                    �U\n"
            "                           �U  1 - ��ʾ����б�  �U\n"
            "                           �U  2 - ���          �U\n"
            "                           �U  3 - ����          �U\n"
            "                           �U  4 - �˳�����      �U\n"
            "                           �U                    �U\n"
            "                           �^�T�T�T�T�T�T�T�T�T�T�a\n");
        
        //scanf("%d", &option);
        option = getch();
        switch (option - 48)
        {
        case 1:
            printf("��ʾ����б�\n");
            i = Print();
            break;

        case 2:
            printf("��⣺\n");
            i = Inport();
            break;

        case 3:
            printf("���⣺\n");
            i = Outport();
            break;

        case 4:
            i = 0;
            break;

        default:
            printf("�������\n");
            system("pause");
            break;
        }
    }
    return 0;
}
