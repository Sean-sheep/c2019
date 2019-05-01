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

    cci.dwSize = 20;                             //设置光标尺寸值为20
    coord.X = 0;                                 //重设行坐标值
    coord.Y = 4;                                 //重设列坐标值
    SetConsoleCursorInfo(handle_out, &cci);      //设置光标尺寸
    SetConsoleCursorPosition(handle_out, coord); //设置光标位置

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
