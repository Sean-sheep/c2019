#if !defined(_Cover_H)
#define Cover_H

// #include "AI.h"
#include "Test.h"
#include "Const.h"

#include <stdio.h>
#include <windows.h>

struct Location AI(unsigned char cover[][_Length][10], unsigned char board[][_Length], int turn);
struct Vertex Decide(struct Limit lmt, unsigned char cover[][_Length][10], unsigned char board[][_Length], int found, unsigned char extro);
unsigned char findPoints(unsigned char cover[][_Length][10], unsigned char board[][_Length], struct Location loc[]);

//�����¸���ļ�ֵ�������а����¸���Ե�ǰ������λ��,��������(����Ϊ��)
short CountScore(unsigned char cover[][_Length][10], struct Location loc, unsigned char option, unsigned char prevalue, unsigned char board[][_Length], char dY, char dX);

//���ذ˷���ֵ֮��
int DrawCover(unsigned char cover[][_Length][10], unsigned char board[][_Length], struct Location loc, int turn);

//�������⴫��CountScore���صĲ�ֵ
short ChangeSocreOfLine(unsigned char cover[][_Length][10], unsigned char board[][_Length], struct Location loc, char Y, char X, unsigned char option);

#endif