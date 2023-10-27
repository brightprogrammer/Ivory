#include <Item.hpp>
#include <Game.hpp>
#include <GameConfig.hpp>

/**
 * Load item from a config
 *
 * @param info
 * @param count
 * */
void Item::LoadItem(const ItemInfo& info) {
    m_item_info = info;

    if(!m_textures_map.count(info.name)) {
        sf::Texture tex;
        std::string img_path = IV_ITEM_ICONS_PATH + Game::item_loader.GetLoadPath() + info.name;
        tex.loadFromFile(img_path);
        m_textures_map[info.name] = tex;
    }

    // load texture
    m_item.setTexture(m_textures_map[info.name]);

    // set font and text
    m_count_display.setFont(GameConfig::GetFont());
    m_count_display.setCharacterSize(GameConfig::GetTitleCharacterSize()/2); // TODO:
    m_count_display.setString(std::to_string(m_count));

    // set position
    const auto& lb1 = m_item.getLocalBounds();
    const auto& lb2 = m_count_display.getLocalBounds();
    m_count_display.setPosition(lb1.width - lb2.width/2.f, lb1.height - lb2.height/2.f);

    m_count = 1;
}

/**
 * Draw this item to screen.
 * */
void Item::DrawSelf(sf::RenderWindow& win) {
    if(m_count) {
        win.draw(m_item);
        m_count_display.setString(std::to_string(m_count));
        win.draw(m_count_display);
    }
}

/**
 * Set a new position.
 * */
void Item::SetPosition(const sf::Vector2f &pos) {
    m_item.setPosition(pos);

    const auto& lb1 = m_item.getLocalBounds();
    const auto& lb2 = m_count_display.getLocalBounds();
    m_count_display.setPosition(pos.x + lb1.width - lb2.width/2.f, pos.y + lb1.height - lb2.height/2.f);
}
