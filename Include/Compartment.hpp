#ifndef IVORY_COMPARTMENT_HPP
#define IVORY_COMPARTMENT_HPP

#include "GameConfig.hpp"
#include <SFML/Graphics.hpp>

#include <Ui/Clickable.hpp>
#include <ItemLoader.hpp>
#include <Item.hpp>

/**
 * Compartments are where our objects will be placed.
 * A container contains many compartments.
 * In the assignment image, the inventory and equipped boxes
 * are two containers, and each box in them is a compartment.
 * */
class Compartment : public Clickable {
    public:
        Compartment();

        void DrawSelf(sf::RenderWindow& win);
        virtual bool OnClick(const sf::Vector2i& pos) override;
        void SetItem(const ItemInfo& info);

        /**
         * Get current position of compartment
         *
         * @return Get position of compartment.
         * */
        inline const sf::Vector2f& GetPosition() { return m_item_bg.getPosition(); }

        /**
         * Set a new position for current compartment.
         * @param pos New position of compartment
         * */
        inline void SetPosition(const sf::Vector2f& pos) {
            /* set position of button */
            left = pos.x;
            top = pos.y;

            m_item_bg.setPosition(pos);
            m_item.SetPosition(pos);
        }

        inline bool IsSelected() { return m_is_selected; }
        void ResetSelection() {
            m_is_selected = false;
            m_item_bg.setColor(GameConfig::GetCompartmentColor());
        }

        inline bool IsEmpty() { return m_item.IsEmpty(); }
        inline ItemType GetItemType() { return m_item.GetItemType(); }

        Item& GetItem() { return m_item; }
    private:
        bool m_is_selected = false;
        sf::Sprite m_item_bg; /* All compartments have a different sprite. */
        Item m_item;
};

#endif // IVORY_COMPARTMENT_HPP
