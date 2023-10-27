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
    win.draw(m_item);
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
        sf::Texture* tex = new sf::Texture;
        if(!tex->loadFromFile(IV_ITEM_ICONS_PATH + Game::item_config.GetLoadPath() + info.name)) {
            std::cout << "[ERR] Failed to load texture \"" << info.name << "\"" << std::endl;
            return;
        }
        m_item.setTexture(*tex);
        m_item.setPosition(m_item_bg.getPosition());
    }
}
