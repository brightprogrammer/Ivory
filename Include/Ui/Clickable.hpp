#ifndef IVORY_UI_CLICKABLE_HPP
#define IVORY_UI_CLICKABLE_HPP

#include <iostream>

#include <SFML/Graphics/Rect.hpp>

#include "EventHandler.hpp"

/**
 * A clickable is anything, that can be clicked. One needs to set
 * the properties @c left, @c top, @c width, and @c height, in order
 * to be able to use it.
 * */
class Clickable : public EventHandler, public sf::Rect<int> {
    public:
        Clickable(const sf::Vector2i& pos = {0, 0}, const sf::Vector2i& size = {0, 0}) :
            Rect(pos, size) {}

        /**
         * Check whether the clickable was clicked.
         *
         * @param pos position of click.
         * @return true if position lies inside the clickable, false otherwise.
         * */
        virtual bool IsClicked(const sf::Vector2i& pos) {
            return contains(pos);
        }
    private:
};

#endif // IVORY_UI_CLICKABLE_HPP
