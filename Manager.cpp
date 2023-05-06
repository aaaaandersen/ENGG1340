#include "Manager.h"

Manager::Manager()
{
	this->CheckerBoardSize = 0;
}

void Manager::Run()
{
	int choice = -1;
	while (choice != 1) {
		system("color 7");
		std::cout << "\t\tGobang game menu" << endl;
		std::cout << "(1) Close the client" << endl;
		std::cout << "(2) Start a new game" << endl;
		std::cout << "(3) Set the board size" <<endl;
		std::cout << "(4) Delete the current game" << endl;
		std::cout << "(5) Enter the current game" << endl;
		std::cout << "(6) Display game-related information" << endl;
		std::cout << "(7) The current game archive" << endl;
		std::cout << "(8) Display the stored route " << endl;
		std::cout << "(9) The man-machine war" << endl;
		std::cout << "Enter the Numbers and press enter: ";
		cin >> choice;
		std::cout << endl;
		if (choice == 2)
		{
			RunNewGame();
		}
		else if (choice == 3) 
		{
			SetSize();
		}
		else if (choice == 4) 
		{
			DeleteCheckerBoard_Max();
		}
		else if (choice == 5) 
		{
			RunNowGame();
		}
		else if (choice == 6) 
		{
			ShowGameInf();
		}
		else if (choice == 7) 
		{
			StorageRouteMax();
		}
		else if (choice == 8)
		{
			ReadRoute();
		}
		else if (choice == 1)
		{
			system("color 3D");
			cout << "I wish you have a good time!";			
			Delay(2000);
			exit(0);
		}
		else if (choice == 9)
		{
			AI_and_Person();
		}
		else
		{
			cout << "No current option, please input again!";
		}
		cout << endl;
		cout << "-----------------------------------------------" << endl;
		Delay(2000);
		system("cls");
	}
}

bool Manager::SizeIsRight()
{
	if (CheckerBoardSize == 0)
	{
		return true;
	}
	return false;
}

void Manager::DeleteCheckerBoard()
{
	delete checkerboard;
	checkerboard = NULL;
}

void Manager::DeleteCheckerBoard_Max()
{
	checkerboard->DeleteRoute();
}

void Manager::RunNewGame()
{
	int x ;
	int y ;
	int id ;

	if (CheckerBoardSize == 0)
	{
		cout << "The current size is zero, please set the board size" << endl;
		Delay(700);
		return;
	}
	system("cls");
	system("color 70");
	DeleteCheckerBoard();
	checkerboard = new CheckerBoard(CheckerBoardSize);
	checkerboard->Display();
	
	while (1)
	{
		//       
		if (checkerboard->ShowRecentStep().GetPlayerId() == -1)
		{
			id = BLACK;
		}
		else if (checkerboard->ShowRecentStep().GetPlayerId() == WHITE)
		{
			id = BLACK;
		}
		else if (checkerboard->ShowRecentStep().GetPlayerId() == BLACK)
		{
			id = WHITE;
		}
		else 
		{
			cout << "Program error, please open the game again" << endl;
		}

		cout << "The player " << id << "  Please enter the coordinates of the moving piece  ";
		cin >> x >> y;

		Delay(1000);
		system("cls");
		if (x > CheckerBoardSize || y > CheckerBoardSize || x < 1 || y < 1)
		{
			cout << "invalid coordinates, please input again! (you can return to the menu by entering '0')" << endl;
			int choice;
			cin >> choice;
			if (choice == 0)
			{
				break;
			}
			else
			{
				Delay(1000);
				system("cls");
				checkerboard->Display();
				continue;
			}
		}	

		checkerboard->PlaceNode(x, y, id);
		checkerboard->Display();
		if (JudgeGame()) 
		{
			system("color 7");
			system("cls");
			cout << "The game victory" << endl;
			Delay(2000);
			break;
		}
		else 
		{
			cout << "No winner" << endl;
			continue;
		}
	}
	
}

