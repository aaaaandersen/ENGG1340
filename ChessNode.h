#pragma once
#include<iostream>
#include<vector>   
#include<stdio.h>
#include<stdlib.h>
#include<ctime> 
#define BLACK 1  
#define WHITE 2
using namespace std;

class ChessNode
{
public:
    // Initialize
    ChessNode();
    // Place chess piece 
    void SetLocation(int x, int y);
    // Player
    void SetPlayerId(int id);
    // Player places chess piece
    void SetChessNode(int x, int y, int id);
    // Return x coordinate of placed chess piece
    int GetLocationX();
    // Return y coordinate of placed chess piece
    int GetLocationY();
    // Return player
    int GetPlayerId();

    // Delay
    void Delay(int time);
private:
    int m_x;        // x coordinate of placed chess piece
    int m_y;        // y coordinate of placed chess piece
    int player_id; // Player
};