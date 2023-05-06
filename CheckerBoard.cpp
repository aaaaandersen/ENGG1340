#include "CheckerBoard1.h"

CheckerBoard::CheckerBoard(int size)
{
	this->Size = size;
	board = new ChessNode * [size + 2];
	for (int i = 0; i < size + 2; i++)
	{
		board[i] = new ChessNode[size + 2];
		for (int j = 0; j < size + 2; j++)
		{
			board[i][j].SetChessNode(i, j, -1);
		}
	}
}

CheckerBoard::~CheckerBoard()
{
	for (int i = 0; i < Size + 2; i++)
	{
		delete[] board[i];
		board[i] = NULL;
	}
	delete board;
	board = NULL;
}

void CheckerBoard::PlaceNode(int x, int y, int id)
{
	if (board[x][y].GetPlayerId() != -1)
	{
		return;
	}
	if (x >= 1 && y >= 1 && x <= Size && y <= Size)
	{
		board[x][y].SetChessNode(x, y, id);
		AddStep(board[x][y]);
	}
}

void CheckerBoard::AddStep(ChessNode a)
{
	route1.push(a);
}

ChessNode CheckerBoard::ShowNode(int x, int y)
{
	if (x >= 1 && y >= 1 && x <= Size && y <= Size) 
	{
		return board[x][y];
	}
	return board[0][0];
}

ChessNode CheckerBoard::ShowRecentStep()
{
	if (!route1.empty()) 
	{
		return route1.top();
	}
	return board[0][0];
}

void CheckerBoard::RetractNode()
{
	if (!route1.empty()) 
	{
		ChessNode tmp = route1.top();
		board[tmp.GetLocationX()][tmp.GetLocationY()].SetChessNode(tmp.GetLocationX(), tmp.GetLocationY(), -1);
		route1.pop();
	}
}

void CheckerBoard::Display()
{
	cout << "\t";
	for (int i = 1; i <= Size; i++) 
	{
		cout << i << "\t";
	}
	cout << endl;

	for (int i = 1; i <= Size; i++)
	{
		cout << i << "\t";
		for (int j = 1; j <= Size; j++) 
		{
			if (board[i][j].GetPlayerId() == BLACK) 
			{
				cout << "X\t";
			}
			else if (board[i][j].GetPlayerId() == WHITE) 
			{
				cout << "O\t";
			}
			else 
			{
				cout << "■\t";
			}
		}

		for (int j = 1; j <= 4; j++)
		{
			cout << endl;
		}
	}
}

void CheckerBoard::StorageRoute()
{
	while (!route1.empty()) 
	{
		route2.push(route1.top());
		route1.pop();
	}

	ofstream ofs;
	ofs.open("test.txt", ios::out);

	while (!route2.empty()) {
		ofs << char(route2.top().GetLocationX() + 48);
		ofs << " ";
		ofs << char(route2.top().GetLocationY() + 48);
		ofs << " ";
		ofs << char(route2.top().GetPlayerId() + 48);
		ofs << "\n";
		route2.pop();
	}
	ofs.close();
}

void CheckerBoard::DeleteRoute()
{
	while (!route1.empty())
	{
		route2.push(route1.top());
		route1.pop();
	}
	
	int i = 0;
	ifstream intf("test.txt");
	ofstream out("tmp.txt");

	string str1;

	while (intf >> str1)
	{
		if (i == 0)
		{
			i = 1;
			continue;
		}
		out << str1 << endl;
	}

	out.close();
	intf.close();

	ifstream intff("tmp.txt");
	ofstream outt("test.txt");
	while (intff >> str1)
	{
		outt << str1 << endl;
	}
	intff.close();
	outt.close();
	remove("tmp.txt");
	cout << "Deleted successfully!" << endl;
}