void Manager::RunNowGame()
{
	system("color 70");
	int x;
	int y;
	int id = -1;

	if (checkerboard == nullptr)
	{
		cout << "In the current background, game is not running" << endl;
		return;
	}
	system("cls");
	checkerboard->Display();

	while (1)
	{
		//       
		if (checkerboard->ShowRecentStep().GetPlayerId() == -1)
		{
			id = BLACK;
		}
		else if (checkerboard->ShowRecentStep().GetPlayerId() == WHITE)
		{
			id = BLACK;
		}
		else if (checkerboard->ShowRecentStep().GetPlayerId() == BLACK)
		{
			id = WHITE;
		}
		else
		{
			cout << "Program error, please open the game again" << endl;
		}

		cout << "The player" << id << "  Please enter the coordinates of the moving piece";
		cin >> x >> y;
		
		Delay(1000);
		system("cls");
		if (x > CheckerBoardSize || y > CheckerBoardSize || x < 1 || y < 1)
		{
			cout << "invalid coordinates, please input again! (you can return to the menu by entering '0')" << endl;
			int choice;
			cin >> choice;
			if (choice == 0)
			{
				break;
			}
			else
			{
				Delay(1000);
				system("cls");
				checkerboard->Display();
				continue;
			}		
		}

		checkerboard->PlaceNode(x, y, id);
		checkerboard->Display();
		if (JudgeGame())
		{
			system("color 7");
			system("cls");
			cout << "The game victory!" << endl;
			Delay(2000);
			break;
		}
		else
		{
			cout << "No winner"<< endl;
			continue;
		}
	}
	system("cls");
}

void Manager::SetSize()
{
	cout << "Please enter the required board size: ";
	cin >> CheckerBoardSize;
	int x = 1;
	while (x != 0)
	{
			if (CheckerBoardSize >= 0 && CheckerBoardSize < 5)
			{
				cout << "  ->Is too small for the size of the board:" << CheckerBoardSize << endl;
				cout << "  ->Please input '0' and press enter" << endl;
				cout << "  ->Please input again need to board size ";
			}
			else if (CheckerBoardSize > 15)
			{
				cout << "  ->Sorry, the size of the board the maximum is 15 unit!" << endl;
				cout << "  ->Please input '0' and press enter" << endl;
				cout << "  ->Please input again need to board size ";
			}
			else if (CheckerBoardSize < 0)
			{
				cout << "  ->Board size can not be negative!!!!!!" << endl;
				cout << "  ->Please input '0' and press enter" << endl;
				cout << "  ->Please input again need to board size ";
			}
			else if (CheckerBoardSize >= 5 && CheckerBoardSize <= 15)
			{
				break;
			}

			cin >> CheckerBoardSize;
			x = CheckerBoardSize;
			cout << endl << endl;
	}
	cout << "  ->The size of the board set up successfully: " << CheckerBoardSize << endl;
}

void Manager::ShowGameInf()
{
	cout << "  Size of the current game " << CheckerBoardSize << endl;
	cout << "    Game developers: Chen Junjie,Gu Shenghao,Tse Siu Yeung,Zhang Diyu" << endl;
	cout << "    The game version:1.0.0" << endl;
	cout << "Whether the current board: ";
	if (checkerboard == nullptr) {
		cout << "no" << endl;
	}
	else {
		cout << "yes" << endl;
	}
}

