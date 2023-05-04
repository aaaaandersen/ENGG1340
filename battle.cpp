#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "player.h"
#include "enemy.h"

using namespace std;

void startBattle(int mapIndex) {
    // Set the random number seed
    srand(time(NULL));

    // Define and initialize variables
    int enemyIndex = rand() % 3;
    int round = 1; // Round number starts at 1
    bool isPlayerTurn = true;

    // Create instances of player and enemy
    player myPlayer;
    enemyData enemy = get_enemy_data(enemyIndex, mapIndex);
    
    // Calculate player's attack and defense values
    int playerAtk = (myPlayer.playerStats.EXP / 20) + myPlayer.get_weapon_data(myPlayer.playerStats.weapon);
    int playerDef = (myPlayer.playerStats.EXP / 20) + myPlayer.get_armour_data(myPlayer.playerStats.weapon);

    // Game loop until one side's HP reaches 0
    while (myPlayer.playerStats.HP > 0 && enemy.HP > 0) {
        // Output current round information
        cout << "Round " << round << endl;
        cout << myPlayer.playerStats.name << "'s HP is " << myPlayer.playerStats.HP << endl;
        cout << enemy.name << "'s HP is " << enemy.HP << endl;

        if (isPlayerTurn) {
            if (isPlayerTurn) {
                // Ask player to choose between using an item or attacking
                cout << "Would you like to use an item or attack? (i/a)" << endl;
                char choice;
                cin >> choice;

                if (choice == 'i') {
                    // Use an item
                    // Show player's available items and have them choose one
                    // Apply the item's effect (heal HP, increase ATK, etc.)
                    for (int i = 0; i < sizeof(myPlayer.playerItems) / sizeof(player::itemData); i++) {
                        cout << "Item name: " << myPlayer.playerItems[i].name << "Quantity: " << myPlayer.playerItems[i].num << "Description: " << myPlayer.playerItems[i].description << endl;
                    }

                    int itemIndex;
                    while (true) {
                        cout << "Please select a item (enter the corresponding number)：" << endl;
                        for (int i = 0; i < sizeof(myPlayer.playerItems) / sizeof(myPlayer.playerItems[0]); i++) {
                            cout << i + 1 << ". " << myPlayer.playerItems[i].name << endl;
                        }
                        cin >> itemIndex;

                        // 确认玩家输入的数字是否有效
                        if (itemIndex < 1 || itemIndex > sizeof(myPlayer.playerItems) / sizeof(myPlayer.playerItems[0])) {
                            cout << "Invalid input!" << endl;
                        }
                        else {
                            break;
                        }
                    }

                    // 根据玩家选择的道具，执行相应的操作
                    switch (itemIndex) {
                    case 1:
                        // 使用Health potion
                        if (myPlayer.playerItems[0].num == 0) {
                            cout << "You have no Health potion" << endl;
                            break;
                        }
                        else {
                            myPlayer.playerStats.HP += 100;
                            myPlayer.playerItems[0].num - 1;
                            cout << "You used a Health potion to recover 100 HP" << endl;
                            break;
                        }
                    case 2:
                        // 使用Greater health potion
                        if (myPlayer.playerItems[1].num == 0) {
                            cout << "You have no Greater health potion" << endl;
                            break;
                        }
                        else {
                            myPlayer.playerStats.HP += 250;
                            myPlayer.playerItems[1].num - 1;
                            cout << "You used a Greater health potion to recover 250 HP" << endl;
                            break;
                        }
                    case 3:
                        // 使用Defense potion
                        if (myPlayer.playerItems[2].num == 0) {
                            cout << "You have no Defense potion potion" << endl;
                            break;
                        }
                        else {
                            playerDef += 50;
                            myPlayer.playerItems[2].num - 1;
                            cout << "You used a Defense potion to boost 50 defense points" << endl;
                            break;
                        }
                    }

                }
                else {
                    // Player attacks 
                    cout << myPlayer.playerStats.name << " attacks " << enemy.name << ", dealing " << playerAtk << " damage." << endl;
                    enemy.HP -= playerAtk;
                }
            }

            // Check if a winner has been decided
            if (enemy.HP <= 0) {
                cout << myPlayer.playerStats.name << " wins!" << endl;
                cout << myPlayer.playerStats.name << "'s remaining HP is " << myPlayer.playerStats.HP << endl;
                cout << enemy.name << "'s remaining HP is " << enemy.HP << endl;
                cout << endl;
                myPlayer.playerStats.EXP += enemy.EXP;
                return 1;
            }
        }
        else {
            // Enemy attacks
            cout << enemy.name << " attacks " << myPlayer.playerStats.name << ", dealing " << enemy.ATK << " damage." << endl;
            myPlayer.playerStats.HP -= enemy.ATK;

            // Check if a winner has been decided
            if (myPlayer.playerStats.HP <= 0) {
                cout << enemy.name << " wins!" << endl;
                cout << myPlayer.playerStats.name << " wins!" << endl;
                cout << myPlayer.playerStats.name << "'s remaining HP is " << myPlayer.playerStats.HP << endl;
                cout << enemy.name << "'s remaining HP is " << enemy.HP << endl;
                return 2;
            }
        }

        // Output current remaining HP information
        cout << myPlayer.playerStats.name << "'s remaining HP is " << myPlayer.playerStats.HP << endl;
        cout << enemy.name << "'s remaining HP is " << enemy.HP << endl;
        cout << endl;


        // Switch turn
        isPlayerTurn = !isPlayerTurn;
        round++;
    }
}
