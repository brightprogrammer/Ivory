#ifndef ITEMCONFIG_H_
#define ITEMCONFIG_H_

#include "GameStaticSettings.hpp"
#include <string>
#include <vector>

enum class ItemType {
    Unknown,
    Armor,
    Weapon,
    Food,
    Craft,
    Collectible
};

enum class ItemRarity {
    Unknown,
    Common,
    Uncommon,
    Rare,
    VeryRare,
    Legendary,
    Mythical,
    Divine,
    Artifact,
    Relic,
    Transcendent
};

/**
 * Replicate the config info present in Load.conf file
 * */
struct ItemInfo {
    std::string name;
    ItemType    type;
    ItemRarity  rarity;
    std::string description;
};

/**
 * ItemConfig parses the config file for loading
 * icons and other information.
 * */
class ItemConfig {
    public:
        ItemConfig() = default;
        ItemConfig(const std::string& path) { LoadFromFile(path); }

        void LoadFromFile(const std::string& path);

        /**
         * Get number of items in the config.
         *
         * @return number of items in config.
         * */
        inline size_t GetItemCount() const { return m_items.size(); };

        /**
         * Get a random item from config.
         * Calling this when item config has no entries is BAD!
         *
         * @return const reference to a random item info.
         * */
        const ItemInfo& GetRandomItem() { return m_items[rand()%m_items.size()]; }

        const std::string& GetLoadPath() { return m_load_path; }
    private:
        std::vector<ItemInfo> m_items;
        std::string m_load_path;
};

#endif // ITEMCONFIG_H_
