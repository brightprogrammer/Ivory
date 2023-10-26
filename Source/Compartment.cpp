#include <iostream>

#include <Compartment.hpp>
#include <GameConfig.hpp>

/**
 * Create a new compartment.
 * */
Compartment::Compartment() {
    sf::Image image;
    size_t sz = GameConfig::GetCompartmentSize();
    image.create(sz, sz, GameConfig::GetCompartmentColor());

    sf::Texture texture;
    if(!texture.loadFromImage(image)) {
        std::cerr << "[ERR] << Failed to create compartment texture" << std::endl;
            abort();
    }

    m_sprite.setTexture(texture);
    m_sprite.setColor(GameConfig::GetCompartmentColor());

    width = sz;
    height = sz;
}


/**
 * Draw this compartment along with it's contents.
 * */
void Compartment::DrawSelf(sf::RenderWindow& win) {
    win.draw(m_sprite);
}

bool Compartment::OnClick(const sf::Vector2i &pos) {
    /* compartments are not supposed to have children, so we won't dispatch any events */
    std::cout << "Item was clicked!!" << std::endl;
    return true;
}
