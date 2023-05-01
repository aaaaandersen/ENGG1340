#include "player.h"

// Struct to store player data
//{std::string name;int HP;int EXP;int weapon;int armour;int trinket;}
player::playerData playerStats = { "", 0, 0, 0, 0, 0, };

// Struct to store player items
//{std::string item1;int num;std::string descriptionl}
player::itemData playerItems[] = {
    {"Health potion", 0, "Restores 10% of the player's health."},
    {"Greater health potion", 0, "Restores 20% of the player's health."},
    {"Critical strike potion", 0, "Guarantees that the player's next attack will be a critical hit."},
    {"Defense potion", 0, "Grants the player immunity to the next enemy attack."},
};

// Struct to store armoury data
//{std::string name;int stats;std::string description;}
//to be added
player::itemData armouryData[] = {
    {"", 0, ""},
    {"", 0, ""},
    {"", 0, ""},
    {"", 0, ""},
};

// Function to modify player stats
// Takes an index and a value as parameters
// The index specifies which member variable of playerStats to modify
// The value can be either an integer or a string
player::playerData modify_player_stats(int index, std::string value) {
    if (index == 0) {
        playerStats.name = value;
    }
    else {
        // If the name is not being modified, the value must be converted to the appropriate type
        if (index == 1) {
            playerStats.HP = stoi(value);
        }
        else if (index == 2) {
            playerStats.EXP = stoi(value);
        }
        else if (index == 3) {
            playerStats.weapon = stoi(value);
        }
        else if (index == 4) {
            playerStats.armour = stoi(value);
        }
        else if (index == 5) {
            playerStats.trinket = stoi(value);
        }
    }
}

// Function to change the amount of an item in the player's inventory
// Takes a pointer to the player's item list, an item index, and an amount as parameters
// Finds the item in the list with the given index and increases or decreases its quantity by the given amount
// If the amount is negative, the item's quantity is decreased
player::itemData change_item_amount(player::itemData* items, int itemIndex, int amount) {
    items[itemIndex].num += amount;
}