bool Manager::JudgeGame()
{
	//  жϺ   
	for (int i = 1; i <= CheckerBoardSize; i++)
	{
		for (int j = 1; j <= CheckerBoardSize-4; j++)
		{
			if (checkerboard->ShowNode(i, j).GetPlayerId() == checkerboard->ShowNode(i, j + 1).GetPlayerId() &&
				checkerboard->ShowNode(i, j + 1).GetPlayerId() == checkerboard->ShowNode(i, j + 2).GetPlayerId() &&
				checkerboard->ShowNode(i, j + 2).GetPlayerId() == checkerboard->ShowNode(i, j + 3).GetPlayerId() &&
				checkerboard->ShowNode(i, j + 3).GetPlayerId() == checkerboard->ShowNode(i, j + 4).GetPlayerId() &&
				checkerboard->ShowNode(i, j).GetPlayerId() != -1)
			{
				return true;
			}
		}
	}
	
	// ж     
	for (int i = 1; i <= CheckerBoardSize - 4; i++)
	{
		for (int j = 1; j <= CheckerBoardSize ; j++)
		{
			if (checkerboard->ShowNode(i, j).GetPlayerId() == checkerboard->ShowNode(i + 1, j).GetPlayerId() &&
				checkerboard->ShowNode(i + 1, j ).GetPlayerId() == checkerboard->ShowNode(i + 2, j).GetPlayerId() &&
				checkerboard->ShowNode(i + 2, j ).GetPlayerId() == checkerboard->ShowNode(i + 3, j).GetPlayerId() &&
				checkerboard->ShowNode(i + 3, j ).GetPlayerId() == checkerboard->ShowNode(i + 4, j).GetPlayerId() &&
				checkerboard->ShowNode(i, j).GetPlayerId() != -1)
			{
				return true;
			}
		}
	}

	// ж    Խ   
	for (int i = CheckerBoardSize; i >= 5 ; i--)
	{
		for (int j = 1; j <= CheckerBoardSize - 4; j++)
		{
			if (checkerboard->ShowNode(i, j).GetPlayerId() == checkerboard->ShowNode(i - 1, j + 1).GetPlayerId() &&
				checkerboard->ShowNode(i - 1, j + 1).GetPlayerId() == checkerboard->ShowNode(i - 2, j + 2).GetPlayerId() &&
				checkerboard->ShowNode(i - 2, j + 2).GetPlayerId() == checkerboard->ShowNode(i - 3, j + 3).GetPlayerId() &&
				checkerboard->ShowNode(i - 3, j + 3).GetPlayerId() == checkerboard->ShowNode(i - 4, j + 4).GetPlayerId() &&
				checkerboard->ShowNode(i, j).GetPlayerId() != -1)
			{
				return true;
			}
		}
	}

	// жϸ  Խ   
	for (int i = 1, j = CheckerBoardSize; i <= CheckerBoardSize - 4; i++)
	{
		for (int j = CheckerBoardSize; j >= CheckerBoardSize - 4; j--)
		{
			if (checkerboard->ShowNode(i, j).GetPlayerId() == checkerboard->ShowNode(i + 1, j - 1).GetPlayerId() &&
				checkerboard->ShowNode(i + 1, j - 1).GetPlayerId() == checkerboard->ShowNode(i + 2, j - 2).GetPlayerId() &&
				checkerboard->ShowNode(i + 2, j - 2).GetPlayerId() == checkerboard->ShowNode(i + 3, j - 3).GetPlayerId() &&
				checkerboard->ShowNode(i + 3, j - 3).GetPlayerId() == checkerboard->ShowNode(i + 4, j - 4).GetPlayerId() &&
				checkerboard->ShowNode(i, j).GetPlayerId() != -1)
			{
				return true;
			}
		}
	}
	return false;
}

void Manager::StorageRouteMax()
{
	if (checkerboard == NULL)
	{
		cout << "No board, failure!" << endl;
		return;
	}
	checkerboard->StorageRoute();
	delete checkerboard;
	checkerboard = NULL;
	cout << "Board path has been stored in the file" << endl;
}

void Manager::ReadRoute()
{
	if (checkerboard != NULL)
	{
		DeleteCheckerBoard();
	}
	CheckerBoardSize = 10;
	checkerboard = new CheckerBoard(CheckerBoardSize);

	ifstream ifs;
	ifs.open("test.txt", ios::in);

	if (!ifs.is_open())
	{
		cout << "Test the .TXT file, read failure" << endl;
		return;
	}

	string xx;
	string yy;
	string dd;

	string buf;
	while (getline(ifs, buf))
	{
		xx = buf.substr(0, 1);
		int j = 0;
		string s = " ";
		for (int i = 0; i < buf.size(); i++)
		{
			string s2 = buf.substr(i, 1);
			if (s.compare(s2) == 0)
			{
				j++;
				if (j == 1)
				{
					yy = buf.substr(i + 1, 1);
				}
				else if (j == 2)
				{
					dd = buf.substr(i + 1, 1);
				}
			}
		}
		int xxx = (int)(xx[0] - 48);
		int yyy = (int)(yy[0] - 48);
		int ddd = (int)(dd[0] - 48);
		checkerboard->PlaceNode(xxx, yyy, ddd);
	}
	ifs.close();

	cout << " Route has been read! The diagram below: " << endl;
	checkerboard->Display();
}

