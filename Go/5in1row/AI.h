#if !defined(_AI_H)
#define AI_H

#include "Test.h"
#include "Const.h"
#include "Cover.h"

#include <stdio.h>

//������߽��
struct Location AI(unsigned char cover[][_Length][10], unsigned char board[][_Length], int turn);

//������ѭ����
struct Vertex Decide(struct Limit lmt, unsigned char cover[][_Length][10], unsigned char board[][_Length], int found, unsigned char extro);

//Ѱ�Ҹ߼�ֵ�㴢���ڽ��ܵ��������в�ͳ�Ƹ���t(<=20)
unsigned char findPoints(unsigned char cover[][_Length][10], unsigned char board[][_Length], struct Location loc[]);

#endif