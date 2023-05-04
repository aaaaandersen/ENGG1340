
#ifndef SAVE_H
#define SAVE_H

#include "player.h"

// 保存玩家数据到文件
void saveGame(const player::playerData &playerData, const std::string &filename);

// 从文件加载先前保存的玩家数据
player::playerData loadGame(const std::string &filename);  

#endif
