#include "Tic.h"

int main(int argc, char const *argv[])
{
    char turn = 0, board[3][3] = {
        {7, 8, 9},
        {4, 5, 6},
        {1, 2, 3}};


    system("color f0");
    PrintBoard(board);

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

        for (;;)
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
            board[coord.Y][coord.X/2] = PutChess(board[coord.Y][coord.X/2], &turn);
            system("cls");
            PrintBoard(board);
            SetConsoleCursorPosition(handle_out, coord);
            break;

        default:
            break;
        }
    }
    return 0;
}
