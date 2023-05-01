#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class player {
public:
    struct playerData {
        std::string name;
        int HP;
        int EXP;
        int weapon;
        int armour;
        int trinket;
    };

    struct itemData {
        std::string name;
        int num;
        std::string description;
    };
    
    struct armouryData {
        std::string name;
        int stats;
        std::string description;
    };

private:
    playerData playerStats;
    itemData playerItems[4];
};

#endif // PLAYER_H
