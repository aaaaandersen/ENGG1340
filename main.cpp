#include <iostream>
#include "enemy.h"
#include "player.h"
#include "map.h"
#include "save.h"

void main_menu() {
    std::cout << "Welcome to the Text-based RPG Game!" << std::endl;
    std::cout << "1. New Game" << std::endl;
    std::cout << "2. Load Game" << std::endl;
    std::cout << "3. Quit" << std::endl;
}

player::playerData setup_player() {
    player::playerData newPlayer;
    std::string playerName;

    std::cout << "Enter your character's name: ";
    std::cin >> playerName;
    newPlayer.name = playerName;
    newPlayer.HP = 100;
    newPlayer.EXP = 0;
    newPlayer.weapon = 0;
    newPlayer.armour = 0;

    return newPlayer;
}

void game_loop(player::playerData &playerData) {
    bool running = true;

    while (running) {
        // Handle user input, update game state, display game state, etc.
        // Use playerData to access and modify the player's information.

        // For example, you can display the player's stats like this:
        std::cout << "Player: " << playerData.name << std::endl;
        std::cout << "HP: " << playerData.HP << std::endl;
        std::cout << "EXP: " << playerData.EXP << std::endl;

        // Here, you can add the game logic, such as:
        // - Moving between maps
        // - Encountering and battling enemies
        // - Managing inventory and equipment

        // For now, we'll just add a simple option to exit the game loop:
        int input;
        std::cout << "Enter 0 to quit the game loop: ";
        std::cin >> input;
        if (input == 0) {
            running = false;
        }
    }
}

void new_game() {
    player::playerData currentPlayer = setup_player();
    game_loop(currentPlayer);
}

void load_game() {
    std::string saveFileName;
    std::cout << "Enter the name of the save file to load: ";
    std::cin >> saveFileName;

    // Assuming you've added a loadGame function in save.h and save.cpp
    Player loadedPlayer = loadGame(saveFileName);
    game_loop(loadedPlayer);
}

int main() {
    int choice = 0;

    while (choice != 3) {
        main_menu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                new_game();
                break;
            case 2:
                load_game();
                break;
            case 3:
                std::cout << "Thank you for playing! Goodbye!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please enter a number between 1 and 3." << std::endl;
                break;
        }
    }

    return 0;
}
