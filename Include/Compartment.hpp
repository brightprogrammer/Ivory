#ifndef IVORY_COMPARTMENT_HPP
#define IVORY_COMPARTMENT_HPP

#include <SFML/Graphics.hpp>
#include <Ui/Clickable.hpp>

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

        /**
         * Get current position of compartment
         *
         * @return Get position of compartment.
         * */
        inline const sf::Vector2f& GetPosition() { return m_sprite.getPosition(); }

        /**
         * Set a new position for current compartment.
         * @param pos New position of compartment
         * */
        inline void SetPosition(const sf::Vector2f& pos) {
            /* set position of button */
            left = pos.x;
            top = pos.y;

            m_sprite.setPosition(pos);
        }
    private:
        sf::Sprite m_sprite; /* All compartments have a different sprite. */
};

#endif // IVORY_COMPARTMENT_HPP
