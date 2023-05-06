#include "ChessNode.h"

ChessNode::ChessNode()
{
	this->m_x = 0;
	this->m_y = 0;
	this->player_id = -1;
}

void ChessNode::SetLocation(int x, int y)
{
	this->m_x = x;
	this->m_y = y;
}

void ChessNode::SetPlayerId(int id)
{
	this->player_id = id;
}

void ChessNode::SetChessNode(int x, int y, int id)
{
	this->m_x = x;
	this->m_y = y;
	this->player_id = id;
}

int ChessNode::GetLocationX()
{
	return m_x;
}

int ChessNode::GetLocationY()
{
	return m_y;
}

int ChessNode::GetPlayerId()
{
	return player_id;
}

void ChessNode::Delay(int time)
{
	clock_t   now = clock();

	while (clock() - now < time);
}
