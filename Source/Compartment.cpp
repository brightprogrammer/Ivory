#include <iostream>

#include <Compartment.hpp>
#include <GameConfig.hpp>
#include <Game.hpp>

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

    m_item_bg.setTexture(texture);
    m_item_bg.setColor(GameConfig::GetCompartmentColor());

    width = sz;
    height = sz;
}


/**
 * Draw this compartment along with it's contents.
 * */
void Compartment::DrawSelf(sf::RenderWindow& win) {
    win.draw(m_item_bg);
    if(m_item.GetQuantity()) m_item.DrawSelf(win);
}

/**
 * Process OnClick event for this compartment.
 *
 * @param pos Position of click
 * @param left_click Whether this was a left click or not.
 * @return true
 * */
bool Compartment::OnClick(const sf::Vector2i &pos, bool left_click) {
    /* compartments are not supposed to have children, so we won't dispatch any events */
    std::cout << "Item was clicked!!" << std::endl;
    return true;
}

void Compartment::SetItem(const ItemInfo &info) {
    if(info.name.length()) {
        m_item.LoadItem(info);
        m_item.SetPosition(m_item_bg.getPosition());
        m_item.SetQuantity(rand()%30);
    }
}
