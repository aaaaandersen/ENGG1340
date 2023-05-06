### Introduction of our team
GROUP NUMBER: 73

TEAM MEMBERS:
Chen Junjie 3036079502
Gu Shenghao  3036103638
Tse Siu Yeung  3036067690
Zhang Diyu  3036104058




### Introduction of our game
Gobang————Players take turn to place a piece of the certain type in  
          the board, and the first person to connect the pieces in a line wins;

          The size of board could be saved by players, normally between 5 and 15;

          If player enters coordinates for a piece that exceed the size of the board, he has to return to the menu by entering '0';

          Two modes to choose: player VS player or player VS computer;




### How we meet the 5 requirements
1. •  Generation of random game sets or events

In order to implement a random set of games or events for this project, we deliberately set up an extra function in the our game - a human-computer match, i.e. the player plays against the computer, while the computer drops the pieces in a random way, completing the above requirement.

2. •  Data structures for storing game status

The data structure for storing the game state is mainly the stack in the STL template. The coordinates of each piece will go into the stack, and then the stack will be pressed and popped to make the pieces appear on the board.

3. •  Dynamic memory management

Dynamic memory management is mainly used to set the size of the board. The game has requirements: 
Each time you start the game you will be asked to set the size of the board, so this size is achieved by using new to open up a section of memory and create a two-dimensional array for the board, which avoids wasting memory. 

4. •  File input/output (e.g., for loading/saving game status)

The input and output of the file is mainly used to save the game state. When saving the game, it will first determine if the game currently exists. If it does, it will be saved. If not, it will indicate that the board does not currently exist. Besides, the main menu of the game has the input and deletion options of the file.

5.  •  Program codes in multiple files
The classes are used to encapsulate the pieces, the board and the user, so that it is clearer when the functions are called, and also provides a convenient way to debug the code. The following are the classes we use in the game.
 `class CheckerBoard`
 `class ChessNode`
 `class Manager`
 
 ### Brief overview of the `Manager.cpp` class and its methods
 
1. `Manager()`: Constructor to initialize the chessboard size.
2. `Run()`: Executes the game.
3. `SizeIsRight()`: Checks if the chessboard size is correct.
4. `DeleteCheckerBoard()`: Deletes the current chessboard.
5. `DeleteCheckerBoard_Max()`: Deletes the maximum chessboard.
6. `RunNewGame()`: Starts a new game.
7. `RunNowGame()`: Resumes the current game.
8. `SetSize()`: Sets the size of the chessboard.
9. `ShowGameInf()`: Displays game-related information.
10. `JudgeGame()`: Determines the game outcome.
11. `StorageRouteMax()`: Stores the game route.
12. `ReadRoute()`: Reads the game route.
13. `AI_and_Person()`: Handles gameplay between the AI and a person.
14. `Delay(int time)`: Adds a delay to the game.

The `Manager` class also has two public member variables:
1. `int CheckerBoardSize`: Represents the size of the chessboard.
2. `CheckerBoard* checkerboard`: A pointer to a `CheckerBoard` object representing the game's chessboard.
 


### Compile Instructions

Run ```make ``` to compile the game.

Do ```./chess``` to start the game.

 
 
 




