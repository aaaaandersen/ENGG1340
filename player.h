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

    playerData playerStats;
    itemData playerItems[4];

    playerData modify_player_stats(int index, std::string value);
    itemData change_item_amount(itemData* items, int itemIndex, int amount);
    int get_weapon_data(int weaponIndex);
    int get_armour_data(int weaponIndex);
};

#endif
