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
    // Initialize the size of the chessboard
    Manager();
    // Run the game
    void Run();
    // Determine if the size of the chessboard is correct
    bool SizeIsRight();
    // Delete chessboard
    void DeleteCheckerBoard();
    void DeleteCheckerBoard_Max();
    // Start a new game 
    void RunNewGame();  
    // Continue the current game
    void RunNowGame();
    // Set the size of the chessboard
    void SetSize();   
    // Display game development information
    void ShowGameInf(); 
    // Judge five in a row
    bool JudgeGame();   
    // Save game progress
    void StorageRouteMax();  
    // Read game path
    void ReadRoute();  
    // Human vs AI 
    void AI_and_Person();

    // Delay
    void Delay(int time);  
public:
   int CheckerBoardSize; 
   CheckerBoard* checkerboard;
};
