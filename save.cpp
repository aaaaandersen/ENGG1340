#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

struct Item {
    std::string name;
    int quantity;
};

struct Equipment {
    std::string name;
    int attack;
    int defense;
};

struct Player {
    std::string name;
    int health;
    int attack;
    int defense;
    int money;
    std::vector<Item> items;
    std::map<std::string, Equipment> equipments;
    std::map<std::string, bool> mapProgress;
};

void saveGame(const Player& player, const std::string& saveFileName) {
    std::ofstream saveFile(saveFileName, std::ios::binary);

    if (!saveFile.is_open()) {
        std::cerr << “CANNOT OPEN FILE: " << saveFileName << std::endl;
        return;
    }

    // 保存基本信息
    saveFile.write(reinterpret_cast<const char*>(&player.health), sizeof(player.health));
    saveFile.write(reinterpret_cast<const char*>(&player.attack), sizeof(player.attack));
    saveFile.write(reinterpret_cast<const char*>(&player.defense), sizeof(player.defense));
    saveFile.write(reinterpret_cast<const char*>(&player.money), sizeof(player.money));

    // 保存物品信息
    int itemsSize = player.items.size();
    saveFile.write(reinterpret_cast<const char*>(&itemsSize), sizeof(itemsSize));
    for (const auto& item : player.items) {
        int itemNameLength = item.name.size();
        saveFile.write(reinterpret_cast<const char*>(&itemNameLength), sizeof(itemNameLength));
        saveFile.write(item.name.c_str(), itemNameLength);
        saveFile.write(reinterpret_cast<const char*>(&item.quantity), sizeof(item.quantity));
    }

    // 保存装备信息
    int equipmentSize = player.equipments.size();
    saveFile.write(reinterpret_cast<const char*>(&equipmentSize), sizeof(equipmentSize));
    for (const auto& equip : player.equipments) {
        int equipNameLength = equip.first.size();
        saveFile.write(reinterpret_cast<const char*>(&equipNameLength), sizeof(equipNameLength));
        saveFile.write(equip.first.c_str(), equipNameLength);
        saveFile.write(reinterpret_cast<const char*>(&equip.second.attack), sizeof(equip.second.attack));
        saveFile.write(reinterpret_cast<const char*>(&equip.second.defense), sizeof(equip.second.defense));
    }

    // 保存地图进度信息
    int mapProgressSize = player.mapProgress.size();
    saveFile.write(reinterpret_cast<const char*>(&mapProgressSize), sizeof(mapProgressSize));
    for (const auto& progress : player.mapProgress) {
        int mapNameLength = progress.first.size();
        saveFile.write(reinterpret_cast<const char*>(&mapNameLength), sizeof(mapNameLength));
        saveFile.write(progress.first.c_str(), mapNameLength);
        saveFile.write(reinterpret_cast<const char*>(&progress.second), sizeof(progress.second));
    }

    saveFile.close();
    std::cout << “SAVED: " << saveFileName << std::endl;
}

int main() {
    Player player{“Player1", 100, 50, 30, 1000,
                  {{"Apple", 5}, {"Potion", 3}},
                  {{"Sword", {30, 10}}, {"Shield", {10, 30}}},
                  {{"Map1", true}, {"Map2", false}, {"Map3
