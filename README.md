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


#### How we meet the 5 requirements
1. In order to implement a random set of games or events for this project, we deliberately set up an extra function in the our game - a human-computer match, i.e. the player plays against the computer, while the computer drops the pieces in a random way, completing the above requirement.

2. The data structure for storing the game state is mainly the stack in the STL template. The coordinates of each piece will go into the stack, and then the stack will be pressed and popped to make the pieces appear on the board.

3. Dynamic memory management is mainly used to set the size of the board. The game has requirements: 
Each time you start the game you will be asked to set the size of the board, so this size is achieved by using new to open up a section of memory and create a two-dimensional array for the board, which avoids wasting memory. 

4. The input and output of the file is mainly used to save the game state. When saving the game, it will first determine if the game currently exists. If it does, it will be saved. If not, it will indicate that the board does not currently exist. Besides, the main menu of the game has the input and deletion options of the file.

5. The classes are used to encapsulate the pieces, the board and the user, so that it is clearer when the functions are called, and also provides a convenient way to debug the code. The following are the classes we use in the game.
 `class CheckerBoard`
 `class ChessNode`
 `class Manager`




