#ifndef IVORY_ITEM_HPP
#define IVORY_ITEM_HPP

#include <unordered_map>

#include <SFML/Graphics.hpp>

#include <ItemLoader.hpp>

class Item {
    public:
        Item() = default;
        void LoadItem(const ItemInfo& info);

        void DrawSelf(sf::RenderWindow& win);

        inline size_t GetQuantity() { return m_count; }
        inline void SetQuantity(size_t cnt) { m_count = cnt; }

        inline const sf::Vector2f& GetPosition() { return m_item.getPosition(); }
        void SetPosition(const sf::Vector2f& pos);
    private:
        size_t m_count = 1;
        sf::Text m_count_display;
        sf::Sprite m_item;
        static inline std::unordered_map<std::string, sf::Texture> m_textures_map;
        ItemInfo m_item_info;
};

#endif // IVORY_ITEM_HPP
