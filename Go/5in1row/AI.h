#if !defined(_AI_)
#define _AI_

#include "Const.h"

#include <stdio.h>
#include <Windows.h>

struct Location Decide(char cover[][_Length_][Pool], char board[][_Length_]);
struct Location AI(char cover[][_Length_][Pool], char board[][_Length_]);
void CountScore(char cover[][_Length_][Pool], struct Location loc, int option, char board[][_Length_], char dY, char dX);//�����¸���ļ�ֵ�������а�����ǰ����¸�������λ��

#endif