#ifndef IVORY_UI_CLICKABLE_HPP
#define IVORY_UI_CLICKABLE_HPP

#include <iostream>

#include <SFML/Graphics/Rect.hpp>

#include "EventHandler.hpp"

class Clickable : public EventHandler, public sf::Rect<int> {
    public:
        Clickable(const sf::Vector2i& pos = {0, 0}, const sf::Vector2i& size = {0, 0}) :
            Rect(pos, size) {}

        virtual bool IsClicked(const sf::Vector2i& pos) {
            return contains(pos);
        }

        virtual bool OnClick(const sf::Vector2i& pos) {
            std::cout << "Clickable Clicked" << std::endl;
            return true;
        }
    private:
};

#endif // IVORY_UI_CLICKABLE_HPP
