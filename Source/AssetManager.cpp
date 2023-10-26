#include <iostream>

#include <AssetManager.hpp>

AssetManager::AssetManager() {
    if(!m_font.loadFromFile("../Assets/Fonts/minecrafter/Minecrafter.Alt.ttf")) {
        std::cerr << "[ERR] Failed to load fonts" << std::endl;
        abort();
    }
}

/**
 * Add a new texture to the asset manager with given name.
 * Adding a texture with an already existing name is UB.
 *
 * @param texname Name of texture. To be used to fetch texture later.
 * @param texture Texture itself.
 * */
void AssetManager::AddTexture(const std::string& texname, const sf::Texture& texture) {
    m_textures[texname] = texture;
}

/**
 * Add a new color to the asset manager with given name.
 * Adding a color with an already existing name is UB.
 *
 * @param colname Name of color. To be used to fetch color later.
 * @param color Color itself.
 * */
void AssetManager::AddColor(const std::string& colname, const sf::Color& color) {
    m_colors[colname] = color;
}

/**
 * Return selected font from asset manager
 * @return pre loaded SFML font object.
 * */
const sf::Font& AssetManager::GetFont() {
    return m_font;
}

/**
 * Get a saved texture from asset manager.
 * Trying to fetch a texture that isn't stored in asset manager
 * will return an empty texture.
 *
 * @param texname Name of texture.
 * @return SFML texture object.
 * */
const sf::Texture& AssetManager::GetTexture(const std::string& texname) {
    return m_textures[texname];
}

/**
 * Get a saved color from asset manager.
 * Trying to fetch a color that isn't stored in asset manager
 * will return an empty color.
 *
 * @param colname Name of color.
 * @return SFML color object.
 * */
const sf::Color& AssetManager::GetColor(const std::string& colname) {
    return m_colors[colname];
}