void Manager::AI_and_Person()
{
	SetSize();

	int x;
	int y;
	int id = -1;

	system("cls");
	system("color 70");
	DeleteCheckerBoard();
	checkerboard = new CheckerBoard(CheckerBoardSize);
	checkerboard->Display();

	while (1)
	{
		//       
		if (checkerboard->ShowRecentStep().GetPlayerId() == -1)
		{
			id = BLACK;
		}
		else if (checkerboard->ShowRecentStep().GetPlayerId() == WHITE)
		{
			id = BLACK;
		}
		else if (checkerboard->ShowRecentStep().GetPlayerId() == BLACK)
		{
			id = WHITE;
		}
		else
		{
			cout << "Program error, please open the game again" << endl;
		}

		if (id == WHITE)
		{
			ChessNode temp;
			srand((unsigned)time(NULL));
			int x1 = 0, y1 = 0;
			if ((x1 = (rand() % (CheckerBoardSize - 1)) + 1) && (y1 = (rand() % (CheckerBoardSize - 1)) + 1))
			{
				if (checkerboard->ShowNode(x1, y1).GetPlayerId() == -1)
				{
					cout << "Computers are operating, please wait." << endl;
					Delay(1000);
					checkerboard->PlaceNode(x1, y1, id);
					checkerboard->Display();
					if (JudgeGame())
					{
						system("color 7");
						system("cls");
						cout << "Computer victory!" << endl;
						Delay(2000);
						break;
					}
					else
					{
						cout << "No winner" << endl;
						continue;
					}
				}
			}
		}
		else
		{
			cout << "The player" << "  Please enter the coordinates of the moving piece";
			cin >> x >> y;

			Delay(1000);
			system("cls");
			if (x > CheckerBoardSize || y > CheckerBoardSize || x < 1 || y < 1)
			{
				cout << "invalid coordinates, please input again! (you can return to the menu by entering '0')" << endl;
				int choice;
				cin >> choice;
				if (choice == 0)
				{
					break;
				}
				else
				{
					Delay(1000);
					system("cls");
					checkerboard->Display();
					continue;
				}
			}

			checkerboard->PlaceNode(x, y, id);
			checkerboard->Display();
			if (JudgeGame())
			{
				system("color 7");
				system("cls");
				cout << "The game victory!" << endl;
				Delay(2000);
				break;
			}
			else
			{
				cout << "No winner" << endl;
				continue;
			}
			cout << "The player" << "  Please enter the coordinates of the moving piece";
			cin >> x >> y;

			Delay(1000);
			system("cls");
			if (x > CheckerBoardSize || y > CheckerBoardSize || x < 1 || y < 1)
			{
				cout << "invalid coordinates, please input again! (you can return to the menu by entering '0')" << endl;
				int choice;
				cin >> choice;
				if (choice == 0)
				{
					break;
				}
				else
				{
					Delay(1000);
					system("cls");
					checkerboard->Display();
					continue;
				}
			}

			checkerboard->PlaceNode(x, y, id);
			checkerboard->Display();
			if (JudgeGame())
			{
				system("color 7");
				system("cls");
				cout << "The game victory!" << endl;
				Delay(2000);
				break;
			}
			else
			{
				cout << "No winner" << endl;
				continue;
			}
		}
	}
}

void Manager::Delay(int time)
{
	clock_t   now = clock();

	while (clock() - now < time);
}
