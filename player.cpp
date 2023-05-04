#include "player.h"

player::playerData playerStats = { "", 0, 0, 0, 0 };

player::itemData playerItems[] = {
    {"Health potion", 0, "Restores 10% of the player's health."},
    {"Greater health potion", 0, "Restores 20% of the player's health."},
    {"Defense potion", 0, "Grants the player immunity to the next enemy attack."},
};

player::armouryData armourData[] = {
    {"Tattered Iron Armor", 20, "This suit of armor appears to have been through many battles, with rust and cracks covering its surface. Although it is battered and worn, it still provides some degree of protection."},
    {"Steel Plate Armor", 40, "This suit of armor is made from high-quality steel, providing stronger defense. It incorporates some heavy metal construction, allowing the wearer to be more agile in combat."},
    {"Enchanted Forge Plate Armor", 60, "This suit of armor is forged through magic, providing excellent protection as well as additional strength and speed to the wearer. It seems to emanate a mysterious energy."},
    {"Armor of the Dragon Lord", 80, "This mysterious armor is made from the body of a legendary dragon, possessing unparalleled strength and defense. The wearer can feel the power of the dragon coursing through their body while wearing it."},
};

player::armouryData weaponData[] = {
    {"Rusty Sword of Copper and Iron", 20, "The blade of this sword looks very worn, even rusty. But although it may not look like much, it can deliver devastating blows to low-level enemies."},
    {"Steel Longsword", 40, "Crafted from high-quality steel, this longsword is sharp and durable. Its power surpasses that of ordinary weapons, making it a valuable ally for any warrior."},
    {"Obsidian Battleaxe", 60, "The head of this battleaxe is made of obsidian, which looks incredibly sharp. It can easily cut through tough metal or stone, dealing massive damage."},
    {"Holy Dragon Slayer Sword", 80, "Legend has it that this sword was used by a great hero to defeat a dragon. It is a sacred weapon capable of dealing devastating blows to any dragon-type enemy."},
};

player::playerData player::modify_player_stats(int index, std::string value) {
    if (index == 0) {
        playerStats.name = value;
    }
    else {
        if (index == 1) {
            playerStats.HP = std::stoi(value);
        }
        else if (index == 2) {
            playerStats.EXP = std::stoi(value);
        }
        else if (index == 3) {
            playerStats.weapon = std::stoi(value);
        }
        else if (index == 4) {
            playerStats.armour = std::stoi(value);
        }
    }
    return playerStats;
}

player::itemData player::change_item_amount(itemData* items, int itemIndex, int amount) {
    items[itemIndex].num += amount;
    return items[itemIndex];
}

int player::get_weapon_data(int weaponIndex) {
    if (playerStats.weapon == 0) {
        return 20;
    }
    else if (playerStats.weapon == 1) {
        return 40;
    }
    else if (playerStats.weapon == 2) {
        return 60;
    }
    else if (playerStats.weapon == 3) {
        return 80;
    }
}

int player::get_armour_data(int armourIndex) {
    if (playerStats.armour == 0) {
        return 20;
    }
    else if (playerStats.armour == 1) {
        return 40;
    }
    else if (playerStats.armour == 2) {
        return 60;
    }
    else if (playerStats.armour == 3) {
        return 80;
    }
}
