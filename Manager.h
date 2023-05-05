#pragma once
#include "CheckerBoard.h"
#include "ChessNode.h"
#include <fstream>
#include <string>
#include <ctime>
#include <iostream>
#include <stdlib.h>
#define BLACK 1
#define WHITE 2
using namespace std;

class Manager 
{
public:
    // ��ʼ�����̴�С
    Manager();
    // ������Ϸ
    void Run();
    // �ж����̴�С�Ƿ���ȷ
    bool SizeIsRight();
    // ɾ������
    void DeleteCheckerBoard();
    void DeleteCheckerBoard_Max();
    // ��ʼ�µ���Ϸ
    void RunNewGame();
    // ����������Ϸ
    void RunNowGame();
    // �������̴�С
    void SetSize();
    // չʾ��Ϸ������Ϣ
    void ShowGameInf();
    // �ж���������
    bool JudgeGame();
    // ������Ϸ����
    void StorageRouteMax();
    // ��ȡ��Ϸ·��
    void ReadRoute();
    // �˻���ս
    void AI_and_Person();

    // ��ʱ
    void Delay(int time);
public:
    int CheckerBoardSize;
    CheckerBoard* checkerboard;
};

