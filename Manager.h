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
    // 初始化棋盘大小
    Manager();
    // 运行游戏
    void Run();
    // 判断棋盘大小是否正确
    bool SizeIsRight();
    // 删除棋盘
    void DeleteCheckerBoard();
    void DeleteCheckerBoard_Max();
    // 开始新的游戏
    void RunNewGame();
    // 进行现在游戏
    void RunNowGame();
    // 设置棋盘大小
    void SetSize();
    // 展示游戏开发信息
    void ShowGameInf();
    // 判断五子连线
    bool JudgeGame();
    // 储存游戏进度
    void StorageRouteMax();
    // 读取游戏路径
    void ReadRoute();
    // 人机大战
    void AI_and_Person();

    // 延时
    void Delay(int time);
public:
    int CheckerBoardSize;
    CheckerBoard* checkerboard;
};

