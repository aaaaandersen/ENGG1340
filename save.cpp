// save.cpp
#include <iostream>
#include <fstream>
#include "save.h"
#include "player.h"

void saveGame(const player::playerData &playerData, const std::string &filename) {
    // Your existing saveGame function implementation
}

player::playerData loadGame(const std::string &filename) {
    player::playerData loadedPlayer;
    std::ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        std::cerr << "Error opening the save file: " << filename << std::endl;
        exit(1);
    }

    std::getline(inputFile, loadedPlayer.name);
    inputFile >> loadedPlayer.HP;
    inputFile >> loadedPlayer.EXP;
    inputFile >> loadedPlayer.weapon;
    inputFile >> loadedPlayer.armour;

    inputFile.close();
    return loadedPlayer;
}
