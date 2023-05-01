#include "enemy.h"
#include <stdexcept> 

// Initialize enemy information arrays
// {name,HP,ATK,DEF,EXP}
enemyData enemiesInMap1[] = {
    {"Goblin Thief", 30, 20, 10, 20},
    {"Goblin Warrior", 40, 10, 20, 20},
    {"Obese Goblin", 50, 5, 0, 30},
    {"Goblin Chief", 80, 50, 20, 100},
};

enemyData enemiesInMap2[] = {
    {"Skeleton Samurai", 70, 80, 40, 50},
    {"Headless Skeleton", 120, 60, 20, 50},
    {"Shielded Skeleton", 180, 40, 100, 60},
    {"King of Skeleton", 150, 100, 40, 500},
};

enemyData enemiesInMap3[] = {
    {"Ghost Gunner", 175, 150, 50, 80},
    {"Ghost Skirmisher", 240, 80, 100, 80},
    {"Ghost Knight", 300, 50, 200, 100},
    {"Gargoyle", 250, 200, 60, 1000},
};

enemyData finalBossInMap4 = {
    "Satan", 400, 300, 100, 0
};

// A function to get enemy information by mapIndex and enemyIndex
enemyData get_enemy_data(int enemyIndex, int mapIndex) {
    if (mapIndex == 1) {
        return enemiesInMap1[enemyIndex];
    }
    else if (mapIndex == 2) {
        return enemiesInMap2[enemyIndex];
    }
    else if (mapIndex == 3) {
        return enemiesInMap3[enemyIndex];
    }
    else if (mapIndex == 4) {
        return finalBossInMap4;
    }
    else {
        // If the map index is incorrect, throw an exception
        throw std::invalid_argument("Invalid map index");
    }
}
