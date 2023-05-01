#ifndef ENEMY_H
#define ENEMY_H

#include <string>

struct enemyData {
    std::string name;
    int HP;
    int ATK;
    int DEF;
    int EXP;
};

enemyData get_enemy_data(int enemyIndex, int mapIndex);

#endif // ENEMY_H