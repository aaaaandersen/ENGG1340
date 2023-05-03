// save.h
#pragma once
#include <string>
#include "player.h"

void saveGame(const player::playerData &playerData, const std::string &filename);
player::playerData loadGame(const std::string &filename);
