#include "Tic.h"

int main(int argc, char const *argv[])
{
    char turn = 0, board[3][3] = {
        {7, 8, 9},
        {4, 5, 6},
        {1, 2, 3}};


    system("color f0");
    PrintBoard(board);

    COORD coord;                                         //屏幕上的坐标
    HANDLE handle_out = GetStdHandle(STD_OUTPUT_HANDLE); //获得标准输出设备句柄
    CONSOLE_SCREEN_BUFFER_INFO csbi;                     //控制台屏幕缓冲区信息
    CONSOLE_CURSOR_INFO cci;                             //定义光标信息结构体
    GetConsoleCursorInfo(handle_out, &cci);              //获得当前光标信息
    coord.X = 0;                                         //初始化行坐标值
    coord.Y = 0;                                         //初始化列坐标值
    SetConsoleCursorPosition(handle_out, coord);         //实现初始化
    cci.dwSize = 100;                                    //设置光标尺寸值为100
    SetConsoleCursorInfo(handle_out, &cci);              //设置光标尺寸
    GetConsoleScreenBufferInfo(handle_out, &csbi);       //获取控制台窗口信息(主要是获取光标坐标)

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
