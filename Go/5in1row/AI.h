#if !defined(_AI_H)
#define AI_H

#include "Const.h"

#include <stdio.h>
#include <Windows.h>

struct Location Decide(char cover[][Length][Pool], char board[][Length]);
struct Location AI(char cover[][Length][Pool], char board[][Length]);
void CountScore(char cover[][Length][Pool], struct Location loc, int option, char board[][Length], char dY, char dX);//�����¸���ļ�ֵ�������а�����ǰ����¸�������λ��

#endif