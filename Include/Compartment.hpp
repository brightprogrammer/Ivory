#ifndef IVORY_COMPARTMENT_HPP
#define IVORY_COMPARTMENT_HPP

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
        virtual bool OnClick(const sf::Vector2i& pos, bool left_click) override;
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
    private:
        sf::Sprite m_item_bg; /* All compartments have a different sprite. */
        Item m_item;
};

#endif // IVORY_COMPARTMENT_HPP
