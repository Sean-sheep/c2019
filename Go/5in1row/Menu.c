#include "Menu.h"

int main(int argc, int const *argv[])
{
    unsigned char board[Height][_Length] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 0},
        {0, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6, 0},
        {0, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6, 0},
        {0, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6, 0},
        {0, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6, 0},
        {0, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6, 0},
        {0, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6, 0},
        {0, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6, 0},
        {0, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6, 0},
        {0, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6, 0},
        {0, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6, 0},
        {0, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6, 0},
        {0, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6, 0},
        {0, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6, 0},
        {0, 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 9, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    int turn = 0; //传入原值,返回值%2
    boolean win = 1;
    struct Location loc = {0, 0};
    unsigned char cover[Height][_Length][10] = {0};
    srand((unsigned)time(NULL));
    system("color f0");

    // InitRecord(); //测试用

    COORD coord;                                         //屏幕上的坐标
    HANDLE handle_out = GetStdHandle(STD_OUTPUT_HANDLE); //获得标准输出设备句柄
    CONSOLE_SCREEN_BUFFER_INFO csbi;                     //控制台屏幕缓冲区信息
    CONSOLE_CURSOR_INFO cci;                             //定义光标信息结构体
    GetConsoleCursorInfo(handle_out, &cci);              //获得当前光标信息
    coord.X = 2;                                         //初始化行坐标值
    coord.Y = 1;                                         //初始化列坐标值
    cci.dwSize = 100;                                    //设置光标尺寸值为100
    SetConsoleCursorInfo(handle_out, &cci);              //设置光标尺寸
    GetConsoleScreenBufferInfo(handle_out, &csbi);       //获取控制台窗口信息(主要是获取光标坐标)

    printf(
        "                           ╔══════════╗\n"
        "                           ║                    ║\n"
        "                           ║   请按数字键选择   ║\n"
        "                           ║                    ║\n"
        "                           ║  1 - 单人游戏      ║\n"
        "                           ║  2 - 双人游戏      ║\n"
        "                           ║  3 - 退出程序      ║\n"
        "                           ║                    ║\n"
        "                           ╚══════════╝\n");
    printf("\n PS：进入游戏后 w s a d 控制上下左右,空格键落子,黑子先行\n");

    switch (getch() - 48)
    {
    case 1:
        turn = SinglePlayer(board, turn, win, loc, cover, coord, handle_out);
        break;

    case 2:
        turn = TwoPlayer(board, turn, win, loc, cover, coord, handle_out);
        break;
    // //  白子先手,然鹅还是弟弟
    // case 3:
    //     loc.Y = rand() % 5 + 5;
    //     loc.X = rand() % 5 + 5;
    //     PutChess(&board[loc.Y][loc.X], 1);
    //     // EveryPoint(cover, loc, turn); //Test
    //     // EveryStep(cover, board);      //Test
    //     DrawCover(cover, board, loc, 1);
    //     turn = SinglePlayer(board, turn, win, loc, cover, coord, handle_out);
    //     break;

    default:
        return 0;
    }

    cci.dwSize = 20;                             //设置光标尺寸值为20
    coord.X = 0;                                 //重设行坐标值
    coord.Y = Height;                            //重设列坐标值
    SetConsoleCursorInfo(handle_out, &cci);      //设置光标尺寸
    SetConsoleCursorPosition(handle_out, coord); //设置光标位置

    switch (turn) //因为结束时turn++,所以逢双白子,逢单黑子
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

boolean TwoPlayer(unsigned char board[Height][_Length], int turn, boolean win, struct Location loc, unsigned char cover[Height][_Length][10], COORD coord, HANDLE handle_out)
{
    system("cls");
    PrintBoard(board);
    SetConsoleCursorPosition(handle_out, coord);

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
            if (PutChess(&board[coord.Y][coord.X / 2], turn))
            {
                loc.Y = coord.Y;
                loc.X = coord.X / 2;
                DrawCover(cover, board, loc, turn);
                // EveryPoint(cover, loc, turn); //Test
                // EveryStep(cover, board);      //Test
                win = WinCheck(cover, loc, turn);
                ChangeBoard(turn);
                SetConsoleCursorPosition(handle_out, coord);
                ++turn;
            }
            break;

        default:
            break;
        }
    }
    return turn % 2;
}

boolean SinglePlayer(unsigned char board[Height][_Length], int turn, boolean win, struct Location loc, unsigned char cover[Height][_Length][10], COORD coord, HANDLE handle_out)
{
    int t = 0;

    system("cls");
    PrintBoard(board);
    SetConsoleCursorPosition(handle_out, coord);

    for (; win == 1;)
    {
        if (turn % 2) //逢单电脑执白子
        {
            loc = AI(cover, board, turn);
            PutChess(&board[loc.Y][loc.X], turn);
            DrawCover(cover, board, loc, turn);
            // EveryPoint(cover, loc, turn); //Test
            // EveryStep(cover, board);      //Test
            win = WinCheck(cover, loc, turn);
            coord.Y = loc.Y;
            coord.X = loc.X * 2;
            SetConsoleCursorPosition(handle_out, coord);
            ChangeBoard(turn);
            SetConsoleCursorPosition(handle_out, coord);
            ++turn;
        }
        else
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
                if (PutChess(&board[coord.Y][coord.X / 2], turn))
                {
                    loc.Y = coord.Y;
                    loc.X = coord.X / 2;
                    DrawCover(cover, board, loc, turn);
                    // EveryPoint(cover, loc, turn); //Test
                    // EveryStep(cover, board);      //Test
                    win = WinCheck(cover, loc, turn);
                    ChangeBoard(turn);
                    SetConsoleCursorPosition(handle_out, coord);
                    ++turn;
                }
                break;

            default:
                break;
            }
        }
    }
    return turn % 2;
}