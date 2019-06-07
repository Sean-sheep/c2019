#include "Menu.h"

int main(int argc, char const *argv[])
{
    char board[Height][Length] = {
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

    int turn = 0;
    boolean win = 1;
    struct Location loc = {0, 0};
    char cover[Height][Length][Pool] = {0};
    srand((unsigned)time(NULL));
    system("color f0");

    InitRecord(); //������

    COORD coord;                                         //��Ļ�ϵ�����
    HANDLE handle_out = GetStdHandle(STD_OUTPUT_HANDLE); //��ñ�׼����豸���
    CONSOLE_SCREEN_BUFFER_INFO csbi;                     //����̨��Ļ��������Ϣ
    CONSOLE_CURSOR_INFO cci;                             //��������Ϣ�ṹ��
    GetConsoleCursorInfo(handle_out, &cci);              //��õ�ǰ�����Ϣ
    coord.X = 0;                                         //��ʼ��������ֵ
    coord.Y = 0;                                         //��ʼ��������ֵ
    cci.dwSize = 100;                                    //���ù��ߴ�ֵΪ100
    SetConsoleCursorInfo(handle_out, &cci);              //���ù��ߴ�
    GetConsoleScreenBufferInfo(handle_out, &csbi);       //��ȡ����̨������Ϣ(��Ҫ�ǻ�ȡ�������)

    printf(
        "                           �X�T�T�T�T�T�T�T�T�T�T�[\n"
        "                           �U                    �U\n"
        "                           �U   �밴���ּ�ѡ��   �U\n"
        "                           �U                    �U\n"
        "                           �U  1 - ������Ϸ      �U\n"
        "                           �U  2 - ˫����Ϸ      �U\n"
        "                           �U  3 - �˳�����      �U\n"
        "                           �U                    �U\n"
        "                           �^�T�T�T�T�T�T�T�T�T�T�a\n");
    printf("\n PS��������Ϸ�� w s a d �����������ң��ո�����ӣ���������\n");

    switch (getch() - 48)
    {
    case 1:
        turn = SinglePlayer(board, turn, win, loc, cover, coord, handle_out);
        break;

    case 2:
        turn = TwoPlayer(board, turn, win, loc, cover, coord, handle_out);
        break;

    default:
        return 0;
    }

    cci.dwSize = 20;                             //���ù��ߴ�ֵΪ20
    coord.X = 0;                                 //����������ֵ
    coord.Y = Height - 1;                        //����������ֵ
    SetConsoleCursorInfo(handle_out, &cci);      //���ù��ߴ�
    SetConsoleCursorPosition(handle_out, coord); //���ù��λ��

    switch (turn % 2) //��Ϊ����ʱturn++�����Է�˫����,�굥����
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

boolean TwoPlayer(char board[Height][Length], int turn, boolean win, struct Location loc, char cover[Height][Length][Pool], COORD coord, HANDLE handle_out)
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
            if (PutChess(&board[coord.Y + 1][coord.X / 2 + 1], turn))
            {
                loc.Y = coord.Y + 1;
                loc.X = coord.X / 2 + 1;
                DrawCover(cover, board, loc, turn % 2);
                win = WinCheck(cover, loc, turn % 2);
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
    return turn % 2;
}

boolean SinglePlayer(char board[Height][Length], int turn, boolean win, struct Location loc, char cover[Height][Length][Pool], COORD coord, HANDLE handle_out)
{
    int t = 0;

    system("cls");
    PrintBoard(board);
    SetConsoleCursorPosition(handle_out, coord);

    for (; win == 1;)
    {
        if (turn % 2) //�굥����ִ����
        {
            loc = AI(cover, board);
            PutChess(&board[loc.Y][loc.X], turn);
            DrawCover(cover, board, loc, turn % 2);
            win = WinCheck(cover, loc, turn % 2);
            ++turn;
            system("cls");
            PrintBoard(board);
            coord.Y = loc.Y - 1;
            coord.X = (loc.X - 1) * 2;
            SetConsoleCursorPosition(handle_out, coord);
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
                if (PutChess(&board[coord.Y + 1][coord.X / 2 + 1], turn))
                {
                    loc.Y = coord.Y + 1;
                    loc.X = coord.X / 2 + 1;
                    DrawCover(cover, board, loc, turn % 2);
                    win = WinCheck(cover, loc, turn % 2);
                    ++turn;
                    system("cls");
                    PrintBoard(board);
                    SetConsoleCursorPosition(handle_out, coord);
                }
                break;

            default:
                break;
            }
        }
    }
    return turn % 2;
}