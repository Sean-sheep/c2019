#if !defined(_Cover_H)
#define Cover_H

// #include "AI.h"
#include "Test.h"
#include "Const.h"

#include <stdio.h>
#include <windows.h>

struct Location AI(int cover[][_Length][10], int board[][_Length], int turn);
int Decide(int cover[][_Length][10], int board[][_Length], struct Location *ansP, int extro);
int Point(int cover[][_Length][10], int board[][_Length], struct Location loc[]);

//�����¸���ļ�ֵ�������а�����ǰ����¸�������λ��,���ذ׷ֶԺڷ�֮��
int CountScore(int cover[][_Length][10], struct Location loc, int option, int board[][_Length], int dY, int dX);

//���ذ˷���ֵ֮��
int DrawCover(int cover[][_Length][10], int board[][_Length], struct Location loc, int turn);

//�������⴫��CountScore���صĲ�ֵ
int ChangeSocreOfLine(int cover[][_Length][10], int board[][_Length], struct Location loc, int Y, int X, int option);

#endif