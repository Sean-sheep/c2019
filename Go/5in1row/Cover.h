#if !defined(_Cover_H)
#define Cover_H

#include "Win.h"
#include "Const.h"

#include <stdio.h>
#include <windows.h>

//�����¸���ļ�ֵ�������а����¸���Ե�ǰ������λ��,��������(����Ϊ��)
short CountScore(unsigned char cover[][_Length][10], struct Location loc, unsigned char option, unsigned char prevalueOfDrct, unsigned char board[][_Length], char dY, char dX);
//����㷨��̫һ��
short CountScoreOfMid(unsigned char cover[][_Length][10], struct Location loc, unsigned char option, unsigned char board[][_Length], char dY, char dX);

//���ذ˷���ֵ֮��
int DrawCover(unsigned char cover[][_Length][10], unsigned char board[][_Length], struct Location loc, int turn);

//�������⴫��CountScore���صĲ�ֵ
short ChangeSocreOfLine(unsigned char cover[][_Length][10], unsigned char board[][_Length], struct Location loc, char Y, char X, unsigned char option);

#endif