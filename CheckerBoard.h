#pragma once  
#include "ChessNode.h"
#include<stack>  
#include<iostream>
#include<vector>
#include<stdio.h>  
#include<stdlib.h>
#include<ctime>
#include<fstream>  
#include<string>  

using namespace std;
#define BLACK 1   
#define WHITE 2

class CheckerBoard
{
public:
    // Place a chess piece on the chessboard
    CheckerBoard(int size);
    // Release memory
    ~CheckerBoard();
    // Backtrack to place pieces
    void PlaceNode(int x, int y, int id);
    // Pop
    void AddStep(ChessNode);
    // Return chess piece
    ChessNode ShowNode(int x, int y);
    // Backtrack step
    ChessNode ShowRecentStep();
    // Regret chess piece
    void RetractNode();
    // Display chess pieces on the chessboard
    void Display();
    // Store path 
    void StorageRoute();
    // Delete path
    void DeleteRoute();
private:
    int Size;
    ChessNode** board;
    stack<ChessNode> route1;
    stack<ChessNode> route2;
};