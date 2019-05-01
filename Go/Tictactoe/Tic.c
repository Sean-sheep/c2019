#include "Tic.h"

int main(int argc, char const *argv[])
{
    char board[5][5] = {
        {0, 0, 0, 0, 0},
        {0, 1, 2, 3, 0},
        {0, 4, 5, 6, 0},
        {0, 7, 8, 9, 0},
        {0, 0, 0, 0, 0}};

    int turn = 0;
    boolean win = 1;
    struct Location loc;
    struct Point cover[5][5];

    system("color f0");
    PrintBoard(board);
    for (size_t i = 0; i < 5; i++)
    {
        for (size_t j = 0; j < 5; j++)
        {
            cover[i][j] = InitCover(cover[i][j]);
        }
    }

    COORD coord;                                         //��Ļ�ϵ�����
    HANDLE handle_out = GetStdHandle(STD_OUTPUT_HANDLE); //��ñ�׼����豸���
    CONSOLE_SCREEN_BUFFER_INFO csbi;                     //����̨��Ļ��������Ϣ
    CONSOLE_CURSOR_INFO cci;                             //��������Ϣ�ṹ��
    GetConsoleCursorInfo(handle_out, &cci);              //��õ�ǰ�����Ϣ
    coord.X = 0;                                         //��ʼ��������ֵ
    coord.Y = 0;                                         //��ʼ��������ֵ
    SetConsoleCursorPosition(handle_out, coord);         //ʵ�ֳ�ʼ��
    cci.dwSize = 100;                                    //���ù��ߴ�ֵΪ100
    SetConsoleCursorInfo(handle_out, &cci);              //���ù��ߴ�
    GetConsoleScreenBufferInfo(handle_out, &csbi);       //��ȡ����̨������Ϣ(��Ҫ�ǻ�ȡ�������)

    for (; win == 1;)
    {
        switch (getch())
        {
        case 'w':
            coord.Y = ChangeRow('-', coord.Y);
            SetConsoleCursorPosition(handle_out, coord);
            break;

        case 's':
            coord.Y = ChangeRow('+', coord.Y);
            SetConsoleCursorPosition(handle_out, coord);
            break;

        case 'a':
            coord.X = ChangeLine('-', coord.X);
            SetConsoleCursorPosition(handle_out, coord);
            break;

        case 'd':
            coord.X = ChangeLine('+', coord.X);
            SetConsoleCursorPosition(handle_out, coord);
            break;

        case ' ':
            if (PutChess(&board[coord.Y + 1][coord.X / 2 + 1], turn))
            {
                loc.Y = coord.Y + 1;
                loc.X = coord.X / 2 + 1;
                DrawCover(cover, loc, turn % 2);
                win = WinCheck(cover[loc.Y][loc.X], board[loc.Y][loc.X], turn % 2);
                ++turn;
            }
            system("cls");
            PrintBoard(board);
            SetConsoleCursorPosition(handle_out, coord);
            break;

        default:
            break;
        }
    }

    cci.dwSize = 20;                             //���ù��ߴ�ֵΪ20
    coord.X = 0;                                 //����������ֵ
    coord.Y = 4;                                 //����������ֵ
    SetConsoleCursorInfo(handle_out, &cci);      //���ù��ߴ�
    SetConsoleCursorPosition(handle_out, coord); //���ù��λ��

    switch (turn % 2)
    {
    case 0:
        printf("The white win");
        break;

    case 1:
        printf("The black win");
        break;

    default:
        printf("Error");
        break;
    }
    system("pause");

    return 0;
}
