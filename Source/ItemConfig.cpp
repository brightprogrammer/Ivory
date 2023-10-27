#include <fstream>
#include <iostream>

#include <ItemConfig.hpp>

std::string ExtractValue(const std::string& key, const std::string& line);
ItemType GetItemTypeFromString(const std::string& typestr);
ItemRarity GetItemRarityFromSTring(const std::string& typestr);

/**
 * Parse and load item config.
 * */
void ItemConfig::LoadFromFile(const std::string& path) {
    std::cout << "Loading Item Config from " << path << std::endl;

    std::fstream file(path, std::ios::in);
    if(!file.is_open()) {
        std::cerr << "Failed to parse Item Config (file does not exist)\n" << std::endl;
        exit(1);
    }

    static std::string
        ITEMSTART   = "ITEMSTART",
        ITEMEND     = "ITEMEND",
        LOADPATH    = "LOADPATH=",
        NAME        = "NAME=",
        TYPE        = "TYPE=",
        RARITY      = "RARITY=",
        DESCRIPTION = "DESCRIPTION=";

    auto LINE_END = std::string::npos;

    std::string line;
    size_t lineno = 1;
    bool parsing_item = false;
    ItemInfo item;
    while(std::getline(file, line)) {
        /* skip if this is a comment */
        if(line[0] == '#') {
            continue;
        }

        if(line.find(ITEMSTART) != LINE_END) {
            if(parsing_item) {
                std::cerr << "[ERR] " << lineno << " Invalid Item Config file (ITEMSTART not closed with ITEMEND)" << std::endl;
                return;
            } else parsing_item = true;
        } else if(line.find(ITEMEND) != LINE_END) {
            if(!parsing_item) {
                std::cerr << "[ERR] " << lineno << " Invalid Item Config file (ITEMEND before ITEMSTART!)" << std::endl;
                return;
            }
            parsing_item = false;
            m_items.push_back(item);
        } else if(line.find(LOADPATH) != LINE_END) {
            if(parsing_item) {
                std::cerr << "[ERR] " << lineno << " Invalid Item Config file (Cannot have LOADPATH when parsing an item)" << std::endl;
                return;
            }
            m_load_path = ExtractValue(LOADPATH, line);
        } else if(line.find(NAME) != LINE_END) {
            item.name = ExtractValue(NAME, line);
        } else if(line.find(TYPE) != LINE_END) {
            item.type = GetItemTypeFromString(ExtractValue(TYPE, line));
        } else if(line.find(RARITY) != LINE_END) {
            item.rarity = GetItemRarityFromSTring(ExtractValue(RARITY, line));
        } else if(line.find(DESCRIPTION) != LINE_END) {
            item.description = ExtractValue(DESCRIPTION, line);
        }
        lineno++;
    }
}

/**
 * Extract value from a KEY="VALUE" pair in a given line.
 *
 * @param key
 * @param line containing key and value
 * @return value
 * */
std::string ExtractValue(const std::string& key, const std::string& line) {
    size_t pos = line.find(key);
    size_t off = key.length() + 1; /* +1 for the opening " character */
    size_t len = line.length() - (off + pos) - 1;
    return line.substr(pos + off, len);
}

/**
 * Convert item type string to ItemType enum.
 * */
ItemType GetItemTypeFromString(const std::string& typestr) {
    static std::string
        Armor       = "Armor",
        Weapon      = "Weapon",
        Food        = "Food",
        Craft       = "Craft",
        Collectible = "Collectible";

#define ITEM_TYPE_CHECK(type) if(typestr == type) return ItemType::type;
    ITEM_TYPE_CHECK(Armor)
    else ITEM_TYPE_CHECK(Weapon)
    else ITEM_TYPE_CHECK(Food)
    else ITEM_TYPE_CHECK(Craft)
    else ITEM_TYPE_CHECK(Collectible)
    else return ItemType::Unknown;
#undef ITEM_TYPE_CHECK
}

/**
 * Convert item rarity string to ItemRarity
 * */
ItemRarity GetItemRarityFromSTring(const std::string& typestr) {
    static std::string
        Common       = "Common",
        Uncommon     = "Uncommon",
        Rare         = "Rare",
        VeryRare     = "VeryRare",
        Legendary    = "Legendary",
        Mythical     = "Mythical",
        Divine       = "Divine",
        Artifact     = "Artifact",
        Relic        = "Relic",
        Transcendent = "Transcendent";

#define ITEM_RARITY_CHECK(type) if(typestr == type) return ItemRarity::type;
    ITEM_RARITY_CHECK(Common)
    else ITEM_RARITY_CHECK(Uncommon)
    else ITEM_RARITY_CHECK(Rare)
    else ITEM_RARITY_CHECK(VeryRare)
    else ITEM_RARITY_CHECK(Legendary)
    else ITEM_RARITY_CHECK(Mythical)
    else ITEM_RARITY_CHECK(Divine)
    else ITEM_RARITY_CHECK(Artifact)
    else ITEM_RARITY_CHECK(Relic)
    else ITEM_RARITY_CHECK(Transcendent)
    else return ItemRarity::Unknown;
#undef ITEM_TYPE_CHECK
}
